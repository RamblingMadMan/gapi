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
			constexpr framebuffer_category() = default;

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
				glNamedFramebufferTexture(handle, attachment, get_handle(tex), level);
			}

			void use(framebuffer_type type) noexcept{
				glBindFramebuffer(
					static_cast<GLenum>(type),
					handle
				);
			}

			void draw_buffer(){}

			template<typename Head, typename ... Tail>
			void draw_buffers(Head &&head, Tail &&... tail){
				std::vector<GLenum> bufs{std::forward<Head>(head), std::forward<Tail>(tail)...};
				glNamedFramebufferDrawBuffers(handle, bufs.size(), bufs.data());
				GLenum err = glGetError();
				if(err != GL_NO_ERROR){
					framebuffer_draw_buffers_category cat;
					throw std::system_error{static_cast<int>(err), cat};
				}
			}

		protected:
			framebuffer_handle(GLuint handle_): handle{handle_}{}

			GLuint handle;
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
				functions::glCreateFramebuffers(N, &handles);
			}

			~framebuffers(){
				functions::glDeleteFramebuffers(N, &handles);
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
	class frambuffers<0>;
}

#endif // GAPI_FRAMEBUFFER_HPP
