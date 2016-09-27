#ifndef GAPI_TEST_DATA_HPP
#define GAPI_TEST_DATA_HPP 1

#include <glm/glm.hpp>

using vec2 = glm::vec2;
using vec3 = glm::vec3;
using vec4 = glm::vec4;

#include "inline_shader.hpp"

static vec4 square_verts[4] = {
	{-1.f, -1.f, 0.f, 1.f}, { 1.f, -1.f, 0.f, 1.f},
	{ 1.f,  1.f, 0.f, 1.f}, {-1.f,  1.f, 0.f, 1.f}
};

static vec2 square_uvs[4] = {
	{0.f, 0.f}, {1.f, 0.f},
	{1.f, 1.f}, {0.f, 1.f}
};

constexpr shader_source color_vertex_src =
	GLSL_VERSION(330 core)
	GLSL_ENABLE_EXT(GL_ARB_shading_language_420pack)

	GLSL_LINE( GLSL_LAYOUT(location = 0) GLSL_IN GLSL_VEC3 GLSL(vert) )
	GLSL_LINE( GLSL_LAYOUT(location = 1) GLSL_IN GLSL_VEC2 GLSL(uv) )

	GLSL_LINE( GLSL_OUT GLSL_VEC3 GLSL(vert_f) )
	GLSL_LINE( GLSL_OUT GLSL_VEC2 GLSL(uv_f) )

	GLSL_FN(void, main,(),
		GLSL_LINE( GLSL(vert_f = vert) )
		GLSL_LINE( GLSL(uv_f = uv ) )
		GLSL_LINE( GLSL(gl_Position = vec4(vert, 1.0)) )
	)
;

constexpr shader_source color_fragment_src =
	GLSL_VERSION(330 core)
	GLSL_ENABLE_EXT(GL_ARB_shading_language_420pack)

	GLSL_LINE( GLSL_UNIFORM GLSL_VEC4 GLSL(color) )

	GLSL_LINE( GLSL_IN GLSL_VEC3 GLSL(vert_f) )
	GLSL_LINE( GLSL_IN GLSL_VEC2 GLSL(uv_f) )

	GLSL_LINE( GLSL_LAYOUT(location = 0) GLSL_OUT GLSL_VEC4 GLSL(screen) )

	GLSL_FN(void, main,(),
		GLSL_LINE( GLSL(screen = vec4(vert_f.xy, uv_f.x*uv_f.y, 1.0) * color) )
	);

constexpr shader_source texture_vertex_src =
	GLSL_VERSION(330 core)
	GLSL_ENABLE_EXT(GL_ARB_shading_language_420pack)

	GLSL_LINE( GLSL_LAYOUT(location = 0) GLSL_IN GLSL_VEC3 GLSL(vert) )
	GLSL_LINE( GLSL_LAYOUT(location = 1) GLSL_IN GLSL_VEC2 GLSL(uv) )

	GLSL_LINE( GLSL_OUT GLSL_VEC3 GLSL(vert_f) )
	GLSL_LINE( GLSL_OUT GLSL_VEC2 GLSL(uv_f) )

	GLSL_FN(void, main,(),
		GLSL_LINE( GLSL(vert_f = vert) )
		GLSL_LINE( GLSL(uv_f = uv) )
		GLSL_LINE( GLSL(gl_Position = vec4(vert, 1.0)) )
	)
;

constexpr shader_source texture_fragment_src =
	GLSL_VERSION(330 core)
	GLSL_ENABLE_EXT(GL_ARB_shading_language_420pack)

	GLSL_LINE( GLSL_UNIFORM GLSL_SAMPLER2D GLSL(tex) )

	GLSL_LINE( GLSL_IN GLSL_VEC3 GLSL(vert_f) )
	GLSL_LINE( GLSL_IN GLSL_VEC2 GLSL(uv_f) )

	GLSL_LINE( GLSL_LAYOUT(location = 0) GLSL_OUT GLSL_VEC4 GLSL(screen) )

	GLSL_FN(void, main,(),
		GLSL_LINE( GLSL(screen = vec4(texture(tex, uv_f).rgb, 1.0) * vec4(vert_f, 1.0)) )
	)
;

constexpr shader_source framebuffer_vertex_src =
	GLSL_VERSION(330 core)
	GLSL_ENABLE_EXT(GL_ARB_shading_language_420pack)
	
	GLSL_LINE( GLSL_LAYOUT(location = 0) GLSL_IN GLSL_VEC3 GLSL(vert) )
	GLSL_LINE( GLSL_LAYOUT(location = 1) GLSL_IN GLSL_VEC2 GLSL(uv) )

	GLSL_LINE( GLSL_OUT GLSL_VEC3 GLSL(vert_f) )
	GLSL_LINE( GLSL_OUT GLSL_VEC2 GLSL(uv_f) )
	
	GLSL_FN(void, main,(),
		GLSL_LINE( GLSL(vert_f = vert) )
		GLSL_LINE( GLSL(uv_f = uv) )
		GLSL_LINE( GLSL(gl_Position = vec4(vert, 1.0)) )
	)
;

constexpr shader_source framebuffer_fragment_src =
	GLSL_VERSION(330 core)
	GLSL_ENABLE_EXT(GL_ARB_shading_language_420pack)

	GLSL_LINE( GLSL_UNIFORM GLSL_SAMPLER2D GLSL(tex) )

	GLSL_LINE( GLSL_IN GLSL_VEC3 GLSL(vert_f) )
	GLSL_LINE( GLSL_IN GLSL_VEC2 GLSL(uv_f) )

	GLSL_LINE( GLSL_LAYOUT(location = 0) GLSL_OUT GLSL_VEC4 GLSL(screen) )

	GLSL_FN(void, main,(),
		GLSL_LINE( GLSL(screen = texture(tex, uv_f)) )
	)
;

#endif // GAPI_TEST_DATA_HPP

