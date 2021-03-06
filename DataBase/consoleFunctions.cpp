#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <exception>

#include "exceptions.h"
#include "consoleFunctions.h"
#include "helpingfunctions.h"

#define BEGCOM std::cout << ">> "
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
	std::cout << "add - add new note to current opened data base" << std::endl;
	NOOP;
	// Edit
	std::cout << "edit - edit current opened database" << std::endl;
	NOOP;
	// Delete_Note
	std::cout << "delete_note <basename> <notename> - deletes note with name <notename>" << std::endl;
	NOOP;
	// Print_Notes
	std::cout << "print_notes <basename> - prints all notes from current opened database" << std::endl;
	NOOP;
	// Sort
	std::cout << "sort <option> <inc/dec>- sorts all notes in current opened database" << std::endl;
	std::cout << "options:" << std::endl;
	std::cout << "           :byname - sort by name by alphabet" << std::endl;
	std::cout << "           :bdnumber - sort by number of departments " << std::endl;
	std::cout << "           you must choose one option" << DBJMP;
	// Choose
	std::cout << "choose <option>  - choose notes by rule of option in current opened database" << std::endl;
	std::cout << "options:" << std::endl;
	std::cout << "           :byles - choose by name of lesson this dep teaches" << std::endl;
	std::cout << "           :mn - choose all notes had more than n deps " << std::endl;
	std::cout << "           you must choose one option" << DBJMP;
	// Transmit_New_Base
	std::cout << "transmit_new_base <string> - transmits last result of command \"Choose\"" <<
		" into a new database with name <string>" << std::endl;
	NOOP;
}

void cf::createDataBase(std::string basename, bool type)
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
		std::cout << "   ...Got " << notesNumber << " notes..." << std::endl;
		std::cout << "   Base opened successfully." << std::endl;
		return returningVector;
	}
	else
	{
		SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new no_such_file_exception;
		throw exception;
	}
}

void cf::saveBase(std::vector<Faculty_Abstract*>& openedBase, std::string& basename)
{
	namespace fs = std::experimental::filesystem;
	basename = "Bases/" + basename + ".txt";
	bool isFileExist = fs::exists(fs::status(basename));
	if (isFileExist)
	{
		std::ofstream file;
		file.open(basename);
		int baseSize = openedBase.size();
		file << baseSize << std::endl;
		for (int i = 0; i < baseSize; i++)
		{
			Faculty_Abstract* currentNote = openedBase[i];
			file << currentNote->getType() << ' ' << currentNote->getName() << ' '
				<< currentNote->getSciCen() << ' ' << currentNote->getNumOfDeps() << ' ';
			std::map<std::string, std::map<std::string, int>> list = currentNote->getList();
			helpingfuncs::saveCollection(file, list);
			if (currentNote->getType() == "0")
			{
				list = currentNote->getBrDepList();
				helpingfuncs::saveCollection(file, list);
			}
			file << '\n';
		}
		file.close();
		std::cout << "Base saved successfully in file " << basename << std::endl;
	}
	else
	{
		SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new no_such_file_exception;
		throw exception;
	}
}

Faculty_Abstract* cf::createNote()
{
	Faculty_Abstract* returningFac;
	std::cout << "  ***Warning! You should enter without spaces!***\n" << std::endl;
	while (true)
	{
		try
		{
			std::cout << "Enter \"1\" if you want to faculty be a basic, or \"0\" to be a branch.\n";
			std::cout << ">> ";
			std::string command;
			std::cin >> command;
			if (command == "1")
			{
				returningFac = new Basic_Faculty;
				returningFac->setType("1");
				break;
			}
			else if (command == "0")
			{
				returningFac = new Branch_Faculty;
				returningFac->setType("0");
				break;
			}
			else
			{
				SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
				throw exception;
			}
		}
		catch (SYSTEM_OF_BASE_CONTROL_EXCEPTION* ex)
		{
			std::cout << ex->what() << std::endl;
			std::cout << " ...try again... " << std::endl;
		}
	}
	while (true)
	{
		try
		{
			std::cout << "Enter name of faculty. \n";
			std::cout << ">> ";
			std::string command;
			std::cin >> command;
			if (command == "")
			{
				SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
				throw exception;
			}
			else
			{
				returningFac->setName(command);
				break;
			}
		}
		catch (SYSTEM_OF_BASE_CONTROL_EXCEPTION * ex)
		{
			std::cout << ex->what() << std::endl;
			std::cout << " ...try again... " << std::endl;
		}
	}
	while (true)
	{
		try
		{
			std::cout << "Enter name of science center. \n";
			std::cout << ">> ";
			std::string command;
			std::cin >> command;
			if (command == "")
			{
				SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
				throw exception;
			}
			else
			{
				returningFac->setSciCen(command);
				break;
			}
		}
		catch (SYSTEM_OF_BASE_CONTROL_EXCEPTION * ex)
		{
			std::cout << ex->what() << std::endl;
			std::cout << " ...try again... " << std::endl;
		}
	}
	std::map<std::string, std::map<std::string, int>> bigMap;
	bigMap = helpingfuncs::enterCollection();
	returningFac->setList(bigMap);
	int numberOfDeps = bigMap.size();
	returningFac->setNumOfDeps(numberOfDeps);
	if (returningFac->getType() == "0")
	{
		std::map<std::string, std::map<std::string, int>> bigBrMap;
		bigBrMap = helpingfuncs::enterCollection();
		returningFac->setBrDepList(bigBrMap);
	}
	std::cout << "Note with name \"" << returningFac->getName() << "\" has been created successfully."
		<< std::endl;
	return returningFac;
}

void cf::editNote(std::vector<Faculty_Abstract*>& openedBase)
{
	while (true)
	{
		try
		{
			int notesNumber = openedBase.size();
			std::cout << "There is " << notesNumber << " notes." << std::endl;
			for (int i = 0; i < notesNumber; i++)
			{
				std::cout << "Note with number " << i << std::endl;
				std::cout << "     Name of note: " << openedBase[i]->getName() << std::endl;
			}
			std::cout << "Select wich note you want to edit\nand enter number of this note" << std::endl;
			BEGCOM;
			int numberOfEditingNote;
			std::string enteringString;
			std::cin >> enteringString;
			numberOfEditingNote = stoi(enteringString);
			if (numberOfEditingNote < 0 || numberOfEditingNote > notesNumber - 1)
			{
				SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
				throw exception;
			}
			Faculty_Abstract* newNote;
			newNote = cf::createNote();
			openedBase[numberOfEditingNote] = newNote;
			std::cout << "Note in base has been changed successfully." << std::endl;
			break;
		}
		catch (SYSTEM_OF_BASE_CONTROL_EXCEPTION * ex)
		{
			std::cout << ex->what() << std::endl;
			std::cout << "  ...try again...  " << std::endl;
		}
		catch (std::invalid_argument ex)
		{
			std::cout << " *ENTER A STRING CONVERTABLE TO NUMBER* " << std::endl;
			std::cout << "  ...try again...  " << std::endl;
		}
	}
}

void cf::deleteNote(std::vector<Faculty_Abstract*>& openedBase)
{
	while (true)
	{
		try
		{
			int notesNumber = openedBase.size();
			std::cout << "There are " << notesNumber << " notes." << std::endl;
			for (int i = 0; i < notesNumber; i++)
			{
				std::cout << "Note with number " << i << std::endl;
				std::cout << "     Name of note: " << openedBase[i]->getName() << std::endl;
			}
			std::cout << "Select wich note you want to delete\nand enter number of this note" << std::endl;
			BEGCOM;
			int numberOfDeletingNote;
			std::string enteringString;
			std::cin >> enteringString;
			numberOfDeletingNote = stoi(enteringString);
			if (numberOfDeletingNote < 0 || numberOfDeletingNote > notesNumber - 1)
			{
				SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
				throw exception;
			}
			openedBase.erase(openedBase.begin() + numberOfDeletingNote);
			std::cout << "Note in base has been deleted successfully." << std::endl;
			std::cin.ignore();
			break;
		}
		catch (SYSTEM_OF_BASE_CONTROL_EXCEPTION * ex)
		{
			std::cout << ex->what() << std::endl;
			std::cout << "  ...try again...  " << std::endl;
		}
		catch (std::invalid_argument ex)
		{
			std::cout << " *ENTER A STRING CONVERTABLE TO NUMBER* " << std::endl;
			std::cout << "  ...try again...  " << std::endl;
		}
	}
}

void cf::printNotes(std::vector<Faculty_Abstract*>& openedBase)
{
	int notesNumber = openedBase.size();
	std::cout << "There are " << notesNumber << " notes." << std::endl;
	for (int i = 0; i < notesNumber; i++)
	{
		Faculty_Abstract* currentNote = openedBase[i];
		std::cout << "Note with number " << i << std::endl;
		std::cout << "\tType of faculty: ";
		if (currentNote->getType() == "1") std::cout << "Basic" << std::endl;
		else std::cout << "Branch" << std::endl;
		std::cout << "\tName of faculty: " << currentNote->getName() << std::endl;
		std::cout << "\tScience center of faculty: " << currentNote->getSciCen() << std::endl;
		std::cout << "\tNumber of departments of faculty: "
			<< currentNote->getNumOfDeps() << std::endl;
		std::cout << "\tList of departments: " << std::endl;
		for (auto& iter_1 : currentNote->getList())
		{
			std::cout << "\t\tDepartment " << iter_1.first << ':' << std::endl;
			for (auto& iter_2 : iter_1.second)
			{
				std::cout << "\t\t\tLessson: " << iter_2.first
					<< " Teachers: " << iter_2.second << std::endl;
			}
		}
		if (currentNote->getType() == "0")
		{
			std::cout << "\tList of branch departments: " << std::endl;
			for (auto& iter_1 : currentNote->getBrDepList())
			{
				std::cout << "\t\tDepartment " << iter_1.first << ':' << std::endl;
				for (auto& iter_2 : iter_1.second)
				{
					std::cout << "\t\t\tLessson: " << iter_2.first
						<< " Teachers: " << iter_2.second << std::endl;
				}
			}
		}
	}
}

bool byNameSortingFunction_inc(Faculty_Abstract* i, Faculty_Abstract* j)
{
	return (i->getName() < j->getName());
}

bool byNameSortingFunction_dec(Faculty_Abstract* i, Faculty_Abstract* j)
{
	return (i->getName() > j->getName());
}

void cf::sortByName(std::vector<Faculty_Abstract*>& openedBase, const bool& direction)
{
	if (direction) std::sort(openedBase.begin(), openedBase.end(), byNameSortingFunction_inc);
	else std::sort(openedBase.begin(), openedBase.end(), byNameSortingFunction_dec);
	std::cout << "Notes have been sorted successfully by names. " << std::endl;
	std::cout << "\t \"print_notes\" to check" << std::endl;
}

bool ByNumberSortingFunction_inc(Faculty_Abstract* i, Faculty_Abstract* j)
{
	return (i->getNumOfDeps() < j->getNumOfDeps());
}

bool ByNumberSortingFunction_dec(Faculty_Abstract* i, Faculty_Abstract* j)
{
	return (i->getNumOfDeps() > j->getNumOfDeps());
}

void cf::sortByBdNumber(std::vector<Faculty_Abstract*>& openedBase, const bool& direction)
{
	if (direction) std::sort(openedBase.begin(), openedBase.end(), ByNumberSortingFunction_inc);
	else std::sort(openedBase.begin(), openedBase.end(), ByNumberSortingFunction_dec);
	std::cout << "Notes have been sorted successfully by numbers of departents. " << std::endl;
	std::cout << "\t \"print_notes\" to check" << std::endl;
}

std::vector<Faculty_Abstract*> cf::chooseNotes(std::vector<Faculty_Abstract*>& openedBase, const bool& rule)
{
	// rule == true == by lesson
	// rule == false == more than n deps
	std::vector<Faculty_Abstract*> returningVector;
	int numberOfNotes = openedBase.size();
	if (rule)
	{
		std::cout << "Enter name of lesson needed in note to be choosen, without spaces" << std::endl;
		BEGCOM;
		std::string lesson;
		std::cin >> lesson;
		std::cin.ignore();
		for (int i = 0; i < numberOfNotes; i++)
		{
			bool higherBreak;
			std::map<std::string, std::map<std::string, int>> bigList = openedBase[i]->getList();
			for (auto& iter_1 : bigList)
			{
				higherBreak = false;
				std::map<std::string, int> smallList = iter_1.second;
				for (auto& iter_2 : smallList)
				{
					if (iter_2.first == lesson)
					{
						returningVector.push_back(openedBase[i]);
						higherBreak = true;
						break;
					}
				}
				if (higherBreak) break;
			}
			if (openedBase[i]->getType() == "0")
			{
				bool higherBreak;
				std::map<std::string, std::map<std::string, int>> bigList = openedBase[i]->getBrDepList();
				for (auto& iter_1 : bigList)
				{
					higherBreak = false;
					std::map<std::string, int> smallList = iter_1.second;
					for (auto& iter_2 : smallList)
					{
						if (iter_2.first == lesson)
						{
							returningVector.push_back(openedBase[i]);
							higherBreak = true;
							break;
						}
					}
					if (higherBreak) break;
				}
			}
		}
		std::cout << "Notes has been chosen successfully. " << std::endl;
		return returningVector;
	}
	else
	{
		std::cout << "Enter number of deaprtments in note to be choosen" << std::endl;
		BEGCOM;
		std::string enteredString;
		int deps;
		std::cin >> enteredString;
		std::cin.ignore();
		while (true)
		{
			try
			{
				deps = stoi(enteredString);
				break;
			}
			catch (std::invalid_argument)
			{
				std::cout << " *ENTER A STRING CONVERTABLE TO NUMBER* " << std::endl;
				std::cout << "  ...try again...  " << std::endl;
			}
		}
		for (int i = 0; i < numberOfNotes; i++)
		{
			if (openedBase[i]->getNumOfDeps() > deps)
			{
				returningVector.push_back(openedBase[i]);
			}
		}
		std::cout << "Notes has been chosen successfully. " << std::endl;
		return returningVector;
	}
}

Faculty_Abstract* cf::findNote(std::vector<Faculty_Abstract*>& openedBase, std::string& noteName)
{
	int numberOfNotes = openedBase.size();
	for (int i = 0; i < numberOfNotes; i++)
	{
		if (openedBase[i]->getName() == noteName)
		{
			return openedBase[i];
		}
	}
}