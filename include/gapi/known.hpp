#ifndef GAPI_KNOWN_HPP
#define GAPI_KNOWN_HPP 1

#include <cstring>
#include <vector>
#include <string>
#include <utility>
#include <typeinfo>

#include "types.hpp"

namespace gapi{
	class known{
		private:
			auto safe_compare(const char *usr, const char *cst){
				return std::strncmp(usr, cst, std::strlen(cst)) == 0;
			}

		public:
			known(const char *fn){
				if(safe_compare(fn, "glActiveShaderProgram")){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glActiveTexture")){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glAttachShader")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBeginConditionalRender")){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glEndConditionalRender")){
					ret = typeid(void).name();
				}
				else if(safe_compare(fn, "glBeginQuery")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glEndQuery")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBeginQueryIndexed")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glEndQueryIndexed")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBeginTransformFeedback")){
					ret = typeid(void).name();
					args.emplace_back("primitiveMode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glEndTransformFeedback")){
					ret = typeid(void).name();
				}
				else if(safe_compare(fn, "glBindAttribLocation")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glBindBuffer")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBindBufferBase")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBindBufferRange")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("buffer", typeid(GLuint).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
				}
				else if(safe_compare(fn, "glBindFragDataLocation")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("colorNumber", typeid(GLuint).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(safe_compare(fn, "glBindFragDataLocationIndexed")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("colorNumber", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(safe_compare(fn, "glBindFramebuffer")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("framebuffer", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBindProgramPipeline")){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBindRenderbuffer")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("renderbuffer", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBindSampler")){
					ret = typeid(void).name();
					args.emplace_back("unit", typeid(GLuint).name());
					args.emplace_back("sampler", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBindTexture")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBindTransformFeedback")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBindVertexArray")){
					ret = typeid(void).name();
					args.emplace_back("array", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glBlendColor")){
					ret = typeid(void).name();
					args.emplace_back("red", typeid(GLclampf).name());
					args.emplace_back("green", typeid(GLclampf).name());
					args.emplace_back("blue", typeid(GLclampf).name());
					args.emplace_back("alpha", typeid(GLclampf).name());
				}
				else if(safe_compare(fn, "glBlendEquation")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBlendEquationi")){
					ret = typeid(void).name();
					args.emplace_back("buf", typeid(GLuint).name());
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBlendEquationSeparate")){
					ret = typeid(void).name();
					args.emplace_back("modeRGB", typeid(GLenum).name());
					args.emplace_back("modeAlpha", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBlendEquationSeparatei")){
					ret = typeid(void).name();
					args.emplace_back("buf", typeid(GLuint).name());
					args.emplace_back("modeRGB", typeid(GLenum).name());
					args.emplace_back("modeAlpha", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBlendFunc")){
					ret = typeid(void).name();
					args.emplace_back("sfactor", typeid(GLenum).name());
					args.emplace_back("dfactor", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBlendFunci")){
					ret = typeid(void).name();
					args.emplace_back("buf", typeid(GLuint).name());
					args.emplace_back("sfactor", typeid(GLenum).name());
					args.emplace_back("dfactor", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBlendFuncSeparate")){
					ret = typeid(void).name();
					args.emplace_back("srcRGB", typeid(GLenum).name());
					args.emplace_back("dstRGB", typeid(GLenum).name());
					args.emplace_back("srcAlpha", typeid(GLenum).name());
					args.emplace_back("dstAlpha", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBlendFuncSeparatei")){
					ret = typeid(void).name();
					args.emplace_back("buf", typeid(GLuint).name());
					args.emplace_back("srcRGB", typeid(GLenum).name());
					args.emplace_back("dstRGB", typeid(GLenum).name());
					args.emplace_back("srcAlpha", typeid(GLenum).name());
					args.emplace_back("dstAlpha", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBlitFramebuffer")){
					ret = typeid(void).name();
					args.emplace_back("srcX0", typeid(GLint).name());
					args.emplace_back("srcY0", typeid(GLint).name());
					args.emplace_back("srcX1", typeid(GLint).name());
					args.emplace_back("srcY1", typeid(GLint).name());
					args.emplace_back("dstX0", typeid(GLint).name());
					args.emplace_back("dstY0", typeid(GLint).name());
					args.emplace_back("dstX1", typeid(GLint).name());
					args.emplace_back("dstY1", typeid(GLint).name());
					args.emplace_back("mask", typeid(GLbitfield).name());
					args.emplace_back("filter", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBufferData")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
					args.emplace_back("data", typeid(GLvoid *).name());
					args.emplace_back("usage", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glBufferSubData")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glCheckFramebufferStatus")){
					ret = typeid(GLenum).name();
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glClampColor")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("clamp", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glClear")){
					ret = typeid(void).name();
					args.emplace_back("mask", typeid(GLbitfield).name());
				}
				else if(safe_compare(fn, "glClearBufferiv")){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLenum).name());
					args.emplace_back("drawBuffer", typeid(GLint).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glClearBufferuiv")){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLenum).name());
					args.emplace_back("drawBuffer", typeid(GLint).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glClearBufferfv")){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLenum).name());
					args.emplace_back("drawBuffer", typeid(GLint).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glClearBufferfi")){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLenum).name());
					args.emplace_back("drawBuffer", typeid(GLint).name());
					args.emplace_back("depth", typeid(GLfloat).name());
					args.emplace_back("stencil", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glClearColor")){
					ret = typeid(void).name();
					args.emplace_back("red", typeid(GLclampf).name());
					args.emplace_back("green", typeid(GLclampf).name());
					args.emplace_back("blue", typeid(GLclampf).name());
					args.emplace_back("alpha", typeid(GLclampf).name());
				}
				else if(safe_compare(fn, "glClearDepth")){
					ret = typeid(void).name();
					args.emplace_back("depth", typeid(GLclampd).name());
				}
				else if(safe_compare(fn, "glClearDepthf")){
					ret = typeid(void).name();
					args.emplace_back("depth", typeid(GLclampf).name());
				}
				else if(safe_compare(fn, "glClearStencil")){
					ret = typeid(void).name();
					args.emplace_back("s", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glClientWaitSync")){
					ret = typeid(GLenum).name();
					args.emplace_back("sync", typeid(GLsync).name());
					args.emplace_back("flags", typeid(GLbitfield).name());
					args.emplace_back("timeout", typeid(GLuint64).name());
				}
				else if(safe_compare(fn, "glColorMask")){
					ret = typeid(void).name();
					args.emplace_back("red", typeid(GLboolean).name());
					args.emplace_back("green", typeid(GLboolean).name());
					args.emplace_back("blue", typeid(GLboolean).name());
					args.emplace_back("alpha", typeid(GLboolean).name());
				}
				else if(safe_compare(fn, "glCompileShader")){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glCompressedTexImage1D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
					args.emplace_back("imageSize", typeid(GLsizei).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glCompressedTexImage2D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
					args.emplace_back("imageSize", typeid(GLsizei).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glCompressedTexImage3D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
					args.emplace_back("imageSize", typeid(GLsizei).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glCompressedTexSubImage1D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("imageSize", typeid(GLsizei).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glCompressedTexSubImage2D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("yoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("imageSize", typeid(GLsizei).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glCompressedTexSubImage3D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("yoffset", typeid(GLint).name());
					args.emplace_back("zoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("imageSize", typeid(GLsizei).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glCopyBufferSubData")){
					ret = typeid(void).name();
					args.emplace_back("readtarget", typeid(GLenum).name());
					args.emplace_back("writetarget", typeid(GLenum).name());
					args.emplace_back("readoffset", typeid(GLintptr).name());
					args.emplace_back("writeoffset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
				}
				else if(safe_compare(fn, "glCopyTexImage1D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glCopyTexImage2D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glCopyTexSubImage1D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glCopyTexSubImage2D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("yoffset", typeid(GLint).name());
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glCopyTexSubImage3D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("yoffset", typeid(GLint).name());
					args.emplace_back("zoffset", typeid(GLint).name());
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glCreateProgram")){
					ret = typeid(GLuint).name();
				}
				else if(safe_compare(fn, "glCreateShader")){
					ret = typeid(GLuint).name();
					args.emplace_back("shaderType", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glCreateShaderProgramv")){
					ret = typeid(GLuint).name();
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("strings", typeid(char **).name());
				}
				else if(safe_compare(fn, "glCullFace")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glDeleteBuffers")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("buffers", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glDeleteFramebuffers")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("framebuffers", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glDeleteProgram")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glDeleteProgramPipelines")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("pipelines", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glDeleteQueries")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glDeleteRenderbuffers")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("renderbuffers", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glDeleteSamplers")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glDeleteShader")){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glDeleteSync")){
					ret = typeid(void).name();
					args.emplace_back("sync", typeid(GLsync).name());
				}
				else if(safe_compare(fn, "glDeleteTextures")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("textures", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glDeleteTransformFeedbacks")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glDeleteVertexArrays")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("arrays", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glDepthFunc")){
					ret = typeid(void).name();
					args.emplace_back("func", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glDepthMask")){
					ret = typeid(void).name();
					args.emplace_back("flag", typeid(GLboolean).name());
				}
				else if(safe_compare(fn, "glDepthRange")){
					ret = typeid(void).name();
					args.emplace_back("nearVal", typeid(GLclampd).name());
					args.emplace_back("farVal", typeid(GLclampd).name());
				}
				else if(safe_compare(fn, "glDepthRangef")){
					ret = typeid(void).name();
					args.emplace_back("nearVal", typeid(GLclampf).name());
					args.emplace_back("farVal", typeid(GLclampf).name());
				}
				else if(safe_compare(fn, "glDepthRangeArrayv")){
					ret = typeid(void).name();
					args.emplace_back("first", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("v", typeid(GLclampd *).name());
				}
				else if(safe_compare(fn, "glDepthRangeIndexed")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("nearVal", typeid(GLclampd).name());
					args.emplace_back("farVal", typeid(GLclampd).name());
				}
				else if(safe_compare(fn, "glDetachShader")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glDrawArrays")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("first", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glDrawArraysIndirect")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("indirect", typeid(void *).name());
				}
				else if(safe_compare(fn, "glDrawArraysInstanced")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("first", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glDrawBuffer")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glDrawBuffers")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("bufs", typeid(GLenum *).name());
				}
				else if(safe_compare(fn, "glDrawElements")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glDrawElementsBaseVertex")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
					args.emplace_back("basevertex", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glDrawElementsIndirect")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indirect", typeid(void *).name());
				}
				else if(safe_compare(fn, "glDrawElementsInstanced")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(void *).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glDrawElementsInstancedBaseVertex")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
					args.emplace_back("basevertex", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glDrawRangeElements")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("start", typeid(GLuint).name());
					args.emplace_back("end", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glDrawRangeElementsBaseVertex")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("start", typeid(GLuint).name());
					args.emplace_back("end", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
					args.emplace_back("basevertex", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glDrawTransformFeedback")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glDrawTransformFeedbackStream")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("stream", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glEnable")){
					ret = typeid(void).name();
					args.emplace_back("cap", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glDisable")){
					ret = typeid(void).name();
					args.emplace_back("cap", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glEnablei")){
					ret = typeid(void).name();
					args.emplace_back("cap", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glDisablei")){
					ret = typeid(void).name();
					args.emplace_back("cap", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glEnableVertexAttribArray")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glDisableVertexAttribArray")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glFenceSync")){
					ret = typeid(GLsync).name();
					args.emplace_back("condition", typeid(GLenum).name());
					args.emplace_back("flags", typeid(GLbitfield).name());
				}
				else if(safe_compare(fn, "glFinish")){
					ret = typeid(void).name();
				}
				else if(safe_compare(fn, "glFlush")){
					ret = typeid(void).name();
				}
				else if(safe_compare(fn, "glFlushMappedBufferRange")){
					ret = typeid(GLsync).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("length", typeid(GLsizeiptr).name());
				}
				else if(safe_compare(fn, "glFramebufferRenderbuffer")){
					ret = typeid(GLsync).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("renderbuffertarget", typeid(GLenum).name());
					args.emplace_back("renderbuffer", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glFramebufferTexture")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glFramebufferTexture1D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("textarget", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glFramebufferTexture2D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("textarget", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glFramebufferTexture3D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("textarget", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("layer", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glFramebufferTextureLayer")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("layer", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glFrontFace")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glGenBuffers")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("buffers", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGenFramebuffers")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGenProgramPipelines")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("pipelines", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGenQueries")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGenRenderbuffers")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("renderbuffers", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGenSamplers")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("samplers", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGenTextures")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("textures", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGenTransformFeedbacks")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGenVertexArrays")){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("arrays", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGenerateMipmap")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glGetBooleanv")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLboolean *).name());
				}
				else if(safe_compare(fn, "glGetDoublev")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glGetFloatv")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glGetIntegerv")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetInteger64v")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint64 *).name());
				}
				else if(safe_compare(fn, "glGetBooleani_v")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("data", typeid(GLboolean *).name());
				}
				else if(safe_compare(fn, "glGetIntegeri_v")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("data", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetInteger64i_v")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("data", typeid(GLint64 *).name());
				}
				else if(safe_compare(fn, "glGetActiveAttrib")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("size", typeid(GLint *).name());
					args.emplace_back("type", typeid(GLenum *).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetActiveSubroutineName")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufsize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetActiveSubroutineUniformiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("values", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetActiveSubroutineUniformName")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufsize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetActiveUniform")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("size", typeid(GLint *).name());
					args.emplace_back("type", typeid(GLenum *).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetActiveUniformBlockiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformBlockIndex", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glGetActiveUniformBlockName")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformBlockIndex", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("uniformBlockName", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetActiveUniformName")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformIndex", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("uniformName", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetActiveUniformsiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformCount", typeid(GLsizei).name());
					args.emplace_back("uniformIndices", typeid(GLuint *).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetAttachedShaders")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("maxCount", typeid(GLsizei).name());
					args.emplace_back("count", typeid(GLsizei *).name());
					args.emplace_back("shaders", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGetAttribLocation")){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetBufferParameteriv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("value", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetBufferPointerv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLvoid **).name());
				}
				else if(safe_compare(fn, "glGetBufferSubData")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glGetCompressedTexImage")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("lod", typeid(GLint).name());
					args.emplace_back("img", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glGetError")){
					ret = typeid(GLenum).name();
				}
				else if(safe_compare(fn, "glGetFragDataIndex")){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(safe_compare(fn, "glGetFragDataLocation")){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(safe_compare(fn, "glGetFramebufferAttachmentParameter")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetMultisamplefv")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("val", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glGetProgramiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetProgramBinary")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("bufsize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("binaryFormat", typeid(GLenum *).name());
					args.emplace_back("binary", typeid(void *).name());
				}
				else if(safe_compare(fn, "glGetProgramInfoLog")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("maxLength", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("infoLog", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetProgramPipelineiv")){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetProgramPipelineInfoLog")){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("infoLog", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetProgramStageiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("values", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetQueryIndexediv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetQueryObjectiv")){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetQueryObjectuiv")){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGetQueryObjecti64v")){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint64 *).name());
				}
				else if(safe_compare(fn, "glGetQueryObjectui64v")){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLuint64 *).name());
				}
				else if(safe_compare(fn, "glGetQueryiv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetRenderbufferParameteriv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetSamplerParameterfv")){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glGetSamplerParameteriv")){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetShaderiv")){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetShaderInfoLog")){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
					args.emplace_back("maxLength", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("infoLog", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetShaderPrecisionFormat")){
					ret = typeid(void).name();
					args.emplace_back("shaderType", typeid(GLenum).name());
					args.emplace_back("precisionType", typeid(GLenum).name());
					args.emplace_back("range", typeid(GLint *).name());
					args.emplace_back("precision", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetShaderSource")){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("source", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetString")){
					ret = typeid(GLubyte*).name();
					args.emplace_back("name", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glGetStringi")){
					ret = typeid(GLubyte*).name();
					args.emplace_back("name", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glGetSubroutineIndex")){
					ret = typeid(GLuint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetSubroutineUniformLocation")){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetSynciv")){
					ret = typeid(void).name();
					args.emplace_back("sync", typeid(GLsync).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("values", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetTexImage")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("img", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glGetTexLevelParameterfv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glGetTexLevelParameteriv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetTexParameterfv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glGetTexParameteriv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetTransformFeedbackVarying")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("size", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum *).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(safe_compare(fn, "glGetUniformfv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glGetUniformiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetUniformBlockIndex")){
					ret = typeid(GLuint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformBlockName", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetUniformIndices")){
					ret = typeid(GLuint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformCount", typeid(GLsizei).name());
					args.emplace_back("uniformNames", typeid(GLchar **).name());
					args.emplace_back("uniformIndices", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGetUniformLocation")){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(safe_compare(fn, "glGetUniformSubroutineuiv")){
					ret = typeid(void).name();
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("values", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGetVertexAttribdv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glGetVertexAttribfv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glGetVertexAttribiv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetVertexAttribIiv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glGetVertexAttribIuiv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glGetVertexAttribLdv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glGetVertexAttribPointerv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("pointer", typeid(GLvoid **).name());
				}
				else if(safe_compare(fn, "glHint")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glIsBuffer")){
					ret = typeid(GLboolean).name();
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsEnabled")){
					ret = typeid(GLboolean).name();
					args.emplace_back("cap", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glIsFramebuffer")){
					ret = typeid(GLboolean).name();
					args.emplace_back("framebuffer", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsProgram")){
					ret = typeid(GLboolean).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsProgramPipeline")){
					ret = typeid(GLboolean).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsQuery")){
					ret = typeid(GLboolean).name();
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsRenderbuffer")){
					ret = typeid(GLboolean).name();
					args.emplace_back("renderbuffer", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsSampler")){
					ret = typeid(GLboolean).name();
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsShader")){
					ret = typeid(GLboolean).name();
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsSync")){
					ret = typeid(GLboolean).name();
					args.emplace_back("sync", typeid(GLsync).name());
				}
				else if(safe_compare(fn, "glIsTexture")){
					ret = typeid(GLboolean).name();
					args.emplace_back("texture", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsTransformFeedback")){
					ret = typeid(GLboolean).name();
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glIsVertexArray")){
					ret = typeid(GLboolean).name();
					args.emplace_back("array", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glLineWidth")){
					ret = typeid(void).name();
					args.emplace_back("width", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glLinkProgram")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glLogicOp")){
					ret = typeid(void).name();
					args.emplace_back("opcode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glMapBuffer")){
					ret = typeid(void *).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("access", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glUnmapBuffer")){
					ret = typeid(GLboolean).name();
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glMapBufferRange")){
					ret = typeid(void *).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("length", typeid(GLsizeiptr).name());
					args.emplace_back("access", typeid(GLbitfield).name());
				}
				else if(safe_compare(fn, "glMinSampleShading")){
					ret = typeid(void).name();
					args.emplace_back("value", typeid(GLclampf).name());
				}
				else if(safe_compare(fn, "glMultiDrawArrays")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("first", typeid(GLint *).name());
					args.emplace_back("count", typeid(GLsizei *).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glMultiDrawElements")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei *).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid **).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glMultiDrawElementsBaseVertex")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei *).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid **).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
					args.emplace_back("basevertex", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glPatchParameteri")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("value", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glPatchParameterfv")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("values", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glPauseTransformFeedback")){
					ret = typeid(void).name();
				}
				else if(safe_compare(fn, "glPixelStoref")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glPixelStorei")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glPointParameterf")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glPointParameteri")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glPointParameterfv")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glPointParameteriv")){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glPointSize")){
					ret = typeid(void).name();
					args.emplace_back("size", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glPolygonMode")){
					ret = typeid(void).name();
					args.emplace_back("face", typeid(GLenum).name());
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glPolygonOffset")){
					ret = typeid(void).name();
					args.emplace_back("factor", typeid(GLfloat).name());
					args.emplace_back("units", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glPrimitiveRestartIndex")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glProgramBinary")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("binaryFormat", typeid(GLenum).name());
					args.emplace_back("binary", typeid(void *).name());
					args.emplace_back("length", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glProgramParameteri")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("value", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glProgramUniform1f")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glProgramUniform2f")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glProgramUniform3f")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glProgramUniform4f")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
					args.emplace_back("v3", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glProgramUniform1i")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glProgramUniform2i")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glProgramUniform3i")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glProgramUniform4i")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glProgramUniform1ui")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glProgramUniform2ui")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glProgramUniform3ui")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glProgramUniform4ui")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glProgramUniform1fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniform2fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniform3fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniform4fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniform1iv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glProgramUniform2iv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glProgramUniform3iv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glProgramUniform4iv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glProgramUniform1uiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glProgramUniform2uiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glProgramUniform3uiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glProgramUniform4uiv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glProgramUniformMatrix2fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniformMatrix3fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniformMatrix4fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniformMatrix2x3fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniformMatrix3x2fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniformMatrix2x4fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniformMatrix4x2fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniformMatrix3x4fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProgramUniformMatrix4x3fv")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glProvokingVertex")){
					ret = typeid(void).name();
					args.emplace_back("provokeMode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glQueryCounter")){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glReadBuffer")){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glReadPixels")){
					ret = typeid(void).name();
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glReleaseShaderCompiler")){
					ret = typeid(void).name();
				}
				else if(safe_compare(fn, "glRenderbufferStorage")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glRenderbufferStorageMultisample")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glResumeTransformFeedback")){
					ret = typeid(void).name();
				}
				else if(safe_compare(fn, "glSampleCoverage")){
					ret = typeid(void).name();
					args.emplace_back("value", typeid(GLclampf).name());
					args.emplace_back("invert", typeid(GLboolean).name());
				}
				else if(safe_compare(fn, "glSampleMaski")){
					ret = typeid(void).name();
					args.emplace_back("maskNumber", typeid(GLuint).name());
					args.emplace_back("mask", typeid(GLbitfield).name());
				}
				else if(safe_compare(fn, "glSamplerParameterf")){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glSamplerParameteri")){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glSamplerParameterfv")){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glSamplerParameteriv")){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glScissor")){
					ret = typeid(void).name();
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glScissorArrayv")){
					ret = typeid(void).name();
					args.emplace_back("first", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glScissorIndexed")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("left", typeid(GLint).name());
					args.emplace_back("bottom", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glScissorIndexedv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glShaderBinary")){
					ret = typeid(void).name();
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("shaders", typeid(GLuint *).name());
					args.emplace_back("binaryFormat", typeid(GLenum).name());
					args.emplace_back("binary", typeid(void *).name());
					args.emplace_back("length", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glShaderSource")){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("string", typeid(GLchar **).name());
					args.emplace_back("length", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glStencilFunc")){
					ret = typeid(void).name();
					args.emplace_back("func", typeid(GLenum).name());
					args.emplace_back("_ref", typeid(GLint).name());
					args.emplace_back("mask", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glStencilFuncSeparate")){
					ret = typeid(void).name();
					args.emplace_back("face", typeid(GLenum).name());
					args.emplace_back("func", typeid(GLenum).name());
					args.emplace_back("_ref", typeid(GLint).name());
					args.emplace_back("mask", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glStencilMask")){
					ret = typeid(void).name();
					args.emplace_back("mask", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glStencilMaskSeparate")){
					ret = typeid(void).name();
					args.emplace_back("face", typeid(GLenum).name());
					args.emplace_back("mask", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glStencilOp")){
					ret = typeid(void).name();
					args.emplace_back("sfail", typeid(GLenum).name());
					args.emplace_back("dpfail", typeid(GLenum).name());
					args.emplace_back("dppass", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glStencilOpSeparate")){
					ret = typeid(void).name();
					args.emplace_back("face", typeid(GLenum).name());
					args.emplace_back("sfail", typeid(GLenum).name());
					args.emplace_back("dpfail", typeid(GLenum).name());
					args.emplace_back("dppass", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glTexBuffer")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("internalFormat", typeid(GLenum).name());
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glTexImage1D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalFormat", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glTexImage2D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalFormat", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glTexImage2DMultisample")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("fixedsamplelocations", typeid(GLboolean).name());
				}
				else if(safe_compare(fn, "glTexImage3D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalFormat", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glTexImage3DMultisample")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
					args.emplace_back("fixedsamplelocations", typeid(GLboolean).name());
				}
				else if(safe_compare(fn, "glTexParameterf")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glTexParameteri")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glTexParameterfv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glTexParameteriv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glTexParameterIiv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glTexParameterIuiv")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glTexSubImage1D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glTexSubImage2D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("yoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glTexSubImage3D")){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("yoffset", typeid(GLint).name());
					args.emplace_back("zoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glTransformFeedbackVaryings")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("varyings", typeid(char **).name());
					args.emplace_back("bufferMode", typeid(GLenum).name());
				}
				else if(safe_compare(fn, "glUniform1f")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glUniform2f")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glUniform3f")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glUniform4f")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
					args.emplace_back("v3", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glUniform1i")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glUniform2i")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glUniform3i")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glUniform4i")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glUniform1ui")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glUniform2ui")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glUniform3ui")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glUniform4ui")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glUniform1fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniform2fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniform3fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniform4fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniform1iv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glUniform2iv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glUniform3iv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glUniform4iv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glUniform1uiv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glUniform2uiv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glUniform3uiv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glUniform4uiv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glUniformMatrix2fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniformMatrix3fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniformMatrix4fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniformMatrix2x3fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniformMatrix3x2fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniformMatrix2x4fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniformMatrix4x2fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniformMatrix3x4fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniformMatrix4x3fv")){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glUniformBlockBinding")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformBlockIndex", typeid(GLuint).name());
					args.emplace_back("uniformBlockBinding", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glUniformSubroutinesuiv")){
					ret = typeid(void).name();
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("indices", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glUseProgram")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glUseProgramStages")){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
					args.emplace_back("stages", typeid(GLbitfield).name());
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glValidateProgram")){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glValidateProgramPipeline")){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttrib1f")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glVertexAttrib1s")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLshort).name());
				}
				else if(safe_compare(fn, "glVertexAttrib1d")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
				}
				else if(safe_compare(fn, "glVertexAttribI1i")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glVertexAttribI1ui")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttrib2f")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glVertexAttrib2s")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLshort).name());
					args.emplace_back("v1", typeid(GLshort).name());
				}
				else if(safe_compare(fn, "glVertexAttrib2d")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
				}
				else if(safe_compare(fn, "glVertexAttribI2i")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glVertexAttribI2ui")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLuint).name());
					args.emplace_back("v1", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttrib3f")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glVertexAttrib3s")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLshort).name());
					args.emplace_back("v1", typeid(GLshort).name());
					args.emplace_back("v2", typeid(GLshort).name());
				}
				else if(safe_compare(fn, "glVertexAttrib3d")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
					args.emplace_back("v2", typeid(GLdouble).name());
				}
				else if(safe_compare(fn, "glVertexAttribI3i")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glVertexAttribI3ui")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLuint).name());
					args.emplace_back("v1", typeid(GLuint).name());
					args.emplace_back("v2", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4f")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
					args.emplace_back("v3", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4s")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLshort).name());
					args.emplace_back("v1", typeid(GLshort).name());
					args.emplace_back("v2", typeid(GLshort).name());
					args.emplace_back("v3", typeid(GLshort).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4d")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
					args.emplace_back("v2", typeid(GLdouble).name());
					args.emplace_back("v3", typeid(GLdouble).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4Nub")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLubyte).name());
					args.emplace_back("v1", typeid(GLubyte).name());
					args.emplace_back("v2", typeid(GLubyte).name());
					args.emplace_back("v3", typeid(GLubyte).name());
				}
				else if(safe_compare(fn, "glVertexAttribI4i")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLint).name());
				}
				else if(safe_compare(fn, "glVertexAttribI4ui")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLuint).name());
					args.emplace_back("v1", typeid(GLuint).name());
					args.emplace_back("v2", typeid(GLuint).name());
					args.emplace_back("v3", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttribL1d")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
				}
				else if(safe_compare(fn, "glVertexAttribL2d")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
				}
				else if(safe_compare(fn, "glVertexAttribL3d")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
					args.emplace_back("v2", typeid(GLdouble).name());
				}
				else if(safe_compare(fn, "glVertexAttribL4d")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
					args.emplace_back("v2", typeid(GLdouble).name());
					args.emplace_back("v3", typeid(GLdouble).name());
				}
				else if(safe_compare(fn, "glVertexAttrib1fv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib1sv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib1dv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI1iv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI1uiv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib2fv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib2sv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib2dv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI2iv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI2uiv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib3fv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib3sv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib3dv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI3iv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI3uiv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4fv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4sv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4dv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4iv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4bv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLbyte *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4ubv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLubyte *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4usv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLushort *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4uiv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4Nbv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLbyte *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4Nsv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4Niv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4Nubv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLubyte *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4Nusv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLushort *).name());
				}
				else if(safe_compare(fn, "glVertexAttrib4Nuiv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI4bv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLbyte *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI4ubv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLubyte *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI4sv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI4usv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLushort *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI4iv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(safe_compare(fn, "glVertexAttribI4uiv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(safe_compare(fn, "glVertexAttribL1dv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glVertexAttribL2dv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glVertexAttribL3dv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glVertexAttribL4dv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(safe_compare(fn, "glVertexAttribP1ui")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttribP2ui")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttribP3ui")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttribP4ui")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttribDivisor")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("divisor", typeid(GLuint).name());
				}
				else if(safe_compare(fn, "glVertexAttribPointer")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("size", typeid(GLint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("stride", typeid(GLsizei).name());
					args.emplace_back("pointer", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glVertexAttribIPointer")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("size", typeid(GLint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("stride", typeid(GLsizei).name());
					args.emplace_back("pointer", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glVertexAttribLPointer")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("size", typeid(GLint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("stride", typeid(GLsizei).name());
					args.emplace_back("pointer", typeid(GLvoid *).name());
				}
				else if(safe_compare(fn, "glViewport")){
					ret = typeid(void).name();
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(safe_compare(fn, "glViewportArrayv")){
					ret = typeid(void).name();
					args.emplace_back("first", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glViewportIndexedf")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("x", typeid(GLfloat).name());
					args.emplace_back("y", typeid(GLfloat).name());
					args.emplace_back("w", typeid(GLfloat).name());
					args.emplace_back("h", typeid(GLfloat).name());
				}
				else if(safe_compare(fn, "glViewportIndexedfv")){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(safe_compare(fn, "glWaitSync")){
					ret = typeid(void).name();
					args.emplace_back("sync", typeid(GLsync).name());
					args.emplace_back("flags", typeid(GLbitfield).name());
					args.emplace_back("timeout", typeid(GLuint64).name());
				}
			}

			const char *ret = nullptr;
			std::vector<std::pair<std::string, const char*>> args;
	};
}

#endif // GAPI_KNOWN_HPP
