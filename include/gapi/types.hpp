#ifndef GAPI_BASIC_TYPES_HPP
#define GAPI_BASIC_TYPES_HPP 1

#include <cstdint>

namespace gapi{
	using GLvoid = void;
	using GLchar = char;
	using GLbyte = signed char;
	using GLubyte = unsigned char;
	using GLfloat = float;
	using GLdouble = double;
	using GLclampf = GLfloat;
	using GLclampd = GLdouble;
	using GLdouble = double;
	using GLushort = std::uint_least16_t;
	using GLshort = std::int_least16_t;
	using GLuint = std::uint_least32_t;
	using GLint = std::int_least32_t;
	using GLuint64 = std::uint_least64_t;
	using GLint64 = std::int_least64_t;
	using GLboolean = bool;
	using GLsizei = GLint;
	using GLbitfield = GLuint;
	using GLenum = GLuint;
	using GLintptr = std::intptr_t;
	using GLsizeiptr = std::intptr_t;
	using GLsync = std::uintptr_t;

	using GLDEBUGPROC = void(*)(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam
	);
}

#endif // GAPI_BASIC_TYPES_HPP
