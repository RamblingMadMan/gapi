#if defined( __linux__ )
	#if defined( GAPI_EGL )
	#include <EGL/egl.h>
	#else
	#include <GL/glx.h>
	void(*glGetProcAddress(const char *name))(){
		return glXGetProcAddress((const GLubyte*)name);
	}
	#endif
#elif defined( _WIN32 )

#elif defined( __APPLE__ ) && defined( __MACH__ )

#endif

#include "gapi/gapi.hpp"

void(*gapi::detail::get_gl_fp(const char *name))(){
	return glGetProcAddress(name);
}
