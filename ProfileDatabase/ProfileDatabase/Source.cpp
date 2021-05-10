#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include "DataManage.h"
#include "UserPlayer.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DataManage* pData = new DataManage;

	/*UserPlayer* pUser = new UserPlayer;*/

	pData->ReadFile();

	bool running = true;

	while (running)
	{
		system("cls");

		pData->Print();

		std::cout << "Here are Your opions" << std::endl;
		std::cout << "Add, Save, Edit, Sort, Quit" << std::endl;

		char action[64];
		std::cin >> action;

		if (strcmp(action, "Add") == 0)
		{
			char name[64];
			std::cout << "Name:" << std::endl;
			std::cin >> name;

			int score;
			std::cout << "Score:" << std::endl;
			std::cin >> score;

			pData->Add(name, score);
		}

		if (strcmp(action, "Save") == 0)
		{
			pData->WriteFile();
		}

		if (strcmp(action, "Edit") == 0)
		{
			char nameFinder[64];
			char newName[64];
			char selection[64];
			int scoreFinder;
			int newScore;

			std::cout << "which would you like to edit Name or Score" << std::endl;
			std::cin >> selection;

			if (strcmp(selection, "Name") == 0)
			{
				do
				{
					std::cout << "Which of the users name would you like to edit" << std::endl;
					std::cin >> nameFinder;
					std::cout << "What world you like to change the name to" << std::endl;
					std::cin >> newName;


				} while (!pData->EditName(nameFinder, newName));
			}

			else if (strcmp(selection, "Score") == 0)
			{
				do
				{
					std::cout << "Which of the users score would you like to edit" << std::endl;
					std::cin >> scoreFinder;
					std::cout << "What world you like to change the score to" << std::endl;
					std::cin >> newScore;


				} while (!pData->EditScore(scoreFinder, newScore));
			}

	
		}

		if (strcmp(action, "Sort") == 0)
		{
			pData->Sort();
		}

		if (strcmp(action, "Quit") == 0)
		{
			pData->WriteFile();
			exit(0);
		}

	}



	return 0;
}