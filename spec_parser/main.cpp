#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <future>

#include <boost/property_tree/xml_parser.hpp>

auto main() -> int{
	namespace pt = boost::property_tree;

	std::ifstream file{"gl.xml"};

	pt::ptree tree;
	pt::read_xml(file, tree);

	struct fn{
		std::string name;
		std::string brief;
		std::string ret;
		std::vector<std::pair<std::string, std::string>> args;
	};

	std::vector<fn> funcs;

	for(auto &&root : tree.get_child("module")){
		if(root.first == "libraries")
			for(auto &&library : root.second.get_child("library")){
				if(library.first == "functions"){
					auto brief = library.second.get<std::string>("documentation");

					std::vector<fn> fns;
					bool going = false;
					fn f;
					for(auto &&function : library.second.get_child("function")){
						if(function.first == "<xmlattr>"){
							if(going)
								funcs.push_back(f);
							else going = true;

							f.name = function.second.get<std::string>("name");
							f.ret = function.second.get<std::string>("type");
							f.brief = brief;
						}
						else if(function.first == "param"){
							auto name = function.second.get<std::string>("<xmlattr>.name");
							if(name == "void")
								continue;
							f.args.emplace_back(
								name,
								function.second.get<std::string>("<xmlattr>.type")
							);
						}
					}
					funcs.push_back(f);
				}
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
				"#include \"basic_types.hpp\"\n"
				"\n"
				"namespace gapi{\n"
				"\tclass known{\n"
				"\t\tprivate:\n"
				"\t\t\tauto safe_compare(const char *usr, const char *cst){\n"
				"\t\t\t\treturn std::strncmp(usr, cst, std::strlen(cst)) == 0;\n"
				"\t\t\t}\n"
				"\n"
				"\t\tpublic:\n"
				"\t\t\tknown(const char *fn){\n"; // start of constructor
				
				for(std::size_t i = 0; i < funcs.size(); i++){
					if(i == 0)
		out <<	"\t\t\t\tif(safe_compare(fn, \"" << funcs[i].name << "\")){\n";
					else
		out <<	"\t\t\t\telse if(safe_compare(fn, \"" << funcs[i].name << "\")){\n";

		out <<	"\t\t\t\t\tret = typeid(" << funcs[i].ret << ").name();\n";

					for(auto &&arg : funcs[i].args)
		out <<	"\t\t\t\t\targs.emplace_back(\"" << arg.first << "\", typeid(" << arg.second << ").name());\n";

		out <<	"\t\t\t\t}\n";
				}

		out <<	"\t\t\t}\n" // end of constructor
				"\n"
				"\t\t\tconst char *ret;\n"
				"\t\t\tstd::vector<std::pair<std::string, const char*>> args;\n"
				"\t};\n" // end of class
				"}\n" // end of namespace
				"\n"
				"#endif // GAPI_KNOWN_HPP\n" // end of file
				"\n";
	}
}
