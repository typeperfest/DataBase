#include <iostream>
#include <string>
#include <exception>
#include "consoleFunctions.h"
#include "exceptions.h"


std::string getFirstWord(std::string& string)
{
	std::string returningString = "";
	int stringSize = string.size();
	int k = 1;
	while ((string[0] != ' ') && (k <= stringSize))
	{
		returningString += string[0];
		string.erase(0, 1);
		k++;
	}
	if (string[0] == ' ')
	{
		string.erase(0, 1);
	}
	return returningString;
}

int main()
{
	std::cout << "Welcome, username. This is DataBase of university." << std::endl << std::endl;
	std::cout << "You can interact with database by list of commands." << std::endl;
	std::cout << ">> Type \"Help\" to see list of commands." << std::endl;
	std::cout << ">> ";
	while(true)
	{
		try
		{
			std::string enteringString, command;
			std::getline(std::cin, enteringString);
			command = getFirstWord(enteringString);
			if (command == "Help")
			{
				if (enteringString != "")
				{
					invalid_command_exception exception;
					throw exception;
				}
				cf::helpToKnowCommands();
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
			std::cout << ">> ";
		}
		catch (invalid_command_exception ex)
		{
			std::cout << ex.what() << std::endl;
			std::cout << ">> ";
		}
	}
	return 0;
}

