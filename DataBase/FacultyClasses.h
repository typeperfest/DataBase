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
	virtual void setName(std::string& string);
	virtual std::string getSciCen();
	virtual void setSciCen(std::string string);
	virtual int getNumOfDeps();
	virtual void setNumOfDeps(const int& value);
	virtual std::map<std::string, std::map<std::string, int>> getList();
	virtual void setList(std::map<std::string, std::map<std::string, int>> list);
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