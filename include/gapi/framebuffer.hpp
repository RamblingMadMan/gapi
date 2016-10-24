#ifndef GAPI_FRAMEBUFFER_HPP
#define GAPI_FRAMEBUFFER_HPP 1

#include <cstddef>
#include <system_error>

#include "types.hpp"
#include "constants.hpp"
#include "functions.hpp"
#include "texture.hpp"
#include "utility.hpp"

namespace gapi{
	//! framebuffer draw buffers category for std::system_error
	class framebuffer_draw_buffers_category: public std::error_category{
		public:
			framebuffer_draw_buffers_category() = default;

			virtual const char *name() const noexcept{ return "opengl|gapi-framebuffer-drawbuffers"; }

			virtual std::string message(int condition) const{
				switch(condition){
					// these should make sense
					case GL_INVALID_OPERATION:
						return "[GL_INVALID_OPERATION] check passed buffers";
					case GL_INVALID_ENUM:
						return "[GL_INVALID_ENUM] check function arguments";
					case GL_INVALID_VALUE:
						return "[GL_INVALID_VALUE] n > GL_MAX_DRAW_BUFFERS";

					default:
						return "[UNKNOWN_ERROR] you'd like to know, wouldn't you?";
				}
			}
	};

	//! represents whether a framebuffer is used for reading or writing
	enum class framebuffer_type: GLenum{
		write = GL_DRAW_FRAMEBUFFER, read = GL_READ_FRAMEBUFFER,
		readwrite = GL_FRAMEBUFFER
	};

	//! represents a single framebuffer object
	class framebuffer_handle: public object{
		public:
			/**
			 * attach a texture to the framebuffer
			 * 
			 * @param[in] attachment the attachment to attach the texture to
			 * @param[in] tex the texture to be attached
			 * @param[in] level the texture level to be attached
			 **/
			void attach_texture(GLenum attachment, const texture_handle &tex, GLint level = 0){
				functions::glNamedFramebufferTexture(handle, attachment, tex.get_handle(), level);
			}

			/**
			 * use the function for reading and/or writing
			 * 
			 * @param[in] type the type of use the buffer will have
			 **/
			void use(framebuffer_type type) noexcept{
				functions::glBindFramebuffer(
					static_cast<GLenum>(type),
					handle
				);
			}

			/**
			 * sets the draw buffer the frambuffer will use
			 * 
			 * @param[in]  buffer the draw buffer
			 **/
			void draw_buffer(GLenum buffer){ functions::glNamedFramebufferDrawBuffer(handle, buffer); }

			/**
			 * sets the draw buffers the framebuffer will use
			 * 
			 * @param[in] head the first draw buffer
			 * @param[in] second the second draw buffer
			 * @param[in] tail the rest of the draw buffers
			 **/
			template<typename ... Tail>
			void draw_buffers(GLenum head, GLenum second, Tail ... tail){
				std::vector<GLenum> bufs{head, second, static_cast<GLenum>(tail)...};
				functions::glNamedFramebufferDrawBuffers(handle, bufs.size(), bufs.data());
				GLenum err = functions::glGetError();
				if(err != GL_NO_ERROR){
					framebuffer_draw_buffers_category cat;
					throw std::system_error{static_cast<int>(err), cat};
				}
			}

		protected:
			template<std::size_t>
			friend class framebuffers;
	};

	//! base class for framebuffer array wrapper
	class framebuffers_base{
		public:
			virtual std::size_t size() const noexcept = 0;

			virtual const framebuffer_handle &operator [](std::size_t) const noexcept = 0;
			virtual framebuffer_handle &operator [](std::size_t) noexcept = 0;
	};

	/**
	 * wrapper for an array of framebuffers
	 * 
	 * @tparam N the number of framebuffers to store
	 **/
	template<std::size_t N>
	class framebuffers: public framebuffers_base{
		public:
			framebuffers(){
				functions::glCreateFramebuffers(N, handles);
				
				for(auto i = 0ul; i < N; i++)
					usr_handles[i].handle = handles[i];
			}

			~framebuffers(){
				functions::glDeleteFramebuffers(N, handles);
			}

			//! @returns the number of frambuffers stored
			std::size_t size() const noexcept{ return N; }

			//! implicit conversion to framebuffer_handle& when there is one element in the wrapped array
			template<typename T = framebuffer_handle&>
			operator std::enable_if_t<N == 1, T>() noexcept{ return usr_handles[0]; }

			//! implicit conversion to const framebuffer_handle& when there is one element in the wrapped array
			template<typename T = const framebuffer_handle&>
			operator std::enable_if_t<N == 1, T>() const noexcept{ return usr_handles[0]; }

			/**
			 * retrieve a reference to one of the elements of the wrapped array
			 * 
			 * @param[in] idx the index into the array of the element
			 * 
			 * @returns a constant reference to the indexed element
			 **/
			const framebuffer_handle &operator [](std::size_t idx) const noexcept{ return usr_handles[idx]; }
			
			/**
			 * retrieve a reference to one of the elements of the wrapped array
			 * 
			 * @param[in] idx the index into the array of the element
			 * 
			 * @returns a reference to the indexed element
			 **/
			framebuffer_handle &operator [](std::size_t idx) noexcept{ return usr_handles[idx]; }

		protected:
			framebuffer_handle usr_handles[N];
			GLuint handles[N];
	};

	//! convenienve type alias for when the array contains a single element
	using framebuffer = framebuffers<1>;

	template<>
	class framebuffers<0>;
}

#endif // GAPI_FRAMEBUFFER_HPP
