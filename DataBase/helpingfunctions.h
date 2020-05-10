#pragma once
#include "FacultyClasses.h"

namespace helpingfuncs
{
	Faculty_Abstract* get_one_faculty(std::ifstream& file);
	void saveCollection(std::ofstream& file, std::map<std::string, std::map<std::string, int>>& list);
	std::map<std::string, std::map<std::string, int>> enterCollection();
}
