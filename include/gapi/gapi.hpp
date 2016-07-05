#ifndef GAPI_HPP
#define GAPI_HPP 1

#include <boost/core/demangle.hpp>

#include "exception.hpp"
#include "known.hpp"

namespace gapi{
	using namespace std::literals;

	namespace detail{
		void(*get_gl_fp(const char *name))();
	}

	template<typename...>
	class gl_function;

	struct no_init_t{
		struct no_init_arg_t{ constexpr no_init_arg_t(){} };
		constexpr no_init_t(no_init_arg_t){}
	};

	static no_init_t no_init{no_init_t::no_init_arg_t{}};

	template<typename Ret, typename ... Args>
	class gl_function<Ret(Args...)>{
		private:
			template<typename T>
			class type_tag{ public: using type = T; };

			template<std::size_t ... Indices, typename T>
			void test_args_impl(std::index_sequence<Indices...>, const std::string &name, T &&vec){
				([&](auto idx, auto type){
					if(std::string(vec[idx].second) != typeid(typename decltype(type)::type).name())
						throw gapi_error{"argument "s + std::to_string(idx) + " for " + name + " not of expected type " + boost::core::demangle(vec[idx].second)};
				}(Indices, type_tag<Args>{}), ...);
			}

			template<typename T>
			void test_args(const std::string &name, T &&vec){
				test_args_impl(std::index_sequence_for<Args...>{}, name, std::forward<T>(vec));
			}

		public:
			gl_function(const char *name)
				: fn_name{name}{
				init();
			}

			gl_function(no_init_t, const char *name)
				: fn_name{name}{}

			Ret operator()(Args ... args){
				return fptr(args...);
			}

			void init(){
				known k{fn_name.c_str()};
				if(k.ret){
					if(std::string(k.ret) != typeid(Ret).name())
						throw gapi_error{"return type doesn't match known return type for "s + name};
					else if(sizeof...(Args) != k.args.size())
						throw gapi_error{"number of arguments doesn't match known number of arguments for "s + name};
					
					test_args(fn_name.c_str(), k.args);
				}

				fptr = reinterpret_cast<Ret(*)(Args...)>(detail::get_gl_fp(fn_name.c_str()));
				if(!fptr)
					throw gapi_error{"could not get function pointer for "};
			}

			const std::string &name() const noexcept{ return fn_name; }

		protected:
			std::string fn_name;
			Ret(*fptr)(Args...) = [](Args...) -> Ret{ throw gapi_error{"uninitialized opengl function called"}; };
			friend class context;
	};
}

#endif // GAPI_HPP
