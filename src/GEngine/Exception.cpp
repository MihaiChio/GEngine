#include "Exception.h"

namespace GEngine
{
	Exception::Exception(const std::string& _message)
	{
		this->message = _message;
	}
	Exception::~Exception() throw() {};
	const char* Exception::what() const throw()
	{
		return message.c_str();
	}
}