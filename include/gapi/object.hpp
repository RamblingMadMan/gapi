#ifndef GAPI_OBJECT_HPP
#define GAPI_OBJECT_HPP 1

#include "types.hpp"

namespace gapi{
	class object{
		public:
			virtual ~object() = default;
			
			//! @returns the OpenGL object name/handle
			GLuint get_handle() const noexcept{ return handle; }
			
		protected:
			GLuint handle;
	};
}

#endif // GAPI_OBJECT_HPP

