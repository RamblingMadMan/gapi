#include "gapi/gapi.hpp"
#include "gapi/texture.hpp"
#include "gapi/shader.hpp"

#if defined( GAPI_EGL )
	#include <EGL/egl.h>
	void(const* glGetProcAddress)(const char *name) = eglGetProcAddress;
#elif defined( __linux__ )
	#include <GL/glx.h>
	void(*glGetProcAddress(const char *name))(){
		return glXGetProcAddress((const GLubyte*)name);
	}
#elif defined( _WIN32 )
	#include <Wingdi.h>
	void(const *glGetProcAddress)(const char *name) = wglGetProcAddress;
#elif defined( __APPLE__ ) && defined( __MACH__ )
	#error MacOS/OSX currently unsupported
#endif

void(*gapi::detail::get_gl_fp(const char *name))(){
	return glGetProcAddress(name);
}
