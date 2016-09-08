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
		public:
			known(const std::string &fn){
				if(fn == "glActiveShaderProgram"){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(fn == "glActiveTexture"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLenum).name());
				}
				else if(fn == "glAttachShader"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(fn == "glBeginConditionalRender"){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(fn == "glEndConditionalRender"){
					ret = typeid(void).name();
				}
				else if(fn == "glBeginQuery"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(fn == "glEndQuery"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(fn == "glBeginQueryIndexed"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(fn == "glEndQueryIndexed"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(fn == "glBeginTransformFeedback"){
					ret = typeid(void).name();
					args.emplace_back("primitiveMode", typeid(GLenum).name());
				}
				else if(fn == "glEndTransformFeedback"){
					ret = typeid(void).name();
				}
				else if(fn == "glBindAttribLocation"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(fn == "glBindBuffer"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(fn == "glBindBufferBase"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(fn == "glBindBufferRange"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("buffer", typeid(GLuint).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
				}
				else if(fn == "glBindFragDataLocation"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("colorNumber", typeid(GLuint).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(fn == "glBindFragDataLocationIndexed"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("colorNumber", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(fn == "glBindFramebuffer"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("framebuffer", typeid(GLuint).name());
				}
				else if(fn == "glBindProgramPipeline"){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
				}
				else if(fn == "glBindRenderbuffer"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("renderbuffer", typeid(GLuint).name());
				}
				else if(fn == "glBindSampler"){
					ret = typeid(void).name();
					args.emplace_back("unit", typeid(GLuint).name());
					args.emplace_back("sampler", typeid(GLuint).name());
				}
				else if(fn == "glBindTexture"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
				}
				else if(fn == "glBindTransformFeedback"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(fn == "glBindVertexArray"){
					ret = typeid(void).name();
					args.emplace_back("array", typeid(GLuint).name());
				}
				else if(fn == "glBlendColor"){
					ret = typeid(void).name();
					args.emplace_back("red", typeid(GLclampf).name());
					args.emplace_back("green", typeid(GLclampf).name());
					args.emplace_back("blue", typeid(GLclampf).name());
					args.emplace_back("alpha", typeid(GLclampf).name());
				}
				else if(fn == "glBlendEquation"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(fn == "glBlendEquationi"){
					ret = typeid(void).name();
					args.emplace_back("buf", typeid(GLuint).name());
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(fn == "glBlendEquationSeparate"){
					ret = typeid(void).name();
					args.emplace_back("modeRGB", typeid(GLenum).name());
					args.emplace_back("modeAlpha", typeid(GLenum).name());
				}
				else if(fn == "glBlendEquationSeparatei"){
					ret = typeid(void).name();
					args.emplace_back("buf", typeid(GLuint).name());
					args.emplace_back("modeRGB", typeid(GLenum).name());
					args.emplace_back("modeAlpha", typeid(GLenum).name());
				}
				else if(fn == "glBlendFunc"){
					ret = typeid(void).name();
					args.emplace_back("sfactor", typeid(GLenum).name());
					args.emplace_back("dfactor", typeid(GLenum).name());
				}
				else if(fn == "glBlendFunci"){
					ret = typeid(void).name();
					args.emplace_back("buf", typeid(GLuint).name());
					args.emplace_back("sfactor", typeid(GLenum).name());
					args.emplace_back("dfactor", typeid(GLenum).name());
				}
				else if(fn == "glBlendFuncSeparate"){
					ret = typeid(void).name();
					args.emplace_back("srcRGB", typeid(GLenum).name());
					args.emplace_back("dstRGB", typeid(GLenum).name());
					args.emplace_back("srcAlpha", typeid(GLenum).name());
					args.emplace_back("dstAlpha", typeid(GLenum).name());
				}
				else if(fn == "glBlendFuncSeparatei"){
					ret = typeid(void).name();
					args.emplace_back("buf", typeid(GLuint).name());
					args.emplace_back("srcRGB", typeid(GLenum).name());
					args.emplace_back("dstRGB", typeid(GLenum).name());
					args.emplace_back("srcAlpha", typeid(GLenum).name());
					args.emplace_back("dstAlpha", typeid(GLenum).name());
				}
				else if(fn == "glBlitFramebuffer"){
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
				else if(fn == "glBufferData"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
					args.emplace_back("data", typeid(const GLvoid *).name());
					args.emplace_back("usage", typeid(GLenum).name());
				}
				else if(fn == "glBufferSubData"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(fn == "glNamedBufferSubData"){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLuint).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizei).name());
					args.emplace_back("data", typeid(const void *).name());
				}
				else if(fn == "glBufferStorage"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
					args.emplace_back("data", typeid(const GLvoid *).name());
					args.emplace_back("flags", typeid(GLbitfield).name());
				}
				else if(fn == "glNamedBufferStorage"){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLuint).name());
					args.emplace_back("size", typeid(GLsizei).name());
					args.emplace_back("data", typeid(const void*).name());
					args.emplace_back("flags", typeid(GLbitfield).name());
				}
				else if(fn == "glCheckFramebufferStatus"){
					ret = typeid(GLenum).name();
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(fn == "glClampColor"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("clamp", typeid(GLenum).name());
				}
				else if(fn == "glClear"){
					ret = typeid(void).name();
					args.emplace_back("mask", typeid(GLbitfield).name());
				}
				else if(fn == "glClearBufferiv"){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLenum).name());
					args.emplace_back("drawBuffer", typeid(GLint).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(fn == "glClearBufferuiv"){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLenum).name());
					args.emplace_back("drawBuffer", typeid(GLint).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(fn == "glClearBufferfv"){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLenum).name());
					args.emplace_back("drawBuffer", typeid(GLint).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glClearBufferfi"){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLenum).name());
					args.emplace_back("drawBuffer", typeid(GLint).name());
					args.emplace_back("depth", typeid(GLfloat).name());
					args.emplace_back("stencil", typeid(GLint).name());
				}
				else if(fn == "glClearColor"){
					ret = typeid(void).name();
					args.emplace_back("red", typeid(GLclampf).name());
					args.emplace_back("green", typeid(GLclampf).name());
					args.emplace_back("blue", typeid(GLclampf).name());
					args.emplace_back("alpha", typeid(GLclampf).name());
				}
				else if(fn == "glClearDepth"){
					ret = typeid(void).name();
					args.emplace_back("depth", typeid(GLclampd).name());
				}
				else if(fn == "glClearDepthf"){
					ret = typeid(void).name();
					args.emplace_back("depth", typeid(GLclampf).name());
				}
				else if(fn == "glClearStencil"){
					ret = typeid(void).name();
					args.emplace_back("s", typeid(GLint).name());
				}
				else if(fn == "glClientWaitSync"){
					ret = typeid(GLenum).name();
					args.emplace_back("sync", typeid(GLsync).name());
					args.emplace_back("flags", typeid(GLbitfield).name());
					args.emplace_back("timeout", typeid(GLuint64).name());
				}
				else if(fn == "glColorMask"){
					ret = typeid(void).name();
					args.emplace_back("red", typeid(GLboolean).name());
					args.emplace_back("green", typeid(GLboolean).name());
					args.emplace_back("blue", typeid(GLboolean).name());
					args.emplace_back("alpha", typeid(GLboolean).name());
				}
				else if(fn == "glCompileShader"){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(fn == "glCompressedTexImage1D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
					args.emplace_back("imageSize", typeid(GLsizei).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(fn == "glCompressedTexImage2D"){
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
				else if(fn == "glCompressedTexImage3D"){
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
				else if(fn == "glCompressedTexSubImage1D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("imageSize", typeid(GLsizei).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(fn == "glCompressedTexSubImage2D"){
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
				else if(fn == "glCompressedTexSubImage3D"){
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
				else if(fn == "glCopyBufferSubData"){
					ret = typeid(void).name();
					args.emplace_back("readtarget", typeid(GLenum).name());
					args.emplace_back("writetarget", typeid(GLenum).name());
					args.emplace_back("readoffset", typeid(GLintptr).name());
					args.emplace_back("writeoffset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
				}
				else if(fn == "glCopyTexImage1D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("border", typeid(GLint).name());
				}
				else if(fn == "glCopyTexImage2D"){
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
				else if(fn == "glCopyTexSubImage1D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
				}
				else if(fn == "glCopyTexSubImage2D"){
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
				else if(fn == "glCopyTexSubImage3D"){
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
				else if(fn == "glCreateProgram"){
					ret = typeid(GLuint).name();
				}
				else if(fn == "glCreateShader"){
					ret = typeid(GLuint).name();
					args.emplace_back("shaderType", typeid(GLenum).name());
				}
				else if(fn == "glCreateShaderProgramv"){
					ret = typeid(GLuint).name();
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("strings", typeid(char **).name());
				}
				else if(fn == "glCullFace"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(fn == "glDeleteBuffers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("buffers", typeid(GLuint *).name());
				}
				else if(fn == "glDeleteFramebuffers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("framebuffers", typeid(GLuint *).name());
				}
				else if(fn == "glDeleteProgram"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(fn == "glDeleteProgramPipelines"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("pipelines", typeid(GLuint *).name());
				}
				else if(fn == "glDeleteQueries"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(fn == "glDeleteRenderbuffers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("renderbuffers", typeid(GLuint *).name());
				}
				else if(fn == "glDeleteSamplers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(fn == "glDeleteShader"){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(fn == "glDeleteSync"){
					ret = typeid(void).name();
					args.emplace_back("sync", typeid(GLsync).name());
				}
				else if(fn == "glDeleteTextures"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("textures", typeid(GLuint *).name());
				}
				else if(fn == "glDeleteTransformFeedbacks"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(fn == "glDeleteVertexArrays"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("arrays", typeid(GLuint *).name());
				}
				else if(fn == "glDepthFunc"){
					ret = typeid(void).name();
					args.emplace_back("func", typeid(GLenum).name());
				}
				else if(fn == "glDepthMask"){
					ret = typeid(void).name();
					args.emplace_back("flag", typeid(GLboolean).name());
				}
				else if(fn == "glDepthRange"){
					ret = typeid(void).name();
					args.emplace_back("nearVal", typeid(GLclampd).name());
					args.emplace_back("farVal", typeid(GLclampd).name());
				}
				else if(fn == "glDepthRangef"){
					ret = typeid(void).name();
					args.emplace_back("nearVal", typeid(GLclampf).name());
					args.emplace_back("farVal", typeid(GLclampf).name());
				}
				else if(fn == "glDepthRangeArrayv"){
					ret = typeid(void).name();
					args.emplace_back("first", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("v", typeid(GLclampd *).name());
				}
				else if(fn == "glDepthRangeIndexed"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("nearVal", typeid(GLclampd).name());
					args.emplace_back("farVal", typeid(GLclampd).name());
				}
				else if(fn == "glDetachShader"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(fn == "glDrawArrays"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("first", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
				}
				else if(fn == "glDrawArraysIndirect"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("indirect", typeid(void *).name());
				}
				else if(fn == "glDrawArraysInstanced"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("first", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
				}
				else if(fn == "glDrawBuffer"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(fn == "glDrawBuffers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("bufs", typeid(GLenum *).name());
				}
				else if(fn == "glDrawElements"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
				}
				else if(fn == "glDrawElementsBaseVertex"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
					args.emplace_back("basevertex", typeid(GLint).name());
				}
				else if(fn == "glDrawElementsIndirect"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indirect", typeid(void *).name());
				}
				else if(fn == "glDrawElementsInstanced"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(void *).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
				}
				else if(fn == "glDrawElementsInstancedBaseVertex"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
					args.emplace_back("basevertex", typeid(GLint).name());
				}
				else if(fn == "glDrawRangeElements"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("start", typeid(GLuint).name());
					args.emplace_back("end", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
				}
				else if(fn == "glDrawRangeElementsBaseVertex"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("start", typeid(GLuint).name());
					args.emplace_back("end", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid *).name());
					args.emplace_back("basevertex", typeid(GLint).name());
				}
				else if(fn == "glDrawTransformFeedback"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(fn == "glDrawTransformFeedbackStream"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("stream", typeid(GLuint).name());
				}
				else if(fn == "glEnable"){
					ret = typeid(void).name();
					args.emplace_back("cap", typeid(GLenum).name());
				}
				else if(fn == "glDisable"){
					ret = typeid(void).name();
					args.emplace_back("cap", typeid(GLenum).name());
				}
				else if(fn == "glEnablei"){
					ret = typeid(void).name();
					args.emplace_back("cap", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(fn == "glDisablei"){
					ret = typeid(void).name();
					args.emplace_back("cap", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(fn == "glEnableVertexAttribArray"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(fn == "glDisableVertexAttribArray"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(fn == "glEnableVertexArrayAttrib"){
					ret = typeid(void).name();
					args.emplace_back("vaobj", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(fn == "glDisableVertexArrayAttrib"){
					ret = typeid(void).name();
					args.emplace_back("vaobj", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(fn == "glFenceSync"){
					ret = typeid(GLsync).name();
					args.emplace_back("condition", typeid(GLenum).name());
					args.emplace_back("flags", typeid(GLbitfield).name());
				}
				else if(fn == "glFinish"){
					ret = typeid(void).name();
				}
				else if(fn == "glFlush"){
					ret = typeid(void).name();
				}
				else if(fn == "glFlushMappedBufferRange"){
					ret = typeid(GLsync).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("length", typeid(GLsizeiptr).name());
				}
				else if(fn == "glFramebufferRenderbuffer"){
					ret = typeid(GLsync).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("renderbuffertarget", typeid(GLenum).name());
					args.emplace_back("renderbuffer", typeid(GLuint).name());
				}
				else if(fn == "glFramebufferTexture"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
				}
				else if(fn == "glFramebufferTexture1D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("textarget", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
				}
				else if(fn == "glFramebufferTexture2D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("textarget", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
				}
				else if(fn == "glFramebufferTexture3D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("textarget", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("layer", typeid(GLint).name());
				}
				else if(fn == "glFramebufferTextureLayer"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("layer", typeid(GLint).name());
				}
				else if(fn == "glFrontFace"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(fn == "glGenBuffers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("buffers", typeid(GLuint *).name());
				}
				else if(fn == "glCreateBuffers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("buffers", typeid(GLuint *).name());
				}
				else if(fn == "glGenFramebuffers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(fn == "glGenProgramPipelines"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("pipelines", typeid(GLuint *).name());
				}
				else if(fn == "glGenQueries"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(fn == "glGenRenderbuffers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("renderbuffers", typeid(GLuint *).name());
				}
				else if(fn == "glGenSamplers"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("samplers", typeid(GLuint *).name());
				}
				else if(fn == "glGenTextures"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("textures", typeid(GLuint *).name());
				}
				else if(fn == "glGenTransformFeedbacks"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("ids", typeid(GLuint *).name());
				}
				else if(fn == "glGenVertexArrays"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("arrays", typeid(GLuint *).name());
				}
				else if(fn == "glGenerateMipmap"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(fn == "glGenerateTextureMipmap"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLuint).name());
				}
				else if(fn == "glGetBooleanv"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLboolean *).name());
				}
				else if(fn == "glGetDoublev"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLdouble *).name());
				}
				else if(fn == "glGetFloatv"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(fn == "glGetIntegerv"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetInteger64v"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint64 *).name());
				}
				else if(fn == "glGetBooleani_v"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("data", typeid(GLboolean *).name());
				}
				else if(fn == "glGetIntegeri_v"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("data", typeid(GLint *).name());
				}
				else if(fn == "glGetInteger64i_v"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("data", typeid(GLint64 *).name());
				}
				else if(fn == "glGetActiveAttrib"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("size", typeid(GLint *).name());
					args.emplace_back("type", typeid(GLenum *).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(fn == "glGetActiveSubroutineName"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufsize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(fn == "glGetActiveSubroutineUniformiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("values", typeid(GLint *).name());
				}
				else if(fn == "glGetActiveSubroutineUniformName"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufsize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(fn == "glGetActiveUniform"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("size", typeid(GLint *).name());
					args.emplace_back("type", typeid(GLenum *).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(fn == "glGetActiveUniformBlockiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformBlockIndex", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint).name());
				}
				else if(fn == "glGetActiveUniformBlockName"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformBlockIndex", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("uniformBlockName", typeid(GLchar *).name());
				}
				else if(fn == "glGetActiveUniformName"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformIndex", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("uniformName", typeid(GLchar *).name());
				}
				else if(fn == "glGetActiveUniformsiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformCount", typeid(GLsizei).name());
					args.emplace_back("uniformIndices", typeid(GLuint *).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetAttachedShaders"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("maxCount", typeid(GLsizei).name());
					args.emplace_back("count", typeid(GLsizei *).name());
					args.emplace_back("shaders", typeid(GLuint *).name());
				}
				else if(fn == "glGetAttribLocation"){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(fn == "glGetBufferParameteriv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("value", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLint *).name());
				}
				else if(fn == "glGetBufferPointerv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLvoid **).name());
				}
				else if(fn == "glGetBufferSubData"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizeiptr).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(fn == "glGetNamedBufferSubData"){
					ret = typeid(void).name();
					args.emplace_back("buffer", typeid(GLuint).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("size", typeid(GLsizei).name());
					args.emplace_back("data", typeid(void *).name());
				}
				else if(fn == "glGetCompressedTexImage"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("lod", typeid(GLint).name());
					args.emplace_back("img", typeid(GLvoid *).name());
				}
				else if(fn == "glGetError"){
					ret = typeid(GLenum).name();
				}
				else if(fn == "glGetFragDataIndex"){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(fn == "glGetFragDataLocation"){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(fn == "glGetFramebufferAttachmentParameter"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("attachment", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetMultisamplefv"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("val", typeid(GLfloat *).name());
				}
				else if(fn == "glGetProgramiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetProgramBinary"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("bufsize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("binaryFormat", typeid(GLenum *).name());
					args.emplace_back("binary", typeid(void *).name());
				}
				else if(fn == "glGetProgramInfoLog"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("maxLength", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("infoLog", typeid(GLchar *).name());
				}
				else if(fn == "glGetProgramPipelineiv"){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetProgramPipelineInfoLog"){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("infoLog", typeid(GLchar *).name());
				}
				else if(fn == "glGetProgramStageiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("values", typeid(GLint *).name());
				}
				else if(fn == "glGetQueryIndexediv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetQueryObjectiv"){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetQueryObjectuiv"){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLuint *).name());
				}
				else if(fn == "glGetQueryObjecti64v"){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint64 *).name());
				}
				else if(fn == "glGetQueryObjectui64v"){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLuint64 *).name());
				}
				else if(fn == "glGetQueryiv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetRenderbufferParameteriv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetSamplerParameterfv"){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(fn == "glGetSamplerParameteriv"){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetShaderiv"){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetShaderInfoLog"){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
					args.emplace_back("maxLength", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("infoLog", typeid(GLchar *).name());
				}
				else if(fn == "glGetShaderPrecisionFormat"){
					ret = typeid(void).name();
					args.emplace_back("shaderType", typeid(GLenum).name());
					args.emplace_back("precisionType", typeid(GLenum).name());
					args.emplace_back("range", typeid(GLint *).name());
					args.emplace_back("precision", typeid(GLint *).name());
				}
				else if(fn == "glGetShaderSource"){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("source", typeid(GLchar *).name());
				}
				else if(fn == "glGetString"){
					ret = typeid(GLubyte*).name();
					args.emplace_back("name", typeid(GLenum).name());
				}
				else if(fn == "glGetStringi"){
					ret = typeid(GLubyte*).name();
					args.emplace_back("name", typeid(GLenum).name());
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(fn == "glGetSubroutineIndex"){
					ret = typeid(GLuint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(fn == "glGetSubroutineUniformLocation"){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("name", typeid(GLchar *).name());
				}
				else if(fn == "glGetSynciv"){
					ret = typeid(void).name();
					args.emplace_back("sync", typeid(GLsync).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("values", typeid(GLint *).name());
				}
				else if(fn == "glGetTexImage"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("img", typeid(GLvoid *).name());
				}
				else if(fn == "glGetTexLevelParameterfv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(fn == "glGetTexLevelParameteriv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetTexParameterfv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(fn == "glGetTexParameteriv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetTransformFeedbackVarying"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("bufSize", typeid(GLsizei).name());
					args.emplace_back("length", typeid(GLsizei *).name());
					args.emplace_back("size", typeid(GLsizei).name());
					args.emplace_back("type", typeid(GLenum *).name());
					args.emplace_back("name", typeid(char *).name());
				}
				else if(fn == "glGetUniformfv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(fn == "glGetUniformiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetUniformBlockIndex"){
					ret = typeid(GLuint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformBlockName", typeid(GLchar *).name());
				}
				else if(fn == "glGetUniformIndices"){
					ret = typeid(GLuint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformCount", typeid(GLsizei).name());
					args.emplace_back("uniformNames", typeid(GLchar **).name());
					args.emplace_back("uniformIndices", typeid(GLuint *).name());
				}
				else if(fn == "glGetUniformLocation"){
					ret = typeid(GLint).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("name", typeid(const GLchar *).name());
				}
				else if(fn == "glGetUniformSubroutineuiv"){
					ret = typeid(void).name();
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("values", typeid(GLuint *).name());
				}
				else if(fn == "glGetVertexAttribdv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLdouble *).name());
				}
				else if(fn == "glGetVertexAttribfv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(fn == "glGetVertexAttribiv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetVertexAttribIiv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glGetVertexAttribIuiv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLuint *).name());
				}
				else if(fn == "glGetVertexAttribLdv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLdouble *).name());
				}
				else if(fn == "glGetVertexAttribPointerv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("pointer", typeid(GLvoid **).name());
				}
				else if(fn == "glHint"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(fn == "glIsBuffer"){
					ret = typeid(GLboolean).name();
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(fn == "glIsEnabled"){
					ret = typeid(GLboolean).name();
					args.emplace_back("cap", typeid(GLenum).name());
				}
				else if(fn == "glIsFramebuffer"){
					ret = typeid(GLboolean).name();
					args.emplace_back("framebuffer", typeid(GLuint).name());
				}
				else if(fn == "glIsProgram"){
					ret = typeid(GLboolean).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(fn == "glIsProgramPipeline"){
					ret = typeid(GLboolean).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
				}
				else if(fn == "glIsQuery"){
					ret = typeid(GLboolean).name();
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(fn == "glIsRenderbuffer"){
					ret = typeid(GLboolean).name();
					args.emplace_back("renderbuffer", typeid(GLuint).name());
				}
				else if(fn == "glIsSampler"){
					ret = typeid(GLboolean).name();
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(fn == "glIsShader"){
					ret = typeid(GLboolean).name();
					args.emplace_back("shader", typeid(GLuint).name());
				}
				else if(fn == "glIsSync"){
					ret = typeid(GLboolean).name();
					args.emplace_back("sync", typeid(GLsync).name());
				}
				else if(fn == "glIsTexture"){
					ret = typeid(GLboolean).name();
					args.emplace_back("texture", typeid(GLuint).name());
				}
				else if(fn == "glIsTransformFeedback"){
					ret = typeid(GLboolean).name();
					args.emplace_back("id", typeid(GLuint).name());
				}
				else if(fn == "glIsVertexArray"){
					ret = typeid(GLboolean).name();
					args.emplace_back("array", typeid(GLuint).name());
				}
				else if(fn == "glLineWidth"){
					ret = typeid(void).name();
					args.emplace_back("width", typeid(GLfloat).name());
				}
				else if(fn == "glLinkProgram"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(fn == "glLogicOp"){
					ret = typeid(void).name();
					args.emplace_back("opcode", typeid(GLenum).name());
				}
				else if(fn == "glMapBuffer"){
					ret = typeid(void *).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("access", typeid(GLenum).name());
				}
				else if(fn == "glMapNamedBuffer"){
					ret = typeid(void *).name();
					args.emplace_back("buffer", typeid(GLuint).name());
					args.emplace_back("access", typeid(GLenum).name());
				}
				else if(fn == "glUnmapBuffer"){
					ret = typeid(GLboolean).name();
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(fn == "glUnmapNamedBuffer"){
					ret = typeid(GLboolean).name();
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(fn == "glMapBufferRange"){
					ret = typeid(void *).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("length", typeid(GLsizeiptr).name());
					args.emplace_back("access", typeid(GLbitfield).name());
				}
				else if(fn == "glMapNamedBufferRange"){
					ret = typeid(void *).name();
					args.emplace_back("buffer", typeid(GLuint).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("length", typeid(GLsizei).name());
					args.emplace_back("access", typeid(GLbitfield).name());
				}
				else if(fn == "glMinSampleShading"){
					ret = typeid(void).name();
					args.emplace_back("value", typeid(GLclampf).name());
				}
				else if(fn == "glMultiDrawArrays"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("first", typeid(GLint *).name());
					args.emplace_back("count", typeid(GLsizei *).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
				}
				else if(fn == "glMultiDrawElements"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei *).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid **).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
				}
				else if(fn == "glMultiDrawElementsBaseVertex"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei *).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("indices", typeid(GLvoid **).name());
					args.emplace_back("primcount", typeid(GLsizei).name());
					args.emplace_back("basevertex", typeid(GLint *).name());
				}
				else if(fn == "glPatchParameteri"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("value", typeid(GLint).name());
				}
				else if(fn == "glPatchParameterfv"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("values", typeid(GLfloat *).name());
				}
				else if(fn == "glPauseTransformFeedback"){
					ret = typeid(void).name();
				}
				else if(fn == "glPixelStoref"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLfloat).name());
				}
				else if(fn == "glPixelStorei"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLint).name());
				}
				else if(fn == "glPointParameterf"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLfloat).name());
				}
				else if(fn == "glPointParameteri"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLint).name());
				}
				else if(fn == "glPointParameterfv"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(fn == "glPointParameteriv"){
					ret = typeid(void).name();
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glPointSize"){
					ret = typeid(void).name();
					args.emplace_back("size", typeid(GLfloat).name());
				}
				else if(fn == "glPolygonMode"){
					ret = typeid(void).name();
					args.emplace_back("face", typeid(GLenum).name());
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(fn == "glPolygonOffset"){
					ret = typeid(void).name();
					args.emplace_back("factor", typeid(GLfloat).name());
					args.emplace_back("units", typeid(GLfloat).name());
				}
				else if(fn == "glPrimitiveRestartIndex"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
				}
				else if(fn == "glProgramBinary"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("binaryFormat", typeid(GLenum).name());
					args.emplace_back("binary", typeid(void *).name());
					args.emplace_back("length", typeid(GLsizei).name());
				}
				else if(fn == "glProgramParameteri"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("value", typeid(GLint).name());
				}
				else if(fn == "glProgramUniform1f"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
				}
				else if(fn == "glProgramUniform2f"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
				}
				else if(fn == "glProgramUniform3f"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
				}
				else if(fn == "glProgramUniform4f"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
					args.emplace_back("v3", typeid(GLfloat).name());
				}
				else if(fn == "glProgramUniform1i"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
				}
				else if(fn == "glProgramUniform2i"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
				}
				else if(fn == "glProgramUniform3i"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
				}
				else if(fn == "glProgramUniform4i"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLint).name());
				}
				else if(fn == "glProgramUniform1ui"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLuint).name());
				}
				else if(fn == "glProgramUniform2ui"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLuint).name());
				}
				else if(fn == "glProgramUniform3ui"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLuint).name());
				}
				else if(fn == "glProgramUniform4ui"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLuint).name());
				}
				else if(fn == "glProgramUniform1fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniform2fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniform3fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniform4fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniform1iv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(fn == "glProgramUniform2iv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(fn == "glProgramUniform3iv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(fn == "glProgramUniform4iv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLint *).name());
				}
				else if(fn == "glProgramUniform1uiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(fn == "glProgramUniform2uiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(fn == "glProgramUniform3uiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(fn == "glProgramUniform4uiv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(GLuint *).name());
				}
				else if(fn == "glProgramUniformMatrix2fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniformMatrix3fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniformMatrix4fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniformMatrix2x3fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniformMatrix3x2fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniformMatrix2x4fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniformMatrix4x2fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniformMatrix3x4fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProgramUniformMatrix4x3fv"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLfloat *).name());
				}
				else if(fn == "glProvokingVertex"){
					ret = typeid(void).name();
					args.emplace_back("provokeMode", typeid(GLenum).name());
				}
				else if(fn == "glQueryCounter"){
					ret = typeid(void).name();
					args.emplace_back("id", typeid(GLuint).name());
					args.emplace_back("target", typeid(GLenum).name());
				}
				else if(fn == "glReadBuffer"){
					ret = typeid(void).name();
					args.emplace_back("mode", typeid(GLenum).name());
				}
				else if(fn == "glReadPixels"){
					ret = typeid(void).name();
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("data", typeid(GLvoid *).name());
				}
				else if(fn == "glReleaseShaderCompiler"){
					ret = typeid(void).name();
				}
				else if(fn == "glRenderbufferStorage"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(fn == "glRenderbufferStorageMultisample"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(fn == "glResumeTransformFeedback"){
					ret = typeid(void).name();
				}
				else if(fn == "glSampleCoverage"){
					ret = typeid(void).name();
					args.emplace_back("value", typeid(GLclampf).name());
					args.emplace_back("invert", typeid(GLboolean).name());
				}
				else if(fn == "glSampleMaski"){
					ret = typeid(void).name();
					args.emplace_back("maskNumber", typeid(GLuint).name());
					args.emplace_back("mask", typeid(GLbitfield).name());
				}
				else if(fn == "glSamplerParameterf"){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLfloat).name());
				}
				else if(fn == "glSamplerParameteri"){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLint).name());
				}
				else if(fn == "glSamplerParameterfv"){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(fn == "glSamplerParameteriv"){
					ret = typeid(void).name();
					args.emplace_back("sampler", typeid(GLuint).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glScissor"){
					ret = typeid(void).name();
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(fn == "glScissorArrayv"){
					ret = typeid(void).name();
					args.emplace_back("first", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(fn == "glScissorIndexed"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("left", typeid(GLint).name());
					args.emplace_back("bottom", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(fn == "glScissorIndexedv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(fn == "glShaderBinary"){
					ret = typeid(void).name();
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("shaders", typeid(GLuint *).name());
					args.emplace_back("binaryFormat", typeid(GLenum).name());
					args.emplace_back("binary", typeid(void *).name());
					args.emplace_back("length", typeid(GLsizei).name());
				}
				else if(fn == "glShaderSource"){
					ret = typeid(void).name();
					args.emplace_back("shader", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("string", typeid(const GLchar **).name());
					args.emplace_back("length", typeid(GLint *).name());
				}
				else if(fn == "glStencilFunc"){
					ret = typeid(void).name();
					args.emplace_back("func", typeid(GLenum).name());
					args.emplace_back("_ref", typeid(GLint).name());
					args.emplace_back("mask", typeid(GLuint).name());
				}
				else if(fn == "glStencilFuncSeparate"){
					ret = typeid(void).name();
					args.emplace_back("face", typeid(GLenum).name());
					args.emplace_back("func", typeid(GLenum).name());
					args.emplace_back("_ref", typeid(GLint).name());
					args.emplace_back("mask", typeid(GLuint).name());
				}
				else if(fn == "glStencilMask"){
					ret = typeid(void).name();
					args.emplace_back("mask", typeid(GLuint).name());
				}
				else if(fn == "glStencilMaskSeparate"){
					ret = typeid(void).name();
					args.emplace_back("face", typeid(GLenum).name());
					args.emplace_back("mask", typeid(GLuint).name());
				}
				else if(fn == "glStencilOp"){
					ret = typeid(void).name();
					args.emplace_back("sfail", typeid(GLenum).name());
					args.emplace_back("dpfail", typeid(GLenum).name());
					args.emplace_back("dppass", typeid(GLenum).name());
				}
				else if(fn == "glStencilOpSeparate"){
					ret = typeid(void).name();
					args.emplace_back("face", typeid(GLenum).name());
					args.emplace_back("sfail", typeid(GLenum).name());
					args.emplace_back("dpfail", typeid(GLenum).name());
					args.emplace_back("dppass", typeid(GLenum).name());
				}
				else if(fn == "glTexBuffer"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("internalFormat", typeid(GLenum).name());
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(fn == "glTexImage1D"){
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
				else if(fn == "glTexImage2D"){
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
				else if(fn == "glTexImage2DMultisample"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("fixedsamplelocations", typeid(GLboolean).name());
				}
				else if(fn == "glTexImage3D"){
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
				else if(fn == "glTexImage3DMultisample"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
					args.emplace_back("fixedsamplelocations", typeid(GLboolean).name());
				}
				else if(fn == "glTexParameterf"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLfloat).name());
				}
				else if(fn == "glTexParameteri"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("param", typeid(GLint).name());
				}
				else if(fn == "glTexParameterfv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLfloat *).name());
				}
				else if(fn == "glTexParameteriv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glTexParameterIiv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLint *).name());
				}
				else if(fn == "glTexParameterIuiv"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("pname", typeid(GLenum).name());
					args.emplace_back("params", typeid(GLuint *).name());
				}
				else if(fn == "glTexSubImage1D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("pixels", typeid(const GLvoid *).name());
				}
				else if(fn == "glTextureSubImage1D"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("pixels", typeid(const void *).name());
				}
				else if(fn == "glTexSubImage2D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("yoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("pixels", typeid(GLvoid *).name());
				}
				else if(fn == "glTextureSubImage2D"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("yoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("pixels", typeid(const void *).name());
				}
				else if(fn == "glTexSubImage3D"){
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
					args.emplace_back("pixels", typeid(const GLvoid *).name());
				}
				else if(fn == "glTextureSubImage3D"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("level", typeid(GLint).name());
					args.emplace_back("xoffset", typeid(GLint).name());
					args.emplace_back("yoffset", typeid(GLint).name());
					args.emplace_back("zoffset", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
					args.emplace_back("format", typeid(GLenum).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("pixels", typeid(const void *).name());
				}
				else if(fn == "glTexStorage1D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("levels", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
				}
				else if(fn == "glTextureStorage1D"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("levels", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
				}
				else if(fn == "glTexStorage2D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("levels", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(fn == "glTextureStorage2D"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("levels", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(fn == "glTexStorage3D"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("levels", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
				}
				else if(fn == "glTextureStorage3D"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("levels", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
				}
				else if(fn == "glTexStorage2DMultisample"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("fixedsamplelocations", typeid(GLboolean).name());
				}
				else if(fn == "glTextureStorage2DMultisample"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("fixedsamplelocations", typeid(GLboolean).name());
				}
				else if(fn == "glTexStorage3DMultisample"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
					args.emplace_back("fixedsamplelocations", typeid(GLboolean).name());
				}
				else if(fn == "glTextureStorage3DMultisample"){
					ret = typeid(void).name();
					args.emplace_back("texture", typeid(GLuint).name());
					args.emplace_back("samples", typeid(GLsizei).name());
					args.emplace_back("internalformat", typeid(GLenum).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
					args.emplace_back("depth", typeid(GLsizei).name());
					args.emplace_back("fixedsamplelocations", typeid(GLboolean).name());
				}
				else if(fn == "glTransformFeedbackVaryings"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("varyings", typeid(char **).name());
					args.emplace_back("bufferMode", typeid(GLenum).name());
				}
				else if(fn == "glUniform1f"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
				}
				else if(fn == "glUniform2f"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
				}
				else if(fn == "glUniform3f"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
				}
				else if(fn == "glUniform4f"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
					args.emplace_back("v3", typeid(GLfloat).name());
				}
				else if(fn == "glUniform1i"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
				}
				else if(fn == "glUniform2i"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
				}
				else if(fn == "glUniform3i"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
				}
				else if(fn == "glUniform4i"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLint).name());
				}
				else if(fn == "glUniform1ui"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLuint).name());
				}
				else if(fn == "glUniform2ui"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLuint).name());
				}
				else if(fn == "glUniform3ui"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLuint).name());
				}
				else if(fn == "glUniform4ui"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLuint).name());
				}
				else if(fn == "glUniform1fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniform2fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniform3fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniform4fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniform1iv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLint *).name());
				}
				else if(fn == "glUniform2iv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLint *).name());
				}
				else if(fn == "glUniform3iv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLint *).name());
				}
				else if(fn == "glUniform4iv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLint *).name());
				}
				else if(fn == "glUniform1uiv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLuint *).name());
				}
				else if(fn == "glUniform2uiv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLuint *).name());
				}
				else if(fn == "glUniform3uiv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLuint *).name());
				}
				else if(fn == "glUniform4uiv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("value", typeid(const GLuint *).name());
				}
				else if(fn == "glUniformMatrix2fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniformMatrix3fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniformMatrix4fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniformMatrix2x3fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniformMatrix3x2fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniformMatrix2x4fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniformMatrix4x2fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniformMatrix3x4fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniformMatrix4x3fv"){
					ret = typeid(void).name();
					args.emplace_back("location", typeid(GLint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("transpose", typeid(GLboolean).name());
					args.emplace_back("value", typeid(const GLfloat *).name());
				}
				else if(fn == "glUniformBlockBinding"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
					args.emplace_back("uniformBlockIndex", typeid(GLuint).name());
					args.emplace_back("uniformBlockBinding", typeid(GLuint).name());
				}
				else if(fn == "glUniformSubroutinesuiv"){
					ret = typeid(void).name();
					args.emplace_back("shadertype", typeid(GLenum).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("indices", typeid(GLuint *).name());
				}
				else if(fn == "glUseProgram"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(fn == "glUseProgramStages"){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
					args.emplace_back("stages", typeid(GLbitfield).name());
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(fn == "glValidateProgram"){
					ret = typeid(void).name();
					args.emplace_back("program", typeid(GLuint).name());
				}
				else if(fn == "glValidateProgramPipeline"){
					ret = typeid(void).name();
					args.emplace_back("pipeline", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttrib1f"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
				}
				else if(fn == "glVertexAttrib1s"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLshort).name());
				}
				else if(fn == "glVertexAttrib1d"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
				}
				else if(fn == "glVertexAttribI1i"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLint).name());
				}
				else if(fn == "glVertexAttribI1ui"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttrib2f"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
				}
				else if(fn == "glVertexAttrib2s"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLshort).name());
					args.emplace_back("v1", typeid(GLshort).name());
				}
				else if(fn == "glVertexAttrib2d"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
				}
				else if(fn == "glVertexAttribI2i"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
				}
				else if(fn == "glVertexAttribI2ui"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLuint).name());
					args.emplace_back("v1", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttrib3f"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
				}
				else if(fn == "glVertexAttrib3s"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLshort).name());
					args.emplace_back("v1", typeid(GLshort).name());
					args.emplace_back("v2", typeid(GLshort).name());
				}
				else if(fn == "glVertexAttrib3d"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
					args.emplace_back("v2", typeid(GLdouble).name());
				}
				else if(fn == "glVertexAttribI3i"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
				}
				else if(fn == "glVertexAttribI3ui"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLuint).name());
					args.emplace_back("v1", typeid(GLuint).name());
					args.emplace_back("v2", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttrib4f"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLfloat).name());
					args.emplace_back("v1", typeid(GLfloat).name());
					args.emplace_back("v2", typeid(GLfloat).name());
					args.emplace_back("v3", typeid(GLfloat).name());
				}
				else if(fn == "glVertexAttrib4s"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLshort).name());
					args.emplace_back("v1", typeid(GLshort).name());
					args.emplace_back("v2", typeid(GLshort).name());
					args.emplace_back("v3", typeid(GLshort).name());
				}
				else if(fn == "glVertexAttrib4d"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
					args.emplace_back("v2", typeid(GLdouble).name());
					args.emplace_back("v3", typeid(GLdouble).name());
				}
				else if(fn == "glVertexAttrib4Nub"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLubyte).name());
					args.emplace_back("v1", typeid(GLubyte).name());
					args.emplace_back("v2", typeid(GLubyte).name());
					args.emplace_back("v3", typeid(GLubyte).name());
				}
				else if(fn == "glVertexAttribI4i"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLint).name());
					args.emplace_back("v1", typeid(GLint).name());
					args.emplace_back("v2", typeid(GLint).name());
					args.emplace_back("v3", typeid(GLint).name());
				}
				else if(fn == "glVertexAttribI4ui"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLuint).name());
					args.emplace_back("v1", typeid(GLuint).name());
					args.emplace_back("v2", typeid(GLuint).name());
					args.emplace_back("v3", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttribL1d"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
				}
				else if(fn == "glVertexAttribL2d"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
				}
				else if(fn == "glVertexAttribL3d"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
					args.emplace_back("v2", typeid(GLdouble).name());
				}
				else if(fn == "glVertexAttribL4d"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v0", typeid(GLdouble).name());
					args.emplace_back("v1", typeid(GLdouble).name());
					args.emplace_back("v2", typeid(GLdouble).name());
					args.emplace_back("v3", typeid(GLdouble).name());
				}
				else if(fn == "glVertexAttrib1fv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(fn == "glVertexAttrib1sv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(fn == "glVertexAttrib1dv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(fn == "glVertexAttribI1iv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(fn == "glVertexAttribI1uiv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(fn == "glVertexAttrib2fv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(fn == "glVertexAttrib2sv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(fn == "glVertexAttrib2dv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(fn == "glVertexAttribI2iv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(fn == "glVertexAttribI2uiv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(fn == "glVertexAttrib3fv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(fn == "glVertexAttrib3sv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(fn == "glVertexAttrib3dv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(fn == "glVertexAttribI3iv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(fn == "glVertexAttribI3uiv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(fn == "glVertexAttrib4fv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(fn == "glVertexAttrib4sv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(fn == "glVertexAttrib4dv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(fn == "glVertexAttrib4iv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(fn == "glVertexAttrib4bv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLbyte *).name());
				}
				else if(fn == "glVertexAttrib4ubv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLubyte *).name());
				}
				else if(fn == "glVertexAttrib4usv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLushort *).name());
				}
				else if(fn == "glVertexAttrib4uiv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(fn == "glVertexAttrib4Nbv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLbyte *).name());
				}
				else if(fn == "glVertexAttrib4Nsv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(fn == "glVertexAttrib4Niv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(fn == "glVertexAttrib4Nubv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLubyte *).name());
				}
				else if(fn == "glVertexAttrib4Nusv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLushort *).name());
				}
				else if(fn == "glVertexAttrib4Nuiv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(fn == "glVertexAttribI4bv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLbyte *).name());
				}
				else if(fn == "glVertexAttribI4ubv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLubyte *).name());
				}
				else if(fn == "glVertexAttribI4sv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLshort *).name());
				}
				else if(fn == "glVertexAttribI4usv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLushort *).name());
				}
				else if(fn == "glVertexAttribI4iv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLint *).name());
				}
				else if(fn == "glVertexAttribI4uiv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLuint *).name());
				}
				else if(fn == "glVertexAttribL1dv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(fn == "glVertexAttribL2dv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(fn == "glVertexAttribL3dv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(fn == "glVertexAttribL4dv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLdouble *).name());
				}
				else if(fn == "glVertexAttribP1ui"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttribP2ui"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttribP3ui"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttribP4ui"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("value", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttribDivisor"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("divisor", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttribPointer"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("size", typeid(GLint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("stride", typeid(GLsizei).name());
					args.emplace_back("pointer", typeid(GLvoid *).name());
				}
				else if(fn == "glVertexAttribIPointer"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("size", typeid(GLint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("stride", typeid(GLsizei).name());
					args.emplace_back("pointer", typeid(GLvoid *).name());
				}
				else if(fn == "glVertexAttribLPointer"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("size", typeid(GLint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("stride", typeid(GLsizei).name());
					args.emplace_back("pointer", typeid(GLvoid *).name());
				}
				else if(fn == "glViewport"){
					ret = typeid(void).name();
					args.emplace_back("x", typeid(GLint).name());
					args.emplace_back("y", typeid(GLint).name());
					args.emplace_back("width", typeid(GLsizei).name());
					args.emplace_back("height", typeid(GLsizei).name());
				}
				else if(fn == "glViewportArrayv"){
					ret = typeid(void).name();
					args.emplace_back("first", typeid(GLuint).name());
					args.emplace_back("count", typeid(GLsizei).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(fn == "glViewportIndexedf"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("x", typeid(GLfloat).name());
					args.emplace_back("y", typeid(GLfloat).name());
					args.emplace_back("w", typeid(GLfloat).name());
					args.emplace_back("h", typeid(GLfloat).name());
				}
				else if(fn == "glViewportIndexedfv"){
					ret = typeid(void).name();
					args.emplace_back("index", typeid(GLuint).name());
					args.emplace_back("v", typeid(GLfloat *).name());
				}
				else if(fn == "glWaitSync"){
					ret = typeid(void).name();
					args.emplace_back("sync", typeid(GLsync).name());
					args.emplace_back("flags", typeid(GLbitfield).name());
					args.emplace_back("timeout", typeid(GLuint64).name());
				}
				else if(fn == "glCreateVertexArrays"){
					ret = typeid(void).name();
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("arrays", typeid(GLuint *).name());
				}
				else if(fn == "glVertexAttribBinding"){
					ret = typeid(void).name();
					args.emplace_back("attribindex", typeid(GLuint).name());
					args.emplace_back("bindingindex", typeid(GLuint).name());
				}
				else if(fn == "glVertexArrayAttribBinding"){
					ret = typeid(void).name();
					args.emplace_back("vaobj", typeid(GLuint).name());
					args.emplace_back("attribindex", typeid(GLuint).name());
					args.emplace_back("bindingindex", typeid(GLuint).name());
				}
				else if(fn == "glVertexAttribFormat"){
					ret = typeid(void).name();
					args.emplace_back("attribindex", typeid(GLuint).name());
					args.emplace_back("size", typeid(GLint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("relativeoffset", typeid(GLuint).name());
				}
				else if(fn == "glVertexArrayAttribFormat"){
					ret = typeid(void).name();
					args.emplace_back("vaobj", typeid(GLuint).name());
					args.emplace_back("attribindex", typeid(GLuint).name());
					args.emplace_back("size", typeid(GLint).name());
					args.emplace_back("type", typeid(GLenum).name());
					args.emplace_back("normalized", typeid(GLboolean).name());
					args.emplace_back("relativeoffset", typeid(GLuint).name());
				}
				else if(fn == "glBindVertexBuffer"){
					ret = typeid(void).name();
					args.emplace_back("bindingindex", typeid(GLuint).name());
					args.emplace_back("buffer", typeid(GLuint).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("stride", typeid(GLintptr).name());
				}
				else if(fn == "glVertexArrayVertexBuffer"){
					ret = typeid(void).name();
					args.emplace_back("vaobj", typeid(GLuint).name());
					args.emplace_back("bindingindex", typeid(GLuint).name());
					args.emplace_back("buffer", typeid(GLuint).name());
					args.emplace_back("offset", typeid(GLintptr).name());
					args.emplace_back("stride", typeid(GLsizei).name());
				}
				else if(fn == "glVertexArrayElementBuffer"){
					ret = typeid(void).name();
					args.emplace_back("vaobj", typeid(GLuint).name());
					args.emplace_back("buffer", typeid(GLuint).name());
				}
				else if(fn == "glDebugMessageCallback"){
					ret = typeid(void).name();
					args.emplace_back("callback", typeid(GLDEBUGPROC).name());
					args.emplace_back("userParam", typeid(void *).name());
				}
				else if(fn == "glCreateTextures"){
					ret = typeid(void).name();
					args.emplace_back("target", typeid(GLenum).name());
					args.emplace_back("n", typeid(GLsizei).name());
					args.emplace_back("textures", typeid(GLuint *).name());
				}
			}

			const char *ret = nullptr;
			std::vector<std::pair<std::string, const char*>> args;
	};
}

#endif // GAPI_KNOWN_HPP
