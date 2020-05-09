#include <iostream>
#include <string>
#include <exception>
#include <vector>

#include "consoleFunctions.h"
#include "exceptions.h"
#include "FacultyClasses.h"



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

static std::vector<Faculty_Abstract*> CURRENT_OPENED_BASE;
static std::string OPENED_BASE_FILENAME;

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
			if (command == "help")
			{
				if (enteringString != "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				cf::helpToKnowCommands();
			}
			else if (command == "create")
			{
				std::string option, basename;
				if (enteringString == "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new empty_name_exception;
					throw exception;
				}
				if (enteringString[0] == ':')
				{
					option = getFirstWord(enteringString);
					basename = getFirstWord(enteringString);
				}
				else
				{
					basename = getFirstWord(enteringString);
				}
				if (basename == "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new empty_name_exception;
					throw exception;
				}
				if (option == ":hybrid" && enteringString == "")
				{
					cf::createDataBase(basename, true);
				}
				else if (option == "" && enteringString == "")
				{
					cf::createDataBase(basename, false);
				}
				else
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
			}
			else if (command == "print_base_list")
			{
				if (enteringString == "")
				{
					cf::printBasesList();
				}
				else
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
			}
			else if (command == "delete_base")
			{
				std::string basename;
				if (enteringString == "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				else
				{
					basename = getFirstWord(enteringString);
				}
				if (enteringString == "")
				{
					cf::deleteBase(basename);
				}
				else
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
			}
			else if (command == "rename")
			{
				if (enteringString == "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				std::string oldname, newname;
				oldname = getFirstWord(enteringString);
				if (enteringString == "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				newname = getFirstWord(enteringString);
				if (enteringString == "")
				{
					cf::renamebase(oldname, newname);
				}
				else
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
			}
			else if (command == "open")
			{
				if (enteringString == "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				std::string basename;
				basename = getFirstWord(enteringString);
				if (enteringString == "")
				{
					CURRENT_OPENED_BASE = cf::openBase(basename);
					OPENED_BASE_FILENAME = basename;
				}
				else
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
			}
			else if (command == "save")
			{
				if (enteringString == "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				std::string basename;
				basename = getFirstWord(enteringString);
				if (enteringString == "")
				{
					cf::saveBase(CURRENT_OPENED_BASE, OPENED_BASE_FILENAME);
				}
				else
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
			}
			else if (command == "add")
			{


			}
			else if (command == "edit")
			{


			}
			else if (command == "delete_note")
			{


			}
			else if (command == "print_notes")
			{


			}
			else if (command == "sort")
			{

			}
			else if (command == "choose")
			{

			}
			else if (command == "transmit_new_base")
			{

			}
			else if (command == "exit")
			{
				if (enteringString == "")
				{
					break;
				}
				else
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
			}
			else
			{
				SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
				throw exception;
			}
			std::cout << ">> ";
		}
		catch (SYSTEM_OF_BASE_CONTROL_EXCEPTION* ex)
		{
			std::cout << ex->what() << std::endl;
			std::cout << ">> ";
		}
	}
	return 0;
}

