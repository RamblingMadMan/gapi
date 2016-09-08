#include <cstdint>
#include <iostream>
#include <random>

#include "gapi/functions.hpp"
#include "gapi/texture.hpp"
#include "gapi/shader.hpp"
#include "gapi/buffer.hpp"
#include "gapi/vertex_array.hpp"
#include "gapi/utility.hpp"

#include "tests.hpp"
#include "test_data.hpp"

bool test_shader_texture(SDL_Window *w){
	using namespace gapi;
	using namespace gapi::functions;
	
	std::cout << "testing shaders & textures together... " << std::flush;

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

	shader_program<> program{
		vertex_shader{texture_vertex_src},
		fragment_shader{texture_fragment_src}
	};

	program.use();

	std::random_device rdev;
	std::mt19937 rengine;

	unsigned char data[1920*1080*4];

	for(auto i = 0; i < 1920*1080*4; i+=4){
		std::uint32_t rand = rengine();
		std::memcpy(&data[i], &rand, 4);
		data[i+3] = static_cast<unsigned char>(255u);
	}

	glActiveTexture(GL_TEXTURE0);

	GLsizei num_levels = 1 + std::floor(std::log2(std::max(1920, 1080)));

	texture tex_obj{{ tex2D(GL_RGBA8, 1920, 1080, num_levels) }};
	auto &&tex = dynamic_cast<texture2D_handle&>(static_cast<texture_handle&>(tex_obj));

	glBindTexture(GL_TEXTURE_2D, get_handle(tex));

	tex.set_sub_data(
		0, 0,
		1920, 1080,
		GL_RGBA, GL_UNSIGNED_BYTE,
		(const char*)data, 1920*1080*4
	);

	glGenerateTextureMipmap(get_handle(tex));

	auto texture_uniform = program.uniform_location("tex");

	glUniform1i(texture_uniform, 0);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	std::cout << "DONE\n";

	return true;
}
