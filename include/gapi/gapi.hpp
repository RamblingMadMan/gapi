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

	template<typename Ret, typename ... Args>
	class gl_function<Ret(Args...)>{
		private:
			template<typename T>
			class type_tag{ public: using type = T; };

			template<std::size_t ... Indices, typename T>
			void test_args_impl(std::index_sequence<Indices...>, const char *name, T &&vec){
				([&](auto idx, auto type){
					if(std::string(vec[idx].second) != typeid(typename decltype(type)::type).name())
						throw gapi_error{"argument "s + std::to_string(idx) + " for " + name + " not of expected type " + boost::core::demangle(vec[idx].second)};
				}(Indices, type_tag<Args>{}), ...);
			}

			template<typename T>
			void test_args(const char *name, T &&vec){
				test_args_impl(std::index_sequence_for<Args...>{}, name, std::forward<T>(vec));
			}

		public:
			gl_function(const char *name){
				known k{name};
				if(k.ret){
					if(std::string(k.ret) != typeid(Ret).name())
						throw gapi_error{"return type doesn't match known return type for "s + name};
					else if(sizeof...(Args) != k.args.size())
						throw gapi_error{"number of arguments doesn't match known number of arguments for "s + name};
					
					test_args(name, k.args);
				}
				fptr = reinterpret_cast<Ret(*)(Args...)>(detail::get_gl_fp(name));
				if(!fptr)
					throw gapi_error{"could not get function pointer for "};
			}

			Ret operator()(Args ... args){
				return fptr(args...);
			}

		protected:
			Ret(*fptr)(Args...);
			friend class context;
	};
}

#endif // GAPI_HPP
