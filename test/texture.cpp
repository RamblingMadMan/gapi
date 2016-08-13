#include <random>

#include "gapi/vertex_array.hpp"
#include "gapi/shader.hpp"
#include "gapi/texture.hpp"

#include "tests.hpp"

#include "test_data.hpp"

bool test_shader_texture(SDL_Window *w){
	using namespace gapi;
	using namespace gapi::functions;

	shader_program<> prog{
		shader<Vertex>{texture_vertex_src},
		shader<Fragment>{texture_fragment_src}
	};

	prog.use();

	unsigned char alignas(16) texture_data[1920*1080*4];

	std::random_device rand_dev;
	for(std::size_t i = 0; i < (1920*1080*4); i+=4){
		std::uint64_t n = std::mt19937_64(rand_dev);
		std::memcpy(&texture_data[i], &n, 16);
		texture_data[3] = 255;
	}

	texture t{gapi::tex2D(GL_RGBA8, 1920, 1080)};
	static_cast<texture_handle&>(t).set_sub_data(
		0, 0,
		1920, 1080,
		GL_RGBA, GL_UNSIGNED_BYTE,
		texture_data
	);

	vertex_array vao_obj;
	auto &vao = static_cast<vertex_array_handle&>(vao_obj);
	
	vao.use();

	vao.enable_attrib(0);
	vao.enable_attrib(1);

	vao.attrib_binding(0, 0);
	vao.attrib_binding(1, 1);

	buffers<2> bufs{{sizeof(glm::vec4)*4, sizeof(glm::vec2)*4}};

	bufs[0].set_sub_data(0, square_verts, sizeof(glm::vec4)*4);
	bufs[1].set_sub_data(0, square_uvs, sizeof(glm::vec2)*4);

	vao.set_vertex_buffer(bufs[0], 0, 0, sizeof(glm::vec4));
	vao.set_vertex_buffer(bufs[1], 1, 0, sizeof(glm::vec2));

	vao.attrib_format(0, 3, GL_FLOAT, GL_FALSE, 0);
	vao.attrib_format(1, 2, GL_FLOAT, GL_FALSE, 0);
}
