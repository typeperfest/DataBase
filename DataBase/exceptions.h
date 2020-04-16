#pragma once
#include <exception>

class invalid_command_exception : protected std::exception
{
public:
	const char* what()
	{
		return "Invalid command, try again";
	}
};