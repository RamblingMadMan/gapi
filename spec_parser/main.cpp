#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <future>
#include <functional>
#include <typeinfo>
#include <chrono>
#include <mutex>

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>

auto main() -> int{
	using Clock = std::chrono::high_resolution_clock;
	using std::chrono::nanoseconds;
	using std::chrono::duration_cast;
	
	struct fn{
		std::string name;
		std::string brief;
		std::string ret;
		std::vector<std::pair<std::string, std::string>> args;
	};
	
	std::vector<fn> funcs;
	std::vector<std::pair<std::string, std::string>> consts;

	rapidxml::file<> xmlFile{"gl.xml"};
	rapidxml::xml_document<> doc;
	doc.parse<0>(xmlFile.data());
	
	using xml_node = rapidxml::xml_node<>;
	
	xml_node *proot = doc.first_node(); // <module>
	if(!proot)
		throw std::runtime_error{"no root <module> in gl.xml"};
	
	for(xml_node *pnode = proot->first_node("libraries"); pnode; pnode = pnode->next_sibling()){
		for(xml_node *plib = pnode->first_node("library"); plib; plib = plib->next_sibling()){
			for(xml_node *pfuncs = plib->first_node("functions"); pfuncs; pfuncs = pfuncs->next_sibling()){
				std::string brief;
				
				xml_node *pdoc = pfuncs->first_node("documentation");
				if(pdoc){
					brief = pdoc->value();
				}
				
				for(xml_node *pfunc = pfuncs->first_node("function"); pfunc; pfunc = pfunc->next_sibling()){
					fn f;
					auto name = pfunc->first_attribute("name");
					if(!name)
						throw std::runtime_error{"function without a name in gl.xml"};
					
					f.name = name->value();
					
					auto type = pfunc->first_attribute("type");
					if(!type)
						throw std::runtime_error{"function without a return type in gl.xml"};
					
					f.ret = type->value();
					
					for(xml_node *pparam = pfunc->first_node("param"); pparam; pparam = pparam->next_sibling()){
						auto nameattr = pparam->first_attribute("name");
						if(!nameattr)
							throw std::runtime_error{"function parameter without a name"};
						
						std::string name = nameattr->value();
						
						if(name == "void")
							break;
						
						auto typeattr = pparam->first_attribute("type");
						if(!typeattr)
							throw std::runtime_error{"function parameter without a type"};
						
						std::string type = typeattr->value();
						
						f.args.emplace_back(std::move(name), std::move(type));
					}
					
					funcs.emplace_back(std::move(f));
				}
			}
		}
	}
	for(xml_node *pnode = proot->first_node("consts"); pnode; pnode = pnode->next_sibling()){
		for(xml_node *pconst = pnode->first_node("const"); pconst; pconst = pconst->next_sibling()){
			auto attrname = pconst->first_attribute("name");
			auto attrvalue = pconst->first_attribute("value");
			
			if(!attrname)
				throw std::runtime_error{"constant without name in gl.xml"};
			else if(!attrvalue)
				throw std::runtime_error{"constant without value in gl.xml"};
			
			consts.emplace_back(attrname->value(), attrvalue->value());
		}
	}

	{
		std::ofstream out{"known.hpp"};
		if(!out){
			std::cerr << "could not create/open output file known.hpp\n";
			std::exit(EXIT_FAILURE);
		}

		out <<	"#ifndef GAPI_KNOWN_HPP\n"
				"#define GAPI_KNOWN_HPP 1\n"
				"\n"
				"#include <cstring>\n"
				"#include <vector>\n"
				"#include <string>\n"
				"#include <utility>\n"
				"#include <typeinfo>\n"
				"\n"
				"#include \"types.hpp\"\n"
				"\n"
				"namespace gapi{\n"
				"\tclass known{\n"
				"\t\tpublic:\n"
				"\t\t\tknown(const std::string &fn){\n"; // start of constructor
				
				for(std::size_t i = 0; i < funcs.size(); i++){
					if(i == 0)
		out <<	"\t\t\t\tif(fn == \"" << funcs[i].name << "\"){\n";
					else
		out <<	"\t\t\t\telse if(fn == \"" << funcs[i].name << "\"){\n";

		out <<	"\t\t\t\t\tret = typeid(" << funcs[i].ret << ").name();\n";

					for(auto &&arg : funcs[i].args)
		out <<	"\t\t\t\t\targs.emplace_back(\"" << arg.first << "\", typeid(" << arg.second << ").name());\n";

		out <<	"\t\t\t\t}\n";
				}

		out <<	"\t\t\t}\n" // end of constructor
				"\n"
				"\t\t\tconst char *ret = nullptr;\n"
				"\t\t\tstd::vector<std::pair<std::string, const char*>> args;\n"
				"\t};\n" // end of class
				"}\n" // end of namespace
				"\n"
				"#endif // GAPI_KNOWN_HPP\n"; // end of file
	}
	{
		std::ofstream out{"constants.hpp"};
		if(!out){
			std::cerr << "could not create/open output file constants.hpp\n";
			std::exit(EXIT_FAILURE);
		}

		out <<	"#ifndef GAPI_CONSTANTS_HPP\n"
				"#define GAPI_CONSTANTS_HPP 1\n"
				"\n"
				"namespace gapi{\n"; // start namespace
				std::vector<std::string> done_consts;
				for(auto &&c : consts){
					bool break_ = false;
					for(auto &&d : done_consts)
						if(c.first == d) break_ = true;
					if(break_) break;
		out	<<	"\tconstexpr auto " << c.first << " = " << c.second << ";\n";
					done_consts.push_back(c.first);
				}
		out	<<	"}\n" // end namespace
				"\n"
				"#endif // GAPI_CONSTANTS_HPP\n";
	}
	{
		std::ofstream out{"functions.hpp"};
		if(!out){
			std::cerr << "could not create/open output file functions.hpp\n";
			std::exit(EXIT_FAILURE);
		}

		out	<<	"#ifndef GAPI_FUNCTIONS_HPP\n"
				"#define GAPI_FUNCTIONS_HPP 1\n"
				"\n"
				"#include \"gapi.hpp\"\n"
				"#include \"types.hpp\"\n"
				"\n"
				"namespace gapi{\n" // start of namespace
				"\tnamespace functions{\n";
				for(auto &&func : funcs){
		out	<<	"\t\textern gl_function<" << func.ret << '(';
					for(std::size_t i = 0; i < func.args.size(); i++){
		out	<<	func.args[i].second;
						if(i < (func.args.size()-1))
							out << ", ";
					}
		out	<<	")> " << func.name << ";\n";
				}
		out	<<	"\t}\n" // end of functions namespace
				"}\n" // end of gapi namespace
				"\n"
				"#endif // GAPI_FUNCTIONS_HPP\n";
	}
	{
		std::ofstream out{"functions.cpp"};
		if(!out){
			std::cerr << "could not create/open output file functions.cpp\n";
			std::exit(EXIT_FAILURE);
		}
		
		out <<	"#include \"gapi/gapi.hpp\"\n"
				"#include \"gapi/types.hpp\"\n"
				"\n"
				"namespace gapi{\n"
				"\tnamespace functions{\n";
		
		for(auto &&func : funcs){
			out	<<	"\t\tgl_function<" << func.ret << '(';
			for(std::size_t i = 0; i < func.args.size(); i++){
				out	<<	func.args[i].second;
				if(i < (func.args.size()-1))
					out << ", ";
			}
			out	<<	")> " << func.name << "{deferred_init, \"" << func.name << "\"};\n";
		}
		
		out <<	"\t}\n" // end functions namespace
				"}\n"; // end gapi namespace
	}
}
