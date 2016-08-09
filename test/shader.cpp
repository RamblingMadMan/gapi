#include <iostream>

#include "gapi/shader.hpp"

#include "tests.hpp"
#include "test_data.hpp"
#include "inline_shader.hpp"

bool test_shader(SDL_Window*){
	using namespace gapi;
	using namespace gapi::functions;
	
	std::cout << "testing shaders... " << std::flush;

	shader<Vertex> color_vert{color_vertex_src};
	shader<Fragment> color_frag{color_fragment_src};
	shader_program<> color_prog{color_vert, color_frag};

	color_prog.use();

	vec4 color{1.f, 1.f, 1.f, 1.f};

	auto loc = color_prog.uniform_location("color");
	glUniform4fv(loc, 1, color);

	std::cout << "DONE\n";

	return false;
}

