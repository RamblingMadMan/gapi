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

	enum class framebuffer_type: GLenum{
		write = GL_DRAW_FRAMEBUFFER, read = GL_READ_FRAMEBUFFER,
		readwrite = GL_FRAMEBUFFER
	};

	class framebuffer_handle{
		public:
			void attach_texture(GLenum attachment, const texture_handle &tex, GLint level = 0){
				functions::glNamedFramebufferTexture(handle, attachment, get_handle(tex), level);
			}

			void use(framebuffer_type type) noexcept{
				functions::glBindFramebuffer(
					static_cast<GLenum>(type),
					handle
				);
			}

			void draw_buffer(){}

			template<typename ... Tail>
			void draw_buffers(GLenum head, Tail &&... tail){
				std::vector<GLenum> bufs{head, std::forward<Tail>(tail)...};
				functions::glNamedFramebufferDrawBuffers(handle, bufs.size(), bufs.data());
				GLenum err = functions::glGetError();
				if(err != GL_NO_ERROR){
					framebuffer_draw_buffers_category cat;
					throw std::system_error{static_cast<int>(err), cat};
				}
			}

		protected:
			GLuint handle;
			
			template<std::size_t>
			friend class framebuffers;
			
			template<typename T>
			friend GLuint get_handle(const T&);
	};

	class framebuffers_base{
		public:
			virtual std::size_t size() const noexcept = 0;

			virtual const framebuffer_handle &operator [](std::size_t) const noexcept = 0;
			virtual framebuffer_handle &operator [](std::size_t) noexcept = 0;
	};

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

			std::size_t size() const noexcept{ return N; }

			template<typename T = framebuffer_handle&>
			operator std::enable_if_t<N == 1, T>() noexcept{ return usr_handles[0]; }

			template<typename T = const framebuffer_handle&>
			operator std::enable_if_t<N == 1, T>() const noexcept{ return usr_handles[0]; }

			const framebuffer_handle &operator [](std::size_t n) const noexcept{ return usr_handles[n]; }
			framebuffer_handle &operator [](std::size_t n) noexcept{ return usr_handles[n]; }

		protected:
			framebuffer_handle usr_handles[N];
			GLuint handles[N];
	};

	using framebuffer = framebuffers<1>;

	template<>
	class framebuffers<0>;
}

#endif // GAPI_FRAMEBUFFER_HPP
