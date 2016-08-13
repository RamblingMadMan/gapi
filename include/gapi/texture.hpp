#ifndef GAPI_TEXTURE_HPP
#define GAPI_TEXTURE_HPP 1

#include <cstddef>
#include <type_traits>
#include <array>

#include "constants.hpp"
#include "functions.hpp"

namespace gapi{
	class texture_handle{
		public:
			virtual ~texture_handle() = default;

			virtual GLenum type() const noexcept = 0;

		protected:
			template<std::size_t>
			friend class textures;

			template<typename T>
			friend GLuint get_handle(const T&);

			GLuint handle;
	};

	class texture1D_handle: public texture_handle{
		public:
			void set_sub_data(
				GLint xoff,
				GLsizei width,
				GLenum format, GLenum type,
				const char *data,
				std::size_t len,
				GLint level = 0
			){
				functions::glTextureSubImage1D(
					handle,
					level,
					xoff,
					width,
					format, type,
					data
				);
			}

			GLenum type() const noexcept{
				return GL_TEXTURE_1D;
			}

		protected:
			texture1D_handle(){}
			
			template<std::size_t>
			friend class textures;

			template<typename T>
			friend GLuint get_handle(const T&);
	};

	class texture2D_handle: public texture_handle{
		public:
			void set_sub_data(
				GLint xoff, GLint yoff,
				GLsizei width, GLsizei height,
				GLenum format, GLenum type,
				const char *data,
				std::size_t len,
				GLint level = 0
			){
				functions::glTextureSubImage2D(
					handle,
					level,
					xoff, yoff,
					width, height,
					format, type,
					data
				);
			}

			GLenum type() const noexcept{
				return GL_TEXTURE_2D;
			}

		protected:
			texture2D_handle(){}
			
			template<std::size_t>
			friend class textures;

			template<typename T>
			friend GLuint get_handle(const T&);
	};

	class texture3D_handle: public texture_handle{
		public:
			void set_sub_data(
				GLint xoff, GLint yoff, GLint zoffset,
				GLsizei width, GLsizei height, GLsizei depth,
				GLenum format, GLenum type,
				const char *data,
				std::size_t len,
				GLint level = 0
			){
				functions::glTextureSubImage3D(
					handle,
					level,
					xoff, yoff, zoffset,
					width, height, depth,
					format, type,
					data
				);
			}

			GLenum type() const noexcept{
				return GL_TEXTURE_3D;
			}

		protected:
			texture3D_handle(){}
			
			template<std::size_t>
			friend class textures;

			template<typename T>
			friend GLuint get_handle(const T&);
	};

	class texture2D_multisample_handle: public texture_handle{
		public:
			void set_sub_data(
				GLint xoff, GLint yoff,
				GLsizei width, GLsizei height,
				GLenum format, GLenum type,
				const char *data,
				std::size_t len,
				GLint level = 0
			){
				functions::glTextureSubImage2D(
					handle,
					level,
					xoff, yoff,
					width, height,
					format, type,
					data
				);
			}

			GLenum type() const noexcept{
				return GL_TEXTURE_2D;
			}

		protected:
			texture2D_multisample_handle(){}
			
			template<std::size_t>
			friend class textures;

			template<typename T>
			friend GLuint get_handle(const T&);
	};
	
	/*
	template<std::size_t N>
	class mutable_textures{
		public:
			mutable_textures(const std::array<std::vector<std::uint32_t>, N> &sizes){
				glCreateTextures(N, handles);
			}

			virtual ~mutable_textures(){
				glDeleteTextures(N, handles);
			}

			template<typename T = const texture_ref&>
			operator std::enable_if_t<N == 1, T>() const noexcept{ return refs[0]; }

			template<typename T = texture_ref&>
			operator std::enable_if_t<N == 1, T>() noexcept{ return refs[0]; }

			const texture_ref &operator [](std::size_t idx) const noexcept{ return refs[idx]; }

			texture_ref &operator [](std::size_t idx) noexcept{ return refs[idx]; }

		protected:
			GLuint handles[N];
			texture_ref refs[N];
	};
	*/

	class texture_arg{
		private:
			texture_arg(GLenum f, GLsizei n_, std::vector<GLsizei> dims_, bool multisample_ = false, bool fsl = false)
				: format(f), n(n_), dims(std::move(dims_)), multisample(multisample_), fixedsamplelocations(fsl){}

			template<std::size_t>
			friend class textures;

			friend texture_arg tex1D(GLenum, GLsizei, GLsizei);
			friend texture_arg tex2D(GLenum, GLsizei, GLsizei, GLsizei);
			friend texture_arg tex3D(GLenum, GLsizei, GLsizei, GLsizei, GLsizei);

			friend texture_arg tex2D_multsample(GLenum, GLsizei, GLsizei, GLsizei, GLboolean);\

			GLenum format;
			GLsizei n;
			std::vector<GLsizei> dims;
			bool multisample, fixedsamplelocations;
	};

	inline texture_arg tex1D(GLenum format, GLsizei size, GLsizei levels = 1){
		return {format, levels, {size}};
	}

	inline texture_arg tex2D(GLenum format, GLsizei width, GLsizei height, GLsizei levels = 1){
		return {format, levels, {width, height}};
	}

	inline texture_arg tex3D(GLenum format, GLsizei width, GLsizei height, GLsizei depth, GLsizei levels = 1){
		return {format, levels, {width, height, depth}};
	}

	inline texture_arg tex2D_multsample(GLenum format, GLsizei width, GLsizei height, GLsizei samples, GLboolean fixedsamplelocations){
		return {format, samples, {width, height}, true, fixedsamplelocations};
	}

	class textures_base{
		public:
			virtual ~textures_base() = default;

			virtual std::size_t size() const noexcept = 0;

			virtual texture_handle &operator[](std::size_t idx) noexcept = 0;
			virtual const texture_handle &operator[](std::size_t idx) const noexcept = 0;
	};

	template<std::size_t N>
	class textures: public textures_base{
		public:
			textures(const std::array<texture_arg, N> &texs){

				for(auto i = 0ul; i < N; i++){
					if(texs[i].multisample){
						switch(texs[i].dims.size()){
							case 2:{
								functions::glCreateTextures(GL_TEXTURE_2D_MULTISAMPLE, 1, &handles[i]);
								functions::glTextureStorage2DMultisample(
									handles[i],
									texs[i].n,
									texs[i].format,
									texs[i].dims[0],
									texs[i].dims[1],
									texs[i].fixedsamplelocations
								);
								usr_handles[i] =  new texture2D_multisample_handle;
								usr_handles[i]->handle = handles[i];
								break;
							}

							default:
								throw std::runtime_error{"invalid dimensions"};
						}
					}
					else{
						switch(texs[i].dims.size()){
							case 1:{
								functions::glCreateTextures(GL_TEXTURE_1D, 1, &handles[i]);
								functions::glTextureStorage1D(
									handles[i],
									texs[i].n,
									texs[i].format,
									texs[i].dims[0]
								);
								usr_handles[i] = new texture1D_handle;
								usr_handles[i]->handle = handles[i];
								break;
							}

							case 2:{
								functions::glCreateTextures(GL_TEXTURE_2D, 1, &handles[i]);
								functions::glTextureStorage2D(
									handles[i],
									texs[i].n,
									texs[i].format,
									texs[i].dims[0],
									texs[i].dims[1]
								);
								usr_handles[i] = new texture2D_handle;
								usr_handles[i]->handle = handles[i];
								break;
							}

							case 3:{
								functions::glCreateTextures(GL_TEXTURE_3D, 1, &handles[i]);
								functions::glTextureStorage3D(
									handles[i],
									texs[i].n,
									texs[i].format,
									texs[i].dims[0],
									texs[i].dims[1],
									texs[i].dims[2]
								);
								usr_handles[i] = new texture3D_handle;
								usr_handles[i]->handle = handles[i];
								break;
							}

							default:
								throw std::runtime_error{"invalid dimensions"};
						}
					}
				}
			}
			
			virtual ~textures(){
				functions::glDeleteTextures(N, handles);
				for(auto *&p : usr_handles)
					delete p;
			}
			
			template<typename T = const texture_handle&>
			operator std::enable_if_t<N==1, T>() const noexcept{ return *usr_handles[0]; }

			template<typename T = texture_handle&>
			operator std::enable_if_t<N==1, T>() noexcept{ return *usr_handles[0]; }
			
			std::size_t size() const noexcept{ return N; }

			texture_handle &operator[](std::size_t idx) noexcept{
				return *usr_handles[idx];
			}
			
			const texture_handle &operator[](std::size_t idx) const noexcept{
				return *usr_handles[idx];
			}
			
		private:
			GLuint handles[N];
			texture_handle *usr_handles[N];
	};
	
	using texture = textures<1>;
	
	template<>
	class textures<0>;
}

#endif // GAPI_TEXTURE_HPP
