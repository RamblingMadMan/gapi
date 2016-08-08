#ifndef GAPI_TEXTURE_HPP
#define GAPI_TEXTURE_HPP 1

#include <cstddef>
#include <type_traits>

#include "constants.hpp"
#include "functions.hpp"

namespace gapi{
	class texture_ref{
		public:
			
		private:
			texture_ref(){}
			
			template<std::size_t>
			friend class textures;
			
			GLuint handle;
	};
	
	template<std::size_t N>
	class textures{
		public:
			textures(){
				glGenTextures(N, handles);
				for(auto i = 0ul; i < N; i++)
					refs[i].handle = handles[i];
			}
			
			~textures(){
				glDeleteTextures(N, handles);
			}
			
			operator std::enable_if_t<N==1, const texture_ref&>() const noexcept{ return refs[0]; }
			operator std::enable_if_t<N==1, texture_ref&>() noexcept{ return refs[0]; }
			
			texture_ref &operator[](std::size_t idx) noexcept{
				return refs[idx];
			}
			
			const texture_ref &operator[](std::size_t idx) const noexcept{
				return refs[idx];
			}
			
			std::size_t size() const noexcept{ return N; }
			
		private:
			GLuint handles[N];
			texture_ref refs[N];
	};
	
	using texture = textures<1>;
	
	template<>
	class textures<0>;
}

#endif // GAPI_TEXTURE_HPP
