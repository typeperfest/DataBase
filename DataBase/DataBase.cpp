#include <iostream>
#include <string>
#include <set>
#include <exception>

#define BEGCOM std::cout << ">> ";
#define NOOP std::cout << "Options: None" << std::endl << std::endl
#define DBJMP std::endl << std::endl

class invalid_command_exception : protected std::exception 
{
public:
	const char* what()
	{
		return "Invalid command, try again";
	}
};

void helpToKnowCommands()
{
	std::set<std::string> commandsSet = { "Create", "Print_Base_List", "Delete_Base", "Rename",
										  "Open", "Save", "Add", "Edit", "Delete_Note", 
		                                  "Print_Notes", "Sort", "Choose", "Transmit_New_Base" };
	// Create
	std::cout << "Create <option> <string> - creates new data base with name <string>" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "           :hybrid - database will be hybrid" <<
		std::endl << "           :s_type - database will be same-type" << std::endl;
	std::cout << "           without option - database will be same-type" << DBJMP;
	// Print_Base_List
	std::cout << "Print_Base_List - prints all available databases" << std::endl;
	NOOP;
	// Delete_Base
	std::cout << "Delete_Base <basename> - deletes database forever" << std::endl;
	NOOP;
	// Rename
	std::cout << "Rename <basename> <string> - renames database with new name <string>" << std::endl;
	NOOP;
	// Open
	std::cout << "Open <basename> - open database to work in" << std::endl;
	NOOP;
	// Save
	std::cout << "Save <basename> - save databse for continue using" << std::endl;
	NOOP;
	// Add
	std::cout << "Add <basename> <option> <string>  - add new note with name <string>" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "           :sh - switch databse to hybrid" << std::endl;
	std::cout << "           without option - withot switching" << DBJMP;
	// Edit
	std::cout << "Edit <basename> - edit existing database" << std::endl;
	NOOP;
	// Delete_Note
	std::cout << "Delete_Note <basename> <notename> - deletes note with name <notename>" << std::endl;
	NOOP;
	// Print_Notes
	std::cout << "Print_Notes <basename> - prints all notes from database" << std::endl;
	NOOP;
	// Sort
	std::cout << "Sort <basename> <option> - sorts all notes in database" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "           :byname - sort by name by alphabet" << std::endl;
	std::cout << "           :bdnumber - sort by number of departments " << std::endl;
	std::cout << "           you must choose one option" << DBJMP;
	// Choose
	std::cout << "Choose <options> <string> - choose notes by rule of option" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "           :byles - choose by name of lesson this dep teaches" << std::endl;
	std::cout << "           :mn - choose all notes had more than n deps " << std::endl;
	std::cout << "           you must choose one option" << DBJMP;
	// Transmit_New_Base
	std::cout << "Transmit_New_Base <string> - transmits last result of command \"Choose\"" <<
		" into a new database with name <string>" << std::endl;
	NOOP;
} 

int main()
{
	std::cout << "Welcome, username. This is DataBase of university." << std::endl << std::endl;
	std::cout << "You can interact with database by list of commands." << std::endl;
	std::cout << ">> Type \"Help\" to see list of commands." << std::endl;
	BEGCOM
	while(true)
	{
		try
		{
			std::string command;
			std::cin >> command;
			if (command == "Help")
			{
				helpToKnowCommands();
			}
			else if (command == "Create")
			{


			}
			else if (command == "Print_Base_List")
			{


			}
			else if (command == "Delete_Base")
			{


			}
			else if (command == "Rename")
			{


			}
			else if (command == "Open")
			{


			}
			else if (command == "Save")
			{


			}
			else if (command == "Add")
			{


			}
			else if (command == "Edit")
			{


			}
			else if (command == "Delete_Note")
			{


			}
			else if (command == "Print_Notes")
			{


			}
			else if (command == "Sort")
			{

			}
			else if (command == "Choose")
			{

			}
			else if (command == "Transmit_New_Base")
			{

			}
			else if (command == "Exit")
			{

				break;
			}
			else
			{
				invalid_command_exception exception;
				throw exception;
			}
			BEGCOM
		}
		catch (invalid_command_exception ex)
		{
			std::cout << ex.what() << std::endl;
			BEGCOM
		}
	}
	return 0;
}

