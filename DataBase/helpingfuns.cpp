#include "helpingfunctions.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "exceptions.h"

#define BEGCOM std::cout << ">> "

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
	returningFac->setType("1");
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
	returningFac->setType("0");
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

void helpingfuncs::saveCollection(std::ofstream& file, std::map<std::string, std::map<std::string, int>>& list)
{
	file << '{' << ' ';
	for (auto& iter_1 : list)
	{
		file << '{' << ' ';
		file << iter_1.first << ' ';
		std::map<std::string, int> lowerList = iter_1.second;
		for (auto& iter_2 : lowerList)
		{
			file << '{' << ' ' << iter_2.first << ' ' << iter_2.second << ' ' << '}' << ' ';
		}
		file << '}' << ' ';
	}
	file << '}' << ' ';
}

std::map<std::string, std::map<std::string, int>> helpingfuncs::enterCollection()
{
	std::map<std::string, std::map<std::string, int>> bigMap;
	while (true)
	{
		try
		{
			std::cout << "Now enter number of departments in faculty." << std::endl;
			BEGCOM;
			int numberOfDeps;
			std::cin >> numberOfDeps;
			if (numberOfDeps == 0)
			{
				std::cout << "You sure there is no any departments? Y/n" << std::endl;
				BEGCOM;
				std::string command;
				std::cin >> command;
				if (command == "Y")
				{
					break;
				}
				else
				{
					std::cout << "  ...try again then...  " << std::endl;
					continue;
				}
			}
			else
			{
				for (int i = 1; i < numberOfDeps + 1; i++)
				{
					std::cout << "Enter name of " << i << " department" << std::endl;
					BEGCOM;
					std::string string;
					std::cin >> string;
					if (string == "")
					{
						SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
						throw exception;
					}
					std::cout << "Enter number of lessons in current department and after that \n enter";
					std::cout << " number of teachers teching this lesson in pair over the space.\n";
					BEGCOM;
					int numberOfLes;
					std::cin >> numberOfLes;
					std::map<std::string, int> lowerMap;
					for (int i = 0; i < numberOfLes; i++)
					{
						int numberOfTeachers;
						std::string lessonName;
						std::cin >> lessonName >> numberOfTeachers;
						lowerMap[lessonName] = numberOfTeachers;
					}
					std::cin.ignore();
					bigMap[string] = lowerMap;
					lowerMap.clear();
				}
				break;
			}
		}
		catch (SYSTEM_OF_BASE_CONTROL_EXCEPTION * ex)
		{
			std::cout << ex->what() << std::endl;
			std::cout << " ...try again... " << std::endl;
		}
	}
	return bigMap;
}