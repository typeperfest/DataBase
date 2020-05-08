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

void Faculty_Abstract::setName(std::string& string)
{
	this->facultyName = string;
}

void Faculty_Abstract::setSciCen(std::string& string)
{
	this->ScienceCenter = string;
}

void Faculty_Abstract::setNumOfDeps(const int& value)
{
	this->number_of_deps = value;
}

void Faculty_Abstract::setList(std::map<std::string, std::map<std::string, int>> list)
{
	this->depList = list;
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

std::map<std::string, std::map<std::string, int>> Branch_Faculty::getBrDepList()
{
	return branchDepList;
}

void Branch_Faculty::setBrDepList(std::map<std::string, std::map<std::string, int>>& map)
{
	this->branchDepList = map;
}
