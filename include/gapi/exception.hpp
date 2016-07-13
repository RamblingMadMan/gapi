#ifndef GAPI_EXCEPTION_HPP
#define GAPI_EXCEPTION_HPP 1

#include <exception>
#include <string>

namespace gapi{
	class gapi_error: public std::exception{
		public:
			gapi_error(std::string err)
				: m_err{err}{}

			const char *what() const noexcept{ return m_err.c_str(); }

		private:
			std::string m_err;
	};
}

#endif // GAPI_EXCEPTION_HPP
