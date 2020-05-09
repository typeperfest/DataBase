#pragma once
#include <string>
#include <map>

class Faculty_Abstract
{
protected:
	std::string type;
	std::string facultyName;
	std::string ScienceCenter;
	int number_of_deps;
	std::map<std::string, std::map<std::string, int>> depList;
public:
	virtual int numberOfLess() = 0;
	virtual std::string getType();
	virtual void setType(const std::string& string);
	virtual std::string getName();
	virtual void setName(std::string& string);
	virtual std::string getSciCen();
	virtual void setSciCen(std::string& string);
	virtual int getNumOfDeps();
	virtual void setNumOfDeps(const int& value);
	virtual std::map<std::string, std::map<std::string, int>> getList();
	virtual void setList(std::map<std::string, std::map<std::string, int>> list);
	//______FOR_BRANCH_FACULTY______
	virtual std::map<std::string, std::map<std::string, int>> getBrDepList() = 0;
	virtual void setBrDepList(std::map<std::string, std::map<std::string, int>>& map) = 0;
};

class Basic_Faculty : public Faculty_Abstract
{
public:
	std::map<std::string, std::map<std::string, int>> getBrDepList();
	void setBrDepList(std::map<std::string, std::map<std::string, int>>& map);
	int numberOfLess();
};

class Branch_Faculty : public Faculty_Abstract
{
	std::map<std::string, std::map<std::string, int>> branchDepList;
public:
	int numberOfLess();
	std::map<std::string, std::map<std::string, int>> getBrDepList();
	void setBrDepList(std::map<std::string, std::map<std::string, int>>& map);
};