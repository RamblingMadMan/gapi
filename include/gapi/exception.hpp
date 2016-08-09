#ifndef GAPI_EXCEPTION_HPP
#define GAPI_EXCEPTION_HPP 1

#include <stdexcept>
#include <exception>
#include <string>

#include "types.hpp"

namespace gapi{
	class gapi_error: public std::runtime_error{
		public:
			template<typename ... Args>
			gapi_error(Args &&... args)
				: std::runtime_error(std::forward<Args>(args)...){}

			const char *what() const noexcept{ return m_err.c_str(); }

		private:
			std::string m_err;
	};
}

#endif // GAPI_EXCEPTION_HPP
