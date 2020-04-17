#pragma once
#include <iostream>
#include <string>


// cf == console functions 
namespace cf
{
	void helpToKnowCommands();
	void createDataBase(std::string& basename, bool type);
	void printBasesList();
	void deleteBase(std::string& basename);
}
