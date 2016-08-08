#ifndef GAPI_GAPI_HPP
#define GAPI_GAPI_HPP 1

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

	struct deferred_init_t{
		struct deferred_init_arg_t{ constexpr deferred_init_arg_t(){} };
		constexpr deferred_init_t(deferred_init_arg_t){}
	};

	struct no_test_t{
		struct no_test_arg_t{ constexpr no_test_arg_t(){} };
		constexpr no_test_t(no_test_arg_t){}
	};

	static deferred_init_t deferred_init{deferred_init_t::deferred_init_arg_t{}};
	static no_test_t no_test{no_test_t::no_test_arg_t{}};

	template<typename Ret, typename ... Args>
	class gl_function<Ret(Args...)>{
		private:
			template<typename T>
			class type_tag{ public: using type = T; };

			template<std::size_t ... Indices, typename T>
			void test_args_impl(std::index_sequence<Indices...>, const std::string &name, T &&vec){
				([this](auto &&vec, auto idx, auto type){
					if(std::string(vec[idx].second) != type)
						throw gapi_error("argument "s + std::to_string(idx) + " for " + this->fn_name + " not of expected type " + boost::core::demangle(vec[idx].second));
				}(std::forward<T>(vec), Indices, typeid(Args).name()), ...);
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

			~gl_function(){ delete fn; }

			gl_function(no_test_t, const char *name)
				: fn_name{name}{
				init(no_test);
			}

			gl_function(deferred_init_t, const char *name)
				: fn_name{name}{}

			Ret operator()(Args ... args){
				return (*fn)(args...);
			}

			void init(no_test_t){
				fptr = reinterpret_cast<Ret(*)(Args...)>(detail::get_gl_fp(fn_name.c_str()));
				if(!fptr)
					throw gapi_error{"could not get function pointer for "s + fn_name};
			
				delete fn;
				fn = new func_ptr{this};
			}

			void init(){
				known k{fn_name.c_str()};
				if(k.ret){
					if(std::string(k.ret) != typeid(Ret).name())
						throw gapi_error{"return type doesn't match known return type for "s + fn_name};
					else if(sizeof...(Args) != k.args.size())
						throw gapi_error{"number of arguments doesn't match known number of arguments for "s + fn_name};
					
					test_args(fn_name.c_str(), k.args);
				}

				init(no_test);
			}

			Ret init_call(Args ... args){
				init();
				return (*fptr)(args...);
			}

			Ret init_call(no_test_t, Args ... args){
				init(no_test);
				return (*fptr)(args...);
			}

			const std::string &name() const noexcept{ return fn_name; }
			
			Ret(*get())(Args...){
				return fptr;
			}

		protected:
			Ret(*fptr)(Args...) = +[](Args ... args) -> Ret{
				throw gapi_error{"opengl function uninitialized"};
				return Ret(0);
			};
			
			std::string fn_name;

			class func_base{
				public:
					func_base(gl_function<Ret(Args...)> *self_)
						: self{self_}{}
						
					virtual ~func_base(){}

					virtual Ret operator()(Args ... args) = 0;

					gl_function<Ret(Args...)> *self;
			};

			class func_init: public func_base{
				public:
					func_init(gl_function<Ret(Args...)> *self_)
						: func_base{self_}{}

					Ret operator()(Args ... args){
						return this->self->init_call(args...);
					}
			};

			class func_ptr: public func_base{
				public:
					func_ptr(gl_function<Ret(Args...)> *self_)
						: func_base{self_}{}

					Ret operator()(Args ... args){
						return this->self->fptr(args...);
					}
			};

			func_base *fn = new func_init{this};
	};
}

#endif // GAPI_GAPI_HPP
