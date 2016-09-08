#ifndef GAPI_UTILITY_HPP
#define GAPI_UTILITY_HPP 1

#include "types.hpp"

namespace gapi{
	template<typename T>
	GLuint get_handle(const T &t){
		return t.handle;
	}
}

#endif // GAPI_UTILITY_HPP
