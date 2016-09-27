#include <iostream>

#include "gapi/constants.hpp"
#include "gapi/functions.hpp"
#include "gapi/shader.hpp"
#include "gapi/buffer.hpp"
#include "gapi/vertex_array.hpp"

#include "tests.hpp"
#include "test_data.hpp"

bool test_shader_buffer(SDL_Window *w){
	using namespace gapi;
	using namespace gapi::functions;
	
	std::cout << "testing shaders & buffers together... " << std::flush;

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

	shader_program<> color_prog{
		vertex_shader{color_vertex_src},
		fragment_shader{color_fragment_src}
	};

	color_prog.use();

	glm::vec4 color{1.f, 1.f, 1.f, 1.f};

	auto loc = color_prog.uniform_location("color");
	glUniform4f(loc, 1.f, 1.f, 1.f, 1.f);
	//glUniform4fv(loc, 1, color);
	
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	std::cout << "DONE\n" << std::flush;

	return true;
}
