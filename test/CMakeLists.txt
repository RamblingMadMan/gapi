find_package(SDL2)

add_executable(
	gapi_test
	main.cpp
	buffer.cpp
	shader.cpp
	shader_buffer.cpp
	shader_texture.cpp
	framebuffer.cpp
)

target_include_directories(gapi_test PUBLIC ${SDL2_INCLUDE_DIR})
target_link_libraries(gapi_test PUBLIC gapi ${SDL2_LIBRARY})
