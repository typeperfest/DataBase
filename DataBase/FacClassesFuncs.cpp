#include "FacultyClasses.h"

//_____________FACULTY_ABSTRACT_______________

std::string Faculty_Abstract::getName()
{
	return facultyName;
}

std::string Faculty_Abstract::getSciCen()
{
	return ScienceCenter;
}

int Faculty_Abstract::getNumOfDeps()
{
	return number_of_deps;
}

std::map<std::string, std::map<std::string, int>> Faculty_Abstract::getList()
{
	return depList;
}

//______________BASIC_FACULTY__________________

int Basic_Faculty::numberOfLess()
{
	int number = 0;
	for (auto& iter : depList)
	{
		number += iter.second.size();
	}
	return number;
}

//______________BRANCH_FACULTIES________________

int Branch_Faculty::numberOfLess()
{
	int number = 0;
	for (auto& iter : depList)
	{
		number += iter.second.size();
	}
	number += branchDepList.size();
	return number;
}

std::map<std::string, std::string> Branch_Faculty::getBrDepList()
{
	return branchDepList;
}