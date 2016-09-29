#ifndef GAPI_VERTEX_ARRAY_HPP
#define GAPI_VERTEX_ARRAY_HPP 1

#include <cstddef>
#include <type_traits>

#include "object.hpp"
#include "functions.hpp"
#include "buffer.hpp"

namespace gapi{
	class vertex_array_handle: public object{
		public:
			void set_vertex_buffer(const buffer_handle &buff, GLuint binding, GLintptr offset, GLsizei stride){
				functions::glVertexArrayVertexBuffer(handle, binding, buff.get(), offset, stride);
			}

			void set_element_buffer(const buffer_handle &buff){
				functions::glVertexArrayElementBuffer(handle, buff.get());
			}

			void enable_attrib(GLuint index) noexcept{
				functions::glEnableVertexArrayAttrib(handle, index);
			}

			void disable_attrib(GLuint index){
				functions::glDisableVertexArrayAttrib(handle, index);
			}

			void attrib_format(GLuint index, std::uint16_t size, GLenum type, GLboolean normalized, GLuint reloffset){
				functions::glVertexArrayAttribFormat(handle, index, size, type, normalized, reloffset);
			}

			void attrib_binding(GLuint attrib, GLuint binding){
				functions::glVertexArrayAttribBinding(handle, attrib, binding);
			}

			void use(){
				functions::glBindVertexArray(handle);
			}
			
		protected:
			vertex_array_handle() = default;
			
			template<std::size_t>
			friend class vertex_arrays;
			
			template<typename T>
			friend GLuint get_handle(const T&);
	};

	class vertex_arrays_base: public object{
		public:
			virtual ~vertex_arrays_base() = default;

			virtual std::size_t size() const noexcept = 0;

			virtual vertex_array_handle &operator [](std::size_t idx) noexcept = 0;
			virtual const vertex_array_handle &operator [](std::size_t idx) const noexcept = 0;
	};

	template<std::size_t N>
	class vertex_arrays: public vertex_arrays_base{
		public:
			vertex_arrays(){
				functions::glCreateVertexArrays(N, m_arrays);
				for(auto i = 0ul; i < N; i++)
					m_handles[i].handle = m_arrays[i];
			}
			
			virtual ~vertex_arrays(){
				functions::glDeleteVertexArrays(N, m_arrays);
			}

			std::size_t size() const noexcept{ return N; }

			template<typename T = vertex_array_handle&>
			explicit operator std::enable_if_t<N == 1, T>() noexcept{ return m_handles[0]; }

			template<typename T = vertex_array_handle&>
			explicit operator std::enable_if_t<N == 1, const T>() const noexcept{ return m_handles[0]; }

			vertex_array_handle &operator [](std::size_t idx) noexcept{ return m_handles[idx]; }
			const vertex_array_handle &operator [](std::size_t idx) const noexcept{ return m_handles[idx]; }

		protected:
			vertex_array_handle m_handles[N];
			GLuint m_arrays[N];
	};

	using vertex_array = vertex_arrays<1>;
}

#endif // GAPI_VERTEX_ARRAY_HPP

