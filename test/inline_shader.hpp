#ifndef INLINE_SHADER_HPP
#define INLINE_SHADER_HPP 1

#define EXPAND(...) __VA_ARGS__
#define GLSL(...) #__VA_ARGS__
#define GLSL_LINE(...) __VA_ARGS__ ";\n"
#define GLSL_FN(ret, name, args, ...) #ret " " #name #args "{\n"\
	__VA_ARGS__\
"}\n"
#define GLSL_EXTENSION(...) "#extension " #__VA_ARGS__ "\n"
#define GLSL_VERSION(...) "#version " #__VA_ARGS__ "\n"
#define GLSL_IN "in "
#define GLSL_OUT "out "
#define GLSL_VEC2 "vec2 "
#define GLSL_VEC3 "vec3 "
#define GLSL_VEC4 "vec4 "
#define GLSL_UNIFORM "uniform "
#define GLSL_LAYOUT(...) GLSL(layout(__VA_ARGS__))

#endif // INLINE_SHADER_HPP

