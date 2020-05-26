#pragma once
#include <string>
class _Exception
{private:
	std::string Error;
public:
	// exceptii personalizate
	_Exception(std::string);

	std::string error_message();

	~_Exception() {}
};


