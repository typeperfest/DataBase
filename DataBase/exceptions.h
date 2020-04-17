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

class empty_name_exception : protected std::exception
{
public:
	const char* what()
	{
		return "You cannot apply a command with empty name";
	}
};

class no_such_file : protected std::exception
{
public:
	const char* what()
	{
		return "There is no such file";
	}
};