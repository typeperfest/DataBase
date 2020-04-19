#pragma once
#include <exception>

class SYSTEM_OF_BASE_CONTROL_EXCEPTION : protected std::exception
{
public:
	virtual const char* what()
	{
		return "Unknown exception";
	}
};

class invalid_command_exception : protected SYSTEM_OF_BASE_CONTROL_EXCEPTION
{
public:
	const char* what()
	{
		return "Error: invalid command, try again";
	}
};

class empty_name_exception : protected SYSTEM_OF_BASE_CONTROL_EXCEPTION
{
public:
	const char* what()
	{
		return "Error: you cannot apply a command with empty name";
	}
};

class no_such_file : protected SYSTEM_OF_BASE_CONTROL_EXCEPTION
{
public:
	const char* what()
	{
		return "Error: there is no such file with that name";
	}
};

class already_exists : protected SYSTEM_OF_BASE_CONTROL_EXCEPTION
{
public:
	const char* what()
	{
		return "Error: file with such name already exists";
	}
};