#pragma once
#include <exception>

class invalid_command_exception : protected std::exception
{
public:
	const char* what()
	{
		return "Error: invalid command, try again";
	}
};

class empty_name_exception : protected std::exception
{
public:
	const char* what()
	{
		return "Error: you cannot apply a command with empty name";
	}
};

class no_such_file : protected std::exception
{
public:
	const char* what()
	{
		return "Error: there is no such file with that name";
	}
};

class already_exists : protected std::exception
{
public:
	const char* what()
	{
		return "Error: file with such name already exists";
	}
};