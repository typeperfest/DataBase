#include <iostream>
#include <string>
#include <set>
#include <exception>

#define BEGCOM std::cout << ">> ";
#define NOOP std::cout << "Options: None" << std::endl << std::endl;
#define DBJMP std::cout << std::endl << std::endl;

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
	std::cout << "Create <string> <option> - creates new data base" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "           :hybrid - database will be hybrid" <<
		std::endl << "           :s_type - database will be same-type";
	DBJMP
	// Print_Base_List
	std::cout << "Print_Base_List - prints all available databases" << std::endl;
	NOOP
	// Delete_Base
	std::cout << "Delete_Base <basename> - deletes database forever" << std::endl;
	NOOP
	// Rename
	std::cout << "Rename <basename> - renames database" << std::endl;
	NOOP
	std::cout << "Open <basename> - open database to work in" << std::endl;
	NOOP
	std::cout << "Save <basename> - save databse for continue using" << std::endl;
	NOOP

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
				BEGCOM
			}
			else if (command == "Create")
			{

				BEGCOM
			}
			else if (command == "Print_Base_List")
			{

				BEGCOM
			}
			else if (command == "Delete_Base")
			{

				BEGCOM
			}
			else if (command == "Rename")
			{

				BEGCOM
			}
			else if (command == "Open")
			{

				BEGCOM
			}
			else if (command == "Save")
			{

				BEGCOM
			}
			else if (command == "Add")
			{

				BEGCOM
			}
			else if (command == "Edit")
			{

				BEGCOM
			}
			else if (command == "Delete_Note")
			{

				BEGCOM
			}
			else if (command == "Print_Notes")
			{

				BEGCOM
			}
			else if (command == "Sort")
			{

				BEGCOM
			}
			else if (command == "Choose")
			{

				BEGCOM
			}
			else if (command == "Transmit_New_Base")
			{

				BEGCOM
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
		}
		catch (invalid_command_exception ex)
		{
			std::cout << ex.what() << std::endl;
			BEGCOM
		}
	}
	return 0;
}

