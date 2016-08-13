#ifndef GAPI_FRAMEBUFFER_HPP
#define GAPI_FRAMEBUFFER_HPP 1

#include <cstddef>

#include "constants.hpp"
#include "functions.hpp"

namespace gapi{
	class framebuffers_base{
		public:
			virtual std::size_t size() const noexcept = 0;

			virtual const framebuffer_handle &operator [](std::size_t) const noexcept = 0;
			virtual framebuffer_handle &operator [](std::size_t) noexcept = 0;
	};

	template<std::size_t N>
	class framebuffers: public framebuffers_base{
		public:
			framebuffers(){}
	};

	using framebuffer = framebuffers<1>;

	template<>
	class frambuffers<0>;
}

#endif // GAPI_FRAMEBUFFER_HPP
