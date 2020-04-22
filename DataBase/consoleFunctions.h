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
	void renamebase(std::string& oldbasename, std::string& newbasename);
	void openBase(std::string& basename);
}
