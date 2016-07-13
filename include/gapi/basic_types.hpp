#ifndef GAPI_BASIC_TYPES_HPP
#define GAPI_BASIC_TYPES_HPP 1

#include <cstdint>

namespace gapi{
	using GLbyte = signed char;
	using GLubyte = unsigned char;
	using GLfloat = float;
	using GLdouble = double;
	using GLushort = std::uint_least16_t;
	using GLshort = std::int_least16_t;
	using GLuint = std::uint_least32_t;
	using GLint = std::int_least32_t;
	using GLboolean = bool;
	using GLsizei = GLint;
	using GLbitfield = GLuint;
	using GLenum = GLuint;
}

#endif // GAPI_BASIC_TYPES_HPP
