#pragma once
#include <vector>
#include <iostream>
#include <string>

#include "FacultyClasses.h"

// cf == console functions 
namespace cf
{
	void helpToKnowCommands();
	void createDataBase(std::string& basename, bool type);
	void printBasesList();
	void deleteBase(std::string& basename);
	void renamebase(std::string& oldbasename, std::string& newbasename);
	std::vector<Faculty_Abstract*> openBase(std::string& basename);
	void saveBase(std::vector<Faculty_Abstract*>& openedBase, std::string& basename);
}
