#pragma once
#include <exception>

class SYSTEM_OF_BASE_CONTROL_EXCEPTION : protected std::exception
{
public:
	virtual const char* what() = 0;
};

class invalid_command_exception : public SYSTEM_OF_BASE_CONTROL_EXCEPTION
{
public:
	const char* what()
	{
		return "Error: invalid command, try again";
	}
};

class empty_name_exception : public SYSTEM_OF_BASE_CONTROL_EXCEPTION
{
public:
	const char* what()
	{
		return "Error: you cannot apply a command with empty name";
	}
};

class no_such_file_exception : public SYSTEM_OF_BASE_CONTROL_EXCEPTION
{
public:
	const char* what()
	{
		return "Error: there is no such file with that name";
	}
};

class already_exists_exception : public SYSTEM_OF_BASE_CONTROL_EXCEPTION
{
public:
	const char* what()
	{
		return "Error: file with such name already exists";
	}
};

class doesnt_opened_exception : public SYSTEM_OF_BASE_CONTROL_EXCEPTION
{
public:
	const char* what()
	{
		return "Error: there is no opened database";
	}
};