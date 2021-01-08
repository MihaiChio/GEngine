#ifndef GEngine_EXCEPTION_H
#define GEngine_EXCEPTION_H

#include <exception>
#include <string>

namespace GEngine
{
	struct Exception : public std::exception
	{
		Exception(const std::string& _message);
		virtual ~Exception() throw();
		virtual const char* what() const throw();
	private:
		std::string message;
	};
}
#endif