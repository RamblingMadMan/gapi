#if defined( __linux__ )
	#if defined( GAPI_EGL )
	#include <EGL/egl.h>
	void(*glGetProcAddress)(const char *name) = eglGetProcAddress;
	#else
	#include <GL/glx.h>
	void(*glGetProcAddress(const char *name))(){
		return glXGetProcAddress((const GLubyte*)name);
	}
	#endif
#elif defined( _WIN32 )
	#include <Wingdi.h>
	void(*glGetProcAddress(const char *name))(){
		return wglGetProcAddress(name);
	}
#elif defined( __APPLE__ ) && defined( __MACH__ )
	#error MacOS/OSX currently unsupported
#endif

#include "gapi/gapi.hpp"

void(*gapi::detail::get_gl_fp(const char *name))(){
	return glGetProcAddress(name);
}
