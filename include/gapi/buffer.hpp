#ifndef GAPI_BUFFER_HPP
#define GAPI_BUFFER_HPP 1

#include <system_error>
#include <cmath>
#include <limits>
#include <array>

#include "object.hpp"
#include "constants.hpp"
#include "functions.hpp"

namespace gapi{
	class buffer_mapping_category: public std::error_category{
		public:
			constexpr buffer_mapping_category(){}

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

	class buffer_category: public std::error_category{
		public:
			constexpr buffer_category(){}

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

	class Read;
	class Write;
	class ReadWrite;
	
	template<typename T>
	class buffer_mapping;
	
	class buffer_handle: public object{
		public:
			virtual ~buffer_handle(){}
			
			buffer_mapping<ReadWrite> map() noexcept;
			buffer_mapping<Read> map() const noexcept;
			
			std::size_t size() const noexcept{ return m_size; }
			
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
			
			[[maybe_unused]]
			std::size_t get_sub_data(std::size_t off, void *buff, std::size_t max){
				max = std::min((std::size_t)std::numeric_limits<std::ptrdiff_t>::max(), max);

				std::ptrdiff_t to_copy = (m_size - off);
				to_copy = std::min(static_cast<std::size_t>(to_copy), max);

				#ifndef NDEBUG
				if(to_copy < 0)
					throw std::logic_error{"offset too large for buffer requested"};
				#endif
				
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
	
	template<>
	class buffer_mapping<Read>: public object{
		public:
			buffer_mapping(const buffer_handle &buff){
				handle = buff.get();
				m_size = buff.size();
				ptr = detail::map_named_buffer(handle, m_size, GL_MAP_READ_BIT);
			}
			
			virtual ~buffer_mapping(){ functions::glUnmapNamedBuffer(handle); }
			
			std::size_t size() const noexcept{ return m_size; }
			
			explicit operator const void*() const noexcept{ return ptr; }
			
			const void *data() const noexcept{ return ptr; }
			
		protected:
			std::size_t m_size;
			const void *ptr;
	};
	
	template<>
	class buffer_mapping<Write>: public object{
		public:
			buffer_mapping(buffer_handle &buff){
				handle = buff.get();
				m_size = buff.size();
				ptr = detail::map_named_buffer(handle, m_size, GL_MAP_WRITE_BIT);
			}
			
			virtual ~buffer_mapping(){ functions::glUnmapNamedBuffer(handle); }
			
			explicit operator void*() noexcept{ return ptr; }
			
			std::size_t size() const noexcept{ return m_size; }
			
			void *data() noexcept{ return ptr; }
			
		protected:
			std::size_t m_size;
			void *ptr;
	};
	
	template<>
	class buffer_mapping<ReadWrite>: public object{
		public:
			buffer_mapping(buffer_handle &buff){
				handle = buff.get();
				m_size = buff.size();
				ptr = detail::map_named_buffer(handle, m_size, GL_MAP_READ_BIT | GL_MAP_WRITE_BIT);
			}
			
			virtual ~buffer_mapping(){ functions::glUnmapNamedBuffer(handle); }
			
			explicit operator void*() noexcept{ return ptr; }
			explicit operator const void*() const noexcept{ return ptr; }
			
			std::size_t size() const noexcept{ return m_size; }
			
			void *data() noexcept{ return ptr; }
			const void *data() const noexcept{ return ptr; }
			
		protected:
			void *ptr;
			std::size_t m_size;
	};
	
	inline buffer_mapping<ReadWrite> buffer_handle::map() noexcept{ return {*this}; }
			
	inline buffer_mapping<Read> buffer_handle::map() const noexcept{ return {*this}; }
	
	namespace detail{
	}
	
	template<std::size_t N>
	class mutable_buffers{
		public:
	};

	class buffers_base{
		public:
			virtual ~buffers_base() = default;

			virtual const buffer_handle &operator [](std::size_t) const noexcept = 0;
			virtual buffer_handle &operator [](std::size_t) noexcept = 0;
	};

	template<std::size_t N>
	class buffers{
		public:
			static_assert((N > 0) && (N < std::numeric_limits<std::int32_t>::max()));
			
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
			
			template<typename T = buffer_handle&>
			operator std::enable_if_t<N==1, T>() noexcept{
				return m_buffer_handles[0];
			}
			
			template<typename T = const buffer_handle&>
			operator std::enable_if_t<N==1, T>() const noexcept{
				return m_buffer_handles[0];
			}
			
			buffer_handle &operator[](std::size_t idx) noexcept{
				return m_buffer_handles[idx];
			}
			
			const buffer_handle &operator[](std::size_t idx) const noexcept{
				return m_buffer_handles[idx];
			}
			
			buffer_mapping<Read> map(std::size_t idx) const noexcept{
				return {m_buffer_handles[idx]};
			}
			
			buffer_mapping<ReadWrite> map(std::size_t idx) noexcept{
				return {m_buffer_handles[idx]};
			}
			
			template<typename T = buffer_mapping<Read>>
			std::enable_if_t<N == 1, T> map() const noexcept{
				return {m_buffer_handles[0]};
			}
			
			template<typename T = buffer_mapping<ReadWrite>>
			std::enable_if_t<N == 1, T> map() noexcept{
				return {m_buffer_handles[0]};
			}
			
		protected:
			buffer_handle m_buffer_handles[N];
			GLuint m_buffers[N];
	};
	
	using buffer = buffers<1>;
}

#endif // GAPI_BUFFER_HPP
