#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include "DataManage.h"
#include "UserPlayer.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Creating a new pointer to the DataManage 
	DataManage* pData = new DataManage;

	//Runs the ReadFile function from the pData C++ file that write what in the txt file on the program when launch
	pData->ReadFile();
	
	//Creates a variable that will run a while loop
	bool running = true;

	while (running)
	{
		//Refresh the program so the screen doesn't over fill with text
		system("cls");

		//Prints out the User Profile so they are always shows as the updated version every time it refresh the program
		pData->Print();

		//Prints the the program of the opions they have to do to the txt file
		std::cout << "Here are Your opions" << std::endl;
		std::cout << "Add, Save, Edit, Sort, Quit" << std::endl;

		//The char is so it can contain what they type for the opion they want to use to the if statement
		char action[64];
		std::cin >> action;

		//The if statement compares the string of the char if it equals "Add" it run the if statement
		//This function is to add a User Profile
		if (strcmp(action, "Add") == 0)
		{
			//Ask for the name of User
			char name[64];
			std::cout << "Name:" << std::endl;
			std::cin >> name;

			//Ask for the score for the User
			int score;
			std::cout << "Score:" << std::endl;
			std::cin >> score;

			//Takes the values and runs it through the Add function
			pData->Add(name, score);
		}

		//Strcmp if action equal "Save" run if statement
		if (strcmp(action, "Save") == 0)
		{
			//Writes/save all the Users profile that has been added or edited on the program to the txt file
			pData->WriteFile();
		}

		//Strcmp if action equal "Edit" run if statement
		if (strcmp(action, "Edit") == 0)
		{
			//List of variables that are need to be used for the function to edit the User profile
			char nameFinder[64];
			char newName[64];
			char selection[64];
			int newScore;

			//Runs a do while loop through the code frist then check if the condition is met
			do
			{
				//Gathers the answer and puts them into the variables
				std::cout << "Which of the users name would you like to edit" << std::endl;
				std::cin >> nameFinder;
				std::cout << "What world you like to change the name to" << std::endl;
				std::cin >> newName;
				std::cout << "What world you like to change the score to" << std::endl;
				std::cin >> newScore;

				//takes the variables and runs it through the EditName function
			} while (!pData->EditName(nameFinder, newName, newScore));
		}

		//Strcmp if action equal "Sort" run if statement
		if (strcmp(action, "Sort") == 0)
		{
			//Runs a funtion that will sort the User proflie in alphabetical order
			pData->Sort();
		}

		//Strcmp if action equal "Quit" run if statement
		if (strcmp(action, "Quit") == 0)
		{
			//Runs the save function before quitting
			pData->WriteFile();
			//Deletes the new DataManage pData before memory leak
			//And calls the destructor that deletes the UserPlayer List
			delete pData;
			//Closes the program
			exit(0);
		}
	}
	return 0;
}