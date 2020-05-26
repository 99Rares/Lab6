#include "Exception.h"

_Exception::_Exception(std::string e) {
	Error = e;
}
std::string _Exception::error_message() {
	std::string out = "Error: " + Error;
	return out;
}