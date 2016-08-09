#include <iostream>
#include <cstring>

#include "gapi/buffer.hpp"
#include "gapi/vertex_array.hpp"

#include "tests.hpp"
#include "test_data.hpp"

bool test_buffer(SDL_Window*){
	using namespace gapi;
	using namespace gapi::functions;
	
	std::cout << "testing buffers... " << std::flush;

	buffers<2> bufs{{sizeof(glm::vec4)*4, sizeof(glm::vec2)*4}};

	if((bufs[0].size() != (sizeof(glm::vec4)*4)) || (bufs[1].size() != (sizeof(glm::vec2)*4)))
		throw std::runtime_error{"buffer test failed: buffer_handle::size() not same as initialized with"};

	bufs[0].set_sub_data(0, square_verts, sizeof(glm::vec4)*4);
	bufs[1].set_sub_data(0, square_uvs, sizeof(glm::vec2)*4);

	auto map4f = bufs[0].map();
	auto map2f = bufs[1].map();

	if(
			(std::memcmp(map4f.data(), square_verts, sizeof(glm::vec4)*4) != 0) ||
			(std::memcmp(map2f.data(), square_uvs, sizeof(glm::vec2)*4) != 0)
		)
		throw std::runtime_error{"buffer test failed: data sent to buffer_handle::set_sub_data() not the same as recieved from buffer_handle::get_sub_data()"};



	vertex_array vao_obj;
	auto &vao = static_cast<vertex_array_handle&>(vao_obj);
	for(auto i = 0ul; i < 2; i++){
		vao.set_vertex_buffer(bufs[i], i);
		vao.enable_attrib(i);
	}

	vao.attrib_format(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec4));
	vao.attrib_format(1, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2));
	
	vao.attrib_binding(0, 0);
	vao.attrib_binding(1, 1);

	std::cout << "DONE\n";

	return false;
}
