#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include "DataManage.h"
#include "UserPlayer.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DataManage* pData = new DataManage;

	bool running;

	while (running)
	{
		system("cis");

		std::cout << " " << std::endl;
		pData->ReadFile();
		//std::cout << give opion for Write, Read, Edit, Sort, Quit << std::endl;

		char action[10];
		std::cin >> action;

		if (strcmp(action, "Write") == 0)
		{
			//pData.Write();
		}

		if (strcmp(action, "Read") == 0)
		{
			//pData.Load();
		}

		if (strcmp(action, "Edit") == 0)
		{
			//pData.Edit();
		}

		if (strcmp(action, "Sort") == 0)
		{
			//pData.Sort();
		}

		if (strcmp(action, "Quit") == 0)
		{
			//pData.Quit();
		}

	}



	return 0;
}