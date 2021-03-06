﻿#include <iostream>
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
static bool IS_OPENED_BASE = false;
static std::vector<Faculty_Abstract*> CURRENT_CHOSEN_BASE;
static bool IS_CHOSE_BASE = false;

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
					OPENED_BASE_FILENAME = basename;
					CURRENT_OPENED_BASE = cf::openBase(basename);
					IS_OPENED_BASE = true;
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
					if (!IS_OPENED_BASE)
					{
						SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new doesnt_opened_exception;
						throw exception;
					}
					cf::saveBase(CURRENT_OPENED_BASE, basename);
				}
				else
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
			}
			else if (command == "add")
			{
				if (!IS_OPENED_BASE)
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new doesnt_opened_exception;
					throw exception;
				}
				if (enteringString != "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				std::cout << "You are going to add note to current database." << std::endl;
				std::cout << "Answer the questions and follow the instructions..." << std::endl;
				std::cout << std::endl;
				Faculty_Abstract* newFaculty = cf::createNote();
				CURRENT_OPENED_BASE.push_back(newFaculty);
				std::cout << "Note has been added successfully." << std::endl;
			}
			else if (command == "edit")
			{
				if (!IS_OPENED_BASE)
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new doesnt_opened_exception;
					throw exception;
				}
				if (enteringString != "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				std::cout << "You are going to edit note of current database." << std::endl;
				std::cout << "Answer the questions and follow the instructions..." << std::endl;
				std::cout << std::endl;
				cf::editNote(CURRENT_OPENED_BASE);
			}
			else if (command == "delete_note")
			{
				if (!IS_OPENED_BASE)
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new doesnt_opened_exception;
					throw exception;
				}
				if (enteringString != "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				std::cout << "You are going to edit note of current database." << std::endl;
				std::cout << "Answer the questions and follow the instructions..." << std::endl;
				cf::deleteNote(CURRENT_OPENED_BASE);
			}
			else if (command == "print_notes")
			{
				if (!IS_OPENED_BASE)
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new doesnt_opened_exception;
					throw exception;
				}
				if (enteringString != "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				cf::printNotes(CURRENT_OPENED_BASE);
			}
			else if (command == "sort")
			{
				if (!IS_OPENED_BASE)
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new doesnt_opened_exception;
					throw exception;
				}
				std::string option, direction;
				if (enteringString[0] == ':')
				{
					option = getFirstWord(enteringString);
					direction = getFirstWord(enteringString);
					if (getFirstWord(enteringString) != "")
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
				if (direction == "inc" || direction == "dec")
				{
					if (option == ":byname" || option == ":bdnumber")
					{
						if (option == ":byname")
						{
							direction == "inc" ? cf::sortByName(CURRENT_OPENED_BASE, true) :
								cf::sortByName(CURRENT_OPENED_BASE, false);
						}
						else
						{
							direction == "inc" ? cf::sortByBdNumber(CURRENT_OPENED_BASE, true) :
								cf::sortByBdNumber(CURRENT_OPENED_BASE, false);
						}
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
			}
			else if (command == "choose")
			{
				if (!IS_OPENED_BASE)
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new doesnt_opened_exception;
					throw exception;
				}
				if (enteringString == "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				std::string option;
				option = getFirstWord(enteringString);
				if (option[0] == ':')
				{
					if (getFirstWord(enteringString) != "")
					{
						SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
						throw exception;
					}
					if (option == ":byles")
					{
						std::cout << "You are going to choose notes in current data base\nby name "
							<< "of lesson teached in this faculty" << std::endl;
						std::cout << "Answer the questions and follow the instructions..." << std::endl;
						CURRENT_CHOSEN_BASE = cf::chooseNotes(CURRENT_OPENED_BASE, true);
						IS_CHOSE_BASE = true;
					}
					else if (option == ":mn")
					{
						std::cout << "You are going to choose notes in current data base\nwich have "
							<< "more than determined number of departments. " << std::endl;
						std::cout << "Answer the questions and follow the instructions..." << std::endl;
						CURRENT_CHOSEN_BASE = cf::chooseNotes(CURRENT_OPENED_BASE, false);
						IS_CHOSE_BASE = true;
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
			}
			else if (command == "transmit_new_base")
			{
				if (!IS_CHOSE_BASE)
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new doesnt_chosen_exception;
					throw exception;
				}
				if (enteringString == "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
				}
				std::string basename;
				basename = getFirstWord(enteringString);
				if (enteringString != "")
				{
					SYSTEM_OF_BASE_CONTROL_EXCEPTION* exception = new invalid_command_exception;
					throw exception;
				}
				cf::createDataBase(basename, true);
				cf::saveBase(CURRENT_CHOSEN_BASE, basename);
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

