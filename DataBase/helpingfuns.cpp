#include "helpingfunctions.h"
#include <fstream>
#include <vector>

std::map<std::string, std::map<std::string, int>> getCollection(std::ifstream& file)
{
	std::vector<std::string> brackets;
	std::string mainstring;
	file >> mainstring;
	if (mainstring == "{")
	{
		brackets.push_back(mainstring);
	}
	int level = 1;
	std::string string_object;
	std::map<std::string, int> smallmap;
	std::string firstword = string_object;
	std::map<std::string, std::map<std::string, int>> bigmap;
	std::string key;
	bool secondstring = false;
	while (!brackets.empty())
	{
		file >> string_object;
		if (string_object == "{")
		{
			brackets.push_back(string_object);
			level++;
			continue;
		}
		if (string_object == "}")
		{
			brackets.pop_back();
			if (level == 2)
			{
				bigmap[key] = smallmap;
				smallmap.clear();
				key = "";
			}
			level--;
			continue;
		}
		switch (level)
		{
		case 2:
		{
			key = string_object;
			break;
		}
		case 3:
		{
			if (!secondstring)
			{
				firstword = string_object;
				secondstring = true;
			}
			else
			{
				int numberofprepods = stoi(string_object);
				smallmap[firstword] = numberofprepods;
				secondstring = false;
			}
			break;
		}
		default:
			break;
		}
	}
	return bigmap;
}

Basic_Faculty* readBasFac(std::ifstream& file)
{
	Basic_Faculty* returningFac = new Basic_Faculty;
	std::string facname, sciencecenter;
	int depnumber;
	file >> facname >> sciencecenter >> depnumber;
	returningFac->setName(facname);
	returningFac->setSciCen(sciencecenter);
	returningFac->setNumOfDeps(depnumber);
	std::map<std::string, std::map<std::string, int>> deplist;
	deplist = getCollection(file);
	returningFac->setList(deplist);
	return returningFac;
}

Branch_Faculty* readBrFac(std::ifstream& file)
{
	Branch_Faculty* returningFac = new Branch_Faculty;
	std::string facname, sciencecenter;
	int depnumber;
	file >> facname >> sciencecenter >> depnumber;
	returningFac->setName(facname);
	returningFac->setSciCen(sciencecenter);
	returningFac->setNumOfDeps(depnumber);
	std::map<std::string, std::map<std::string, int>> deplist, brDepList;
	deplist = getCollection(file);
	returningFac->setList(deplist);
	brDepList = getCollection(file);
	returningFac->setBrDepList(brDepList);
	return returningFac;
}

Faculty_Abstract* helpingfuncs::get_one_faculty(std::ifstream& file)
{
	int type;
	file >> type;
	Faculty_Abstract* returningFac;
	if (type == 1)
	{
		Basic_Faculty* faculty = readBasFac(file);
		returningFac = faculty;
	}
	else
	{
		Branch_Faculty* faculty = readBrFac(file);
		returningFac = faculty;
	}
	return returningFac;
}

