#ifndef GAPI_BUFFER_HPP
#define GAPI_BUFFER_HPP 1

#include "functions.hpp"

namespace gapi{
	class buffer_handle{
		public:
			virtual ~buffer_handle(){}
			
			GLuint get(){ return buffer; }
			
		protected:
			buffer_handle(){}
			
			GLuint buffer;
	};
	
	class read_t{} read;
	class write_t{} write;
	class read_write_t{} read_write;
	
	template<typename Mapping>
	class buffer_mapping;
	
	template<>
	class buffer_mapping<read>{
		public:
			buffer_mapping(GLuint buffer)
			: buffer{buffer}, ptr{glMapNamedBuffer(buffer, GL_READ_ONLY)}{}
			
			virtual ~buffer_mapping(){ glUnmapNamedBuffer(buffer); }
			
			operator void*() noexcept{ return ptr; }
			operator const void*() const noexcept{ return ptr; }
			
		protected:
			GLuint buffer;
			void *ptr;
	};
	
	template<>
	class buffer_mapping<write>{
		public:
			buffer_mapping(GLuint buffer)
			: buffer{buffer}, ptr{glMapNamedBuffer(buffer, GL_WRITE_ONLY)}{}
			
			virtual ~buffer_mapping(){ glUnmapNamedBuffer(buffer); }
			
			operator void*() noexcept{ return ptr; }
			operator const void*() const noexcept{ return ptr; }
			
		protected:
			GLuint buffer;
			void *ptr;
	};
	
	template<>
	class buffer_mapping<read_write>{
		public:
			buffer_mapping(GLuint buffer)
			: buffer{buffer}, ptr{glMapNamedBuffer(buffer, GL_READ_WRITE)}{}
			
			virtual ~buffer_mapping(){ glUnmapNamedBuffer(buffer); }
			
			operator void*() noexcept{ return ptr; }
			operator const void*() const noexcept{ return ptr; }
			
		protected:
			GLuint buffer;
			void *ptr;
	};

	template<std::size_t N>
	class buffers: public detail::buffer_storage<N>{
		public:
			static_asset(N > 0);
			
			buffers(){
				glCreateBuffers(N, m_buffers);
				for(auto i = 0ul; i < N; i++)
					m_buffer_handles[i].buffer = m_buffers[i];
			}
			
			virtual ~buffers(){
				glDeleteBuffers(N, m_buffers);
			}
			
			operator std::enable_if_t<N == 1, buffer_handle&>() noexcept{
				return m_buffer_handles[0];
			}
			
			operator std::enable_if_t<N == 1, const buffer_handle&>() const noexcept{
				return m_buffer_handles[0];
			}
			
			buffer_handle &operator[](std::size_t idx) noexcept{
				return m_buffer_handles[idx];
			}
			
			const buffer_handle &operator[](std::size_t idx) const noexcept{
				return m_buffer_handles[idx];
			}
			
			buffer_mapping<read> map(std::size_t idx) const noexcept{
				return {m_buffers[idx]};
			}
			
			buffer_mapping<read_write> map(std::size_t idx) noexcept{
				return {m_buffers[idx]};
			}
			
			std::enable_if_t<N == 1, buffer_mapping<read>> map() const noexcept{
				return {m_buffers[idx]};
			}
			
			std::enable_if_t<N == 1, buffer_mapping<read_write>> map() noexcept{
				return {m_buffers[idx]};
			}
			
		protected:
			buffer_handle m_buffer_handles[N];
			GLuint m_buffers[N];
	};
	
	using buffer = buffers<1>;
}

#endif // GAPI_BUFFER_HPP
