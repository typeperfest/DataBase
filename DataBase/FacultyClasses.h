#pragma once
#include <string>
#include <map>

class Faculty_Abstract
{
protected:
	std::string facultyName;
	std::string ScienceCenter;
	int number_of_deps;
	std::map<std::string, std::map<std::string, int>> depList;
public:
	virtual int numberOfless() = 0;
	virtual std::string getName();
	virtual std::string getSciCen();
	virtual int getNumOfDeps();
	virtual std::map<std::string, std::map<std::string, int>> getList();
};

class Basic_Faculty : public Faculty_Abstract
{
public:
	int numberOfLess();
};

class Branch_Faculty : protected Faculty_Abstract
{
	std::map<std::string, std::string> branchDepList;
public:
	int numberOfLess();
	std::map<std::string, std::string> getBrDepList();
};