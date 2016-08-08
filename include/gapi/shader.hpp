#ifndef GAPI_SHADER_HPP
#define GAPI_SHADER_HPP 1

#include <istream>

#include "object.hpp"
#include "functions.hpp"

namespace gapi{
	class shader_error: public gapi_error{
		public:
			shader_error(const std::string &str)
				: gapi_error{str}{}
	};
	
	class program_error: public gapi_error{
		public:
			program_error(const std::string &str)
			: gapi_error{str}{}
	};
	
	class Vertex;
	class Fragment;
	class Geometry;
	
	namespace detail{
		template<typename T>
		T &lvalue(T &&val){ return val; }
		
		template<typename ShaderType>
		class shader_enum;
		
		template<>
		struct shader_enum<Vertex>{
			enum { value = GL_VERTEX_SHADER };
		};
		
		template<>
		struct shader_enum<Fragment>{
			enum { value = GL_FRAGMENT_SHADER };
		};
		
		template<>
		struct shader_enum<Geometry>{
			enum { value = GL_GEOMETRY_SHADER };
		};
	}
	
	template<typename ShaderType>
	class shader: public object{
		public:
			shader(const std::string &source)
				: shader(){
				set_source(source);
				compile();
			}
			
			shader(std::istream &str)
				: shader(){
				set_source(str);
				compile();
			}
			
			shader(){ handle = functions::glCreateShader(detail::shader_enum<ShaderType>::value); }
			
			virtual ~shader(){ functions::glDeleteShader(handle); }
			
			void set_source(const std::string &str){
				functions::glShaderSource(handle, 1, &detail::lvalue(str.c_str()), nullptr);
			}
			
			void set_source(std::istream &str){
				std::string source, line;
				while(getline(str, line))
					source += line + '\n';
				
				set_source(source);
			}
			
			void compile(){
				functions::glCompileShader(handle);
				
				GLint val;
				functions::glGetShaderiv(handle, GL_COMPILE_STATUS, &val);
				
				if(val != GL_TRUE){
					functions::glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &val);
					std::string str(val, '\0');
					
					functions::glGetShaderInfoLog(handle, val, &val, &str[0]);
					throw shader_error{str};
				}
			}
		
		protected:
			template<typename...>
			friend class shader_program;
	};
	
	class Seperate;
	
	template<typename...>
	class shader_program;
	
	template<typename ShaderType>
	class shader_program<Seperate, ShaderType>: public object{
		public:
			shader_program(const std::string &str){
				create(str);
			}
				
			shader_program(std::istream &str){
				std::string source, line;
				while(getline(str, line))
					source += line + '\n';
				
				create(source);
			}
			
			shader_program(){}
			
			void create(const std::string &str){
				if(created)
					throw program_error{"program already created"};
				
				handle = functions::glCreateShaderProgramv(detail::shader_enum<ShaderType>::value, 1, detail::lvalue(str.c_str()));
				check();
				created = true;
			}
			
			void create(std::istream &str){
				std::string source, line;
				while(getline(str, line))
					source += line + '\n';
				
				create(source);
			}
			
			virtual ~shader_program(){ functions::glDeleteProgram(handle); }
			
			void use() const noexcept{ functions::glUseProgram(handle); }
			
		protected:
			bool created = false;
			
			void check(){
				GLint val;
				functions::glGetProgramiv(handle, GL_LINK_STATUS, &val);
				 
				if(val != GL_TRUE){
					functions::glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &val);
					std::string str(val, '\0');
					 
					functions::glGetProgramInfoLog(handle, val, &val, &str[0]);
					throw program_error{str};
				}
			}
	};
	
	class deferred_link_t{} deferred_link;
	
	template<>
	class shader_program<>: public object{
		public:
			shader_program(){ handle = functions::glCreateProgram(); }
			
			template<typename ShaderType, typename ... ShaderTypes>
			shader_program(const shader<ShaderType> &shad, const shader<ShaderTypes> &... shaders)
				: shader_program(){
				attach(shad);
				(attach(shaders), ...);
				link();
			}
			
			template<typename ShaderType, typename ... ShaderTypes>
			shader_program(deferred_link_t, const shader<ShaderType> &shad, const shader<ShaderTypes> &... shaders)
			: shader_program(){
				attach(shad);
				(attach(shaders), ...);
			}
			
			virtual ~shader_program(){ functions::glDeleteProgram(handle); }
			
			template<typename ShaderType, typename ... ShaderTypes>
			void attach(const shader<ShaderType> &shad, const shader<ShaderTypes> &... shaders){
				functions::glAttachShader(handle, shad.handle);
				(functions::glAttachShader(handle, shaders.handle), ...);
			}
			
			void link(){
				functions::glLinkProgram(handle);
				
				GLint val;
				functions::glGetProgramiv(handle, GL_LINK_STATUS, &val);
				
				if(val != GL_TRUE){
					functions::glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &val);
					std::string str(val, '\0');
					
					functions::glGetProgramInfoLog(handle, val, &val, &str[0]);
					throw program_error{str};
				}
			}
			
			void use() const noexcept{ functions::glUseProgram(handle); }
	};
}

#endif // GAPI_SHADER_HPP
