#ifndef GAPI_TEST_DATA_HPP
#define GAPI_TEST_DATA_HPP 1

#include <glm/glm.hpp>

#include "inline_shader.hpp"

static glm::vec4 square_verts[4] = {
	{-1.f, -1.f, 0.f, 1.f}, { 1.f, -1.f, 0.f, 1.f},
	{ 1.f,  1.f, 0.f, 1.f}, {-1.f,  1.f, 0.f, 1.f}
};

static glm::vec2 square_uvs[4] = {
	{0.f, 0.f}, {1.f, 0.f},
	{1.f, 1.f}, {0.f, 1.f}
};

constexpr char color_vertex_src[] =
GLSL_VERSION(330 core)
GLSL_EXTENSION(GL_ARB_shading_language_420pack : enable)

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

constexpr char color_fragment_src[] =
GLSL_VERSION(330 core)
GLSL_EXTENSION(GL_ARB_shading_language_420pack : enable)

GLSL_LINE( GLSL_UNIFORM GLSL_VEC4 GLSL(color) )

GLSL_LINE( GLSL_IN GLSL_VEC3 GLSL(vert_f) )
GLSL_LINE( GLSL_IN GLSL_VEC2 GLSL(uv_f) )

GLSL_LINE( GLSL_LAYOUT(location = 0) GLSL_OUT GLSL_VEC4 GLSL(screen) )

GLSL_FN(void, main,(),
	GLSL_LINE( GLSL(screen = vec4(vert_f.xy, uv_f.x*uv_f.y, 1.0) * color) )
)
;

#endif // GAPI_TEST_DATA_HPP

