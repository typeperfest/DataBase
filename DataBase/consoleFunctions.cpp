#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>


#include "exceptions.h"
#include "consoleFunctions.h"
#include "helpingfunctions.h"

#define BEGCOM std::cout << ">> ";
#define NOOP std::cout << "Options: None" << std::endl << std::endl
#define DBJMP std::endl << std::endl

void cf::helpToKnowCommands()
{
	// Create
	std::cout << "create <option> <string> - creates new data base with name <string>" << std::endl;
	std::cout << "options:" << std::endl;
	std::cout << "           :hybrid - database will be hybrid" << std::endl;
	std::cout << "           without option - database will be same-type" << DBJMP;
	// Print_Base_List
	std::cout << "print_base_list - prints all available databases" << std::endl;
	NOOP;
	// Delete_Base
	std::cout << "delete_base <basename> - deletes database forever" << std::endl;
	NOOP;
	// Rename
	std::cout << "rename <basename> <string> - renames database with new name <string>" << std::endl;
	NOOP;
	// Open
	std::cout << "open <basename> - open database to work in" << std::endl;
	NOOP;
	// Save
	std::cout << "save <basename> - save databse for continue using" << std::endl;
	NOOP;
	// Add
	std::cout << "add <basename> <option> <string>  - add new note with name <string>" << std::endl;
	std::cout << "options:" << std::endl;
	std::cout << "           :sh - switch databse to hybrid" << std::endl;
	std::cout << "           without option - withot switching" << DBJMP;
	// Edit
	std::cout << "edit <basename> - edit existing database" << std::endl;
	NOOP;
	// Delete_Note
	std::cout << "delete_note <basename> <notename> - deletes note with name <notename>" << std::endl;
	NOOP;
	// Print_Notes
	std::cout << "print_notes <basename> - prints all notes from database" << std::endl;
	NOOP;
	// Sort
	std::cout << "sort <basename> <option> - sorts all notes in database" << std::endl;
	std::cout << "options:" << std::endl;
	std::cout << "           :byname - sort by name by alphabet" << std::endl;
	std::cout << "           :bdnumber - sort by number of departments " << std::endl;
	std::cout << "           you must choose one option" << DBJMP;
	// Choose
	std::cout << "choose <options> <string> - choose notes by rule of option" << std::endl;
	std::cout << "options:" << std::endl;
	std::cout << "           :byles - choose by name of lesson this dep teaches" << std::endl;
	std::cout << "           :mn - choose all notes had more than n deps " << std::endl;
	std::cout << "           you must choose one option" << DBJMP;
	// Transmit_New_Base
	std::cout << "transmit_new_base <string> - transmits last result of command \"Choose\"" <<
		" into a new database with name <string>" << std::endl;
	NOOP;
}

void cf::createDataBase(std::string& basename, bool type)
{
	std::string nameForCheck = "Bases\\" + basename + ".txt";
	namespace fs = std::experimental::filesystem;
	bool isFileExist = fs::exists(fs::status(nameForCheck));
	if (!isFileExist)
	{

		std::string fileName = "Bases/" + basename + ".txt";
		std::ofstream baseFile;
		baseFile.open(fileName);
		baseFile << basename;
		baseFile.close();
		std::cout << "DataBase " << basename << " has been created successfully" << std::endl;
	}
	else
	{
		SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new already_exists_exception;
		throw exception;
	}
}

void cf::printBasesList()
{
	std::cout << "Saved databases: " << std::endl;
	bool isThereAny = false;
	for (auto& iter : std::experimental::filesystem::directory_iterator("Bases"))
	{
		isThereAny = true;
		std::cout << "   " << iter.path().filename() << std::endl;
	}
	if (!isThereAny)
	{
		std::cout << "There is no any saved databses" << std::endl;
	}
}

void cf::deleteBase(std::string& basename)
{
	basename = "Bases\\" + basename;
	namespace fs = std::experimental::filesystem;
	bool isFileExist = fs::exists(fs::status(basename));
	if (isFileExist)
	{
		std::experimental::filesystem::remove(basename);
		std::cout << "Data base " << basename << " has been successfully removed" << std::endl;
	}
	else
	{
		SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new no_such_file_exception;
		throw exception;
	}
}

void cf::renamebase(std::string& oldbasename, std::string& newbasename)
{
	oldbasename = "Bases/" + oldbasename;
	newbasename = "Bases/" + newbasename;
	namespace fs = std::experimental::filesystem;
	bool isFileExist = fs::exists(fs::status(oldbasename));
	if (isFileExist)
	{
		bool isFileExist = fs::exists(fs::status(newbasename));
		if (!isFileExist)
		{
			fs::rename(oldbasename, newbasename);
			std::cout << "File " << oldbasename << " has been successfully renamed to "
				<< newbasename << std::endl;
		}
		else
		{
			SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new already_exists_exception;
			throw exception;
		}
	}
	else
	{
		SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new no_such_file_exception;
		throw exception;
	}
}



std::vector<Faculty_Abstract*> cf::openBase(std::string& basename)
{
	std::cout << "you got to the openbase" << std::endl;
	namespace fs = std::experimental::filesystem;
	basename = "Bases/" + basename;
	bool isFileExist = fs::exists(fs::status(basename));
	if (isFileExist)
	{
		std::vector<Faculty_Abstract*> returningVector;
		std::ifstream file;
		file.open(basename);
		int notesNumber;
		file >> notesNumber;
		Faculty_Abstract* newFaculty;
		for (int i = 0; i < notesNumber; i++)
		{
			newFaculty = helpingfuncs::get_one_faculty(file);
			returningVector.push_back(newFaculty);
		}
		return returningVector;
	}
	else
	{
		SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new no_such_file_exception;
		throw exception;
	}
}