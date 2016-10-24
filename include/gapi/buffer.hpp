#ifndef GAPI_BUFFER_HPP
#define GAPI_BUFFER_HPP 1

#include <cmath>
#include <limits>
#include <array>
#include <system_error>
#include <type_traits>

#include "object.hpp"
#include "constants.hpp"
#include "functions.hpp"

namespace gapi{
	//! buffer mapping error category for std::system_error
	class buffer_mapping_category: public std::error_category{
		public:
			buffer_mapping_category(){}

			virtual const char *name() const noexcept{ return "opengl|gapi-buffer-mapping"; }

			virtual std::string message(int condition) const{
				switch(condition){
					// these should make sense
					case GL_INVALID_ENUM:
						return "[GL_INVALID_ENUM] target is not a valid buffer binding target";
					case GL_INVALID_OPERATION:
						return "[GL_INVALID_OPERATION] buffer is not the name of an existing buffer object";
					case GL_INVALID_VALUE:
						return "[GL_INVALID_VALUE] check offset, length and access";

					default:
						return "[UNKNOWN_ERROR] fuck knows haye";
				}
			}
	};

	//! buffer category for std::system_error
	class buffer_category: public std::error_category{
		public:
			buffer_category(){}

			virtual const char *name() const noexcept{ return "opengl|gapi-buffer"; }

			virtual std::string message(int condition) const{
				switch(condition){
					case GL_INVALID_ENUM:
						return "[GL_INVALID_ENUM] target is not one of the accepted buffer targets";
					case GL_INVALID_OPERATION:
						return "[GL_INVALID_OPERATION] buffer is not the name of an existing buffer object";
					case GL_INVALID_VALUE:
						return "[GL_INVALID_VALUE] check offsets and sizes, make sure sizes don't overflow 32-bit signed int";
				
					default:
						return "[UNKNOWN_ERROR] sheeeiit, i dunno";
				}
			}
	};

	//! @cond
	namespace detail{
		static inline void *map_named_buffer(GLuint handle, std::size_t size, GLbitfield flags){
			auto ret = functions::glMapNamedBufferRange(
				handle,
				0, static_cast<GLsizeiptr>(size),
				flags | GL_MAP_COHERENT_BIT | GL_MAP_PERSISTENT_BIT
			);
			if(!ret){
				buffer_mapping_category buffer_mapping_category_inst;
				throw std::system_error(functions::glGetError(), buffer_mapping_category_inst);
			}
			return ret;
		}
	}
	//! @endcond

	//! Tags for function selection
	class Read;
	class Write;
	class ReadWrite;
	
	/** class template for buffer mapping
	 * 
	 *  @tparam T tag to specify read/write access
	 **/
	template<typename T>
	class buffer_mapping;
	
	//! generic handle to a buffer of any kind
	class buffer_handle: public object{
		public:
			virtual ~buffer_handle(){}
			
			//! map the buffer with read/write access
			buffer_mapping<ReadWrite> map() noexcept;
			
			//! map the buffer with only read access
			buffer_mapping<Read> map() const noexcept;
			
			//! buffer size in bytes
			std::size_t size() const noexcept{ return m_size; }
			
			/**
			 * set the buffer data
			 * 
			 * @param[in] off offset into the buffer in bytes that the write will be done
			 * @param[in] data pointer to the bytes to be copied into the buffer
			 * @param[in] size the number of bytes \p data points to
			 * 
			 * @returns the number of bytes that were actually copied
			 **/
			[[maybe_unused]]
			std::size_t set_sub_data(std::size_t off, const void *data, std::size_t size){
				size = std::min((std::size_t)std::numeric_limits<std::ptrdiff_t>::max(), size);

				std::ptrdiff_t to_copy = (m_size - off);
				to_copy = std::min(static_cast<std::size_t>(to_copy), size);

				#ifndef NDEBUG
				if(to_copy < 0)
					throw std::logic_error{"offset too large for buffer requested"};
				#endif

				functions::glNamedBufferSubData(handle, off, size, data);
				
				#ifndef NDEBUG
				auto err = functions::glGetError();
				if(err != GL_NO_ERROR){
					buffer_category buffer_category_inst;
					throw std::system_error{static_cast<int>(err), buffer_category_inst};
				}
				#endif

				return to_copy;
			}
			
			/**
			 * get the buffer data
			 * 
			 * @param[in] off offset into the buffer the bytes will be retrieved from
			 * @param[out] buff pointer to the bytes that the buffer will be copied into
			 * @param[in] max the maximum number of bytes that will be written into \p buff
			 * 
			 * @returns the number of bytes actually retrieved
			 **/
			[[maybe_unused]]
			std::size_t get_sub_data(std::size_t off, void *buff, std::size_t max){
				max = std::min((std::size_t)std::numeric_limits<std::ptrdiff_t>::max(), max);

				std::ptrdiff_t to_copy = (m_size - off);
				to_copy = std::min(static_cast<std::size_t>(to_copy), max);

				#ifndef NDEBUG
				if(to_copy < 0)
					throw std::logic_error{"offset too large for buffer requested"};
				#endif
				
				functions::glGetNamedBufferSubData(handle, off, to_copy, buff);
				
				#ifndef NDEBUG
				auto err = functions::glGetError();
				if(err != GL_NO_ERROR){
					buffer_category buffer_category_inst;
					throw std::system_error{static_cast<int>(err), buffer_category_inst};
				}
				#endif

				return to_copy;
			}
			
		protected:
			std::size_t m_size;
			buffer_handle(){}

			template<std::size_t>
			friend class buffers;
	};
	
	//! represents a buffer mapping with only read access
	template<>
	class buffer_mapping<Read>: public object{
		public:
			/**
			 * create a mapping to the given buffer
			 * 
			 * @param[in] buff the buffer to map
			 **/
			buffer_mapping(const buffer_handle &buff){
				handle = buff.get();
				m_size = buff.size();
				ptr = detail::map_named_buffer(handle, m_size, GL_MAP_READ_BIT);
			}
			
			virtual ~buffer_mapping(){ functions::glUnmapNamedBuffer(handle); }
			
			//! @returns size in bytes of the mapped buffer
			std::size_t size() const noexcept{ return m_size; }
			
			//! explicit conversion to a pointer to the mapped data
			explicit operator const void*() const noexcept{ return ptr; }
			
			//! @returns pointer to the mapped bytes
			const void *data() const noexcept{ return ptr; }
			
		protected:
			std::size_t m_size;
			const void *ptr;
	};
	
	//! represents a buffer mapping with only write access
	template<>
	class buffer_mapping<Write>: public object{
		public:
			//! @param[in] buff the buffer to be mapped
			buffer_mapping(buffer_handle &buff){
				handle = buff.get();
				m_size = buff.size();
				ptr = detail::map_named_buffer(handle, m_size, GL_MAP_WRITE_BIT);
			}
			
			virtual ~buffer_mapping(){ functions::glUnmapNamedBuffer(handle); }
			
			/**
			 * explicit conversion to a pointer to the mapped buffer bytes.
			 * @warning this pointer must only be written to. it is undefined what happens when this pointer is read.
			 **/
			explicit operator void*() noexcept{ return ptr; }
			
			//! @returns size in bytes of the mapped buffer
			std::size_t size() const noexcept{ return m_size; }
			
			/**
			 * @warning this pointer must only be written to. it is undefined what happens when this pointer is read.
			 * 
			 * @returns pointer to the bytes of the mapped buffer
			 **/
			void *data() noexcept{ return ptr; }
			
		protected:
			std::size_t m_size;
			void *ptr;
	};
	
	//! represents a buffer mapping with read and write access
	template<>
	class buffer_mapping<ReadWrite>: public object{
		public:
			/**
			 * create a mapping to the given buffer
			 * 
			 * @param[in] buff the buffer to map
			 **/
			buffer_mapping(buffer_handle &buff){
				handle = buff.get();
				m_size = buff.size();
				ptr = detail::map_named_buffer(handle, m_size, GL_MAP_READ_BIT | GL_MAP_WRITE_BIT);
			}
			
			virtual ~buffer_mapping(){ functions::glUnmapNamedBuffer(handle); }

			//! conversion for writing
			explicit operator void*() noexcept{ return ptr; }
			
			//! conversion for reading
			explicit operator const void*() const noexcept{ return ptr; }
			
			//! @returns the size in bytes of the mapped buffer
			std::size_t size() const noexcept{ return m_size; }
			
			//! @returns pointer to the data
			void *data() noexcept{ return ptr; }
			
			//! @returns pointer to the data
			const void *data() const noexcept{ return ptr; }
			
		protected:
			void *ptr;
			std::size_t m_size;
	};
	
	inline buffer_mapping<ReadWrite> buffer_handle::map() noexcept{ return {*this}; }
			
	inline buffer_mapping<Read> buffer_handle::map() const noexcept{ return {*this}; }
	
	//! base class for buffers array wrapper
	class buffers_base: public object{
		public:
			virtual ~buffers_base() = default;

			virtual const buffer_handle &operator [](std::size_t) const noexcept = 0;
			virtual buffer_handle &operator [](std::size_t) noexcept = 0;
	};
	
	//! mutable buffers
	template<std::size_t N>
	class mutable_buffers{
		public:
	};

	//! wrapper for an array of buffers
	template<std::size_t N>
	class buffers: public buffers_base{
		public:
			static_assert((N > 0) && (N < std::numeric_limits<std::int32_t>::max()), "");
			
			buffers(const std::array<std::size_t, N> &sizes){
				functions::glCreateBuffers(N, m_buffers);
				for(auto i = 0ul; i < N; i++){
					functions::glNamedBufferStorage(
						m_buffers[i],
						sizes[i], nullptr,
						GL_DYNAMIC_STORAGE_BIT | GL_MAP_READ_BIT |
						GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT |
						GL_MAP_COHERENT_BIT 
					);
					m_buffer_handles[i].handle = m_buffers[i];
					m_buffer_handles[i].m_size = sizes[i];
				}
			}
			
			virtual ~buffers(){
				functions::glDeleteBuffers(N, m_buffers);
			}
			
			//! implicit conversion to buffer_handle& when the class wraps an array with 1 element
			template<typename T = buffer_handle&>
			operator std::enable_if_t<N==1, T>() noexcept{
				return m_buffer_handles[0];
			}
			
			//! implicit conversion to const buffer_handle& when the class wraps an array with 1 element
			template<typename T = const buffer_handle&>
			operator std::enable_if_t<N==1, T>() const noexcept{
				return m_buffer_handles[0];
			}
			
			/**
			 * get element of wrapped buffer array
			 * 
			 * @param[in] idx index of the array element to get
			 * 
			 * @returns reference to buffer_handle
			 **/
			buffer_handle &operator[](std::size_t idx) noexcept{
				return m_buffer_handles[idx];
			}
			
			/**
			 * get element of wrapped buffer array
			 * 
			 * @param[in] idx index of the array element to get
			 * 
			 * @returns constant reference to buffer_handle
			 **/
			const buffer_handle &operator[](std::size_t idx) const noexcept{
				return m_buffer_handles[idx];
			}
			
			/**
			 * map an element of the array
			 * 
			 * @param[in] idx index of the buffer to map
			 * 
			 * @returns buffer mapping
			 **/
			buffer_mapping<Read> map(std::size_t idx) const noexcept{
				return {m_buffer_handles[idx]};
			}
			
			/**
			 * map an element of the array
			 * 
			 * @param[in] idx index of the buffer to map
			 * 
			 * @returns buffer mapping
			 **/
			buffer_mapping<ReadWrite> map(std::size_t idx) noexcept{
				return {m_buffer_handles[idx]};
			}
			
			/**
			 * map the buffer contained in the array
			 * only available when the array contains a single element
			 * 
			 * @returns buffer mapping
			 **/
			template<typename T = buffer_mapping<Read>>
			std::enable_if_t<N == 1, T> map() const noexcept{
				return {m_buffer_handles[0]};
			}
			
			/**
			 * map the buffer contained in the array
			 * only available when the array contains a single element
			 * 
			 * @returns buffer mapping
			 **/
			template<typename T = buffer_mapping<ReadWrite>>
			std::enable_if_t<N == 1, T> map() noexcept{
				return {m_buffer_handles[0]};
			}
			
		protected:
			buffer_handle m_buffer_handles[N];
			GLuint m_buffers[N];
	};
	
	//! convienience type alias to represent a single buffer
	using buffer = buffers<1>;
}

#endif // GAPI_BUFFER_HPP
