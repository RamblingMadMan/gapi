#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <functional>
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>

#include <SDL2/SDL.h>

#include "gapi/shader.hpp"
#include "gapi/texture.hpp"
#include "gapi/functions.hpp"

#include "tests.hpp"

#include "const_str.hpp"

namespace {
	using namespace gapi::functions;
	using namespace gapi;

	std::vector<std::function<void()>> atexit_funcs;

	void atexit_fn(){
		for(auto &&fn : atexit_funcs)
			fn();
	}
	
	template<typename Fn>
	void atexit(Fn &&fn){ atexit_funcs.emplace_back(std::forward<Fn>(fn)); }

	void gl_debug_fn(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const char *message,
		const void*
	){
		switch(severity){
			case GL_DEBUG_SEVERITY_HIGH:
				std::cerr << "[high severity] ";

			case GL_DEBUG_SEVERITY_MEDIUM:
				std::cerr << "[medium severity] ";

			case GL_DEBUG_SEVERITY_LOW:
				std::cerr << "[low severity] ";

			case GL_DEBUG_SEVERITY_NOTIFICATION:
			default:
				std::cerr << "[notification] ";
				break;
		}

		switch(type){
			case GL_DEBUG_TYPE_ERROR:{
				std::cerr << "[GL_DEBUG_TYPE_ERROR] ";
				break;
			}
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:{
				std::cerr << "[GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR] ";
				break;
			}
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:{
				std::cerr << "[GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR] ";
				break;
			}
			case GL_DEBUG_TYPE_PORTABILITY:{
				std::cerr << "[GL_DEBUG_TYPE_PORTABILITY] ";
				break;
			}
			case GL_DEBUG_TYPE_PERFORMANCE:{
				std::cerr << "[GL_DEBUG_TYPE_PERFORMANCE] ";
				break;
			}
			case GL_DEBUG_TYPE_OTHER:{
				std::cerr << "[GL_DEBUG_TYPE_OTHER] ";
				break;
			}
			case GL_DEBUG_TYPE_MARKER:{
				std::cerr << "[GL_DEBUG_TYPE_MARKER] ";
				break;
			}
			default:
				std::cerr << "[OPENGL_MESSAGE] ";
		}

		std::cerr << "from ";

		switch(source){
			case GL_DEBUG_SOURCE_API:{
				std::cerr << "api";
				break;
			}
			case GL_DEBUG_SOURCE_WINDOW_SYSTEM:{
				std::cerr << "window system";
				break;
			}
			case GL_DEBUG_SOURCE_SHADER_COMPILER:{
				std::cerr << "shader compiler";
				break;
			}
			case GL_DEBUG_SOURCE_THIRD_PARTY:{
				std::cerr << "third party";
				break;
			}
			case GL_DEBUG_SOURCE_APPLICATION:{
				std::cerr << "application";
				break;
			}

			[[fallthrough]]
			case GL_DEBUG_SOURCE_OTHER:
			default:{
				std::cerr << "other";
				break;
			}
		}

		std::cerr << ": " << message << '\n';
	}
}

auto main(int argc, char *argv[]) -> int
try{
	std::ofstream out("/dev/null");
	auto old_cerr_rdbuf = std::cerr.rdbuf();

	for(auto i = 1; i < argc; i++){
		if(std::strncmp(argv[i], "--", 2) != 0)
			throw std::runtime_error{"invalid command line option"};
		else if((argv[i]+2) == "nodebug"s)
			std::cerr.rdbuf(out.rdbuf());
	}

	std::atexit(atexit_fn);
	
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		throw std::runtime_error{SDL_GetError()};
		
	atexit(SDL_Quit);
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
	
	auto window = SDL_CreateWindow(
		"gapi test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1920, 1080,
		SDL_WINDOW_OPENGL
	);
	if(!window)
		throw std::runtime_error{SDL_GetError()};
	
	atexit([&window]{ SDL_DestroyWindow(window); });
	
	auto ctx = SDL_GL_CreateContext(window);
	if(!ctx)
		throw std::runtime_error{SDL_GetError()};
		
	atexit([&ctx]{ SDL_GL_DeleteContext(ctx); });
	
	if(SDL_GL_MakeCurrent(window, ctx) != 0)
		throw std::runtime_error{SDL_GetError()};

	atexit([]{ SDL_GL_MakeCurrent(nullptr, nullptr); });
	
	glDebugMessageCallback(gl_debug_fn, nullptr);

	SDL_Event ev;
	
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClearDepthf(1.f);
	
	std::vector<bool(*)(SDL_Window*)> tests;
	std::size_t i = 0;
	
	tests.push_back(test_buffer);
	tests.push_back(test_shader);
	tests.push_back(test_shader_buffer);
	tests.push_back(test_shader_texture);
	
	bool running = true;
	while(running){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	
		while(SDL_PollEvent(&ev)){
			switch(ev.type){
				case SDL_KEYDOWN:{
					switch(ev.key.keysym.sym){
						case SDLK_ESCAPE:{
							running = false;
							break;
						}
					
						default:
							break;
					}
					break;
				}
			
				default:
					break;
			}
		}
		
		bool test_res = tests[i++](window);
		
		SDL_GL_SwapWindow(window);

		if(test_res)
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
		if(i == tests.size())
			running = false;
	}

	std::cerr.rdbuf(old_cerr_rdbuf);
}
catch(const std::system_error &err){
	std::string except_type = boost::core::demangle(typeid(err).name());
	std::string message =
		"message: "s + err.code().message() + "\n" +
		"what:    "s + err.what();

	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, except_type.c_str(), message.c_str(), nullptr);
	std::exit(EXIT_FAILURE);
}
catch(const std::exception &err){
	std::string except_type = boost::core::demangle(typeid(err).name());
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, except_type.c_str(), err.what(), nullptr);
	std::exit(EXIT_FAILURE);
}
catch(...){
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "gapi error", "unknown error", nullptr);
	std::exit(EXIT_FAILURE);
}
