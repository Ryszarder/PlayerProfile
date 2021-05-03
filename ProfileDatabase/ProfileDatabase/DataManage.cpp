#include "DataManage.h"
#include "UserPlayer.h"
#include <iostream>
#include <fstream>

//#define MAX_ENTRIES 10;

DataManage::DataManage()
{
	//UserPlayer* pUser = new UserPlayer;

	int count = 0;

	UserPlayer** List = new UserPlayer*[count];
	
}

void DataManage::ReadFile()
{
	std::fstream file;
	file.open("data.dat", std::ios_base::in | std::ios_base::binary);
	if (file.is_open())
	{
		while (!file.eof() && file.peek() != EOF)
		{
			UserPlayer List;
			file.read((char*)&List, sizeof(UserPlayer));
			std::cout << List.GetName() << ", " << List.GetHighScore() << std::endl;
		}
	}
}

void DataManage::WriteFile()
{
	int count = 10;

	std::fstream file;
	file.open("data.dat", std::ios_base::out | std::ios_base::binary);
	if (file.is_open())
	{
		for (int i = 0; i < count; ++i)
		{
			file.write((char*)&List[i], sizeof(UserPlayer));
		}
		file.close();
	}
}

void DataManage::Sort()
{

}

void DataManage::Edit()
{

}

void DataManage::Add(char name, int score)
{
	int count = 0;
	UserPlayer* List = new UserPlayer[count];

	for (int i = 0; i < count; i++)
	{
		List[i].SetName(&name);
		List[i].SetHighScore(score);

		std::cout << List[i].GetName() << std::endl;
		std::cout << List[i].GetHighScore() << std::endl;

		count++;
	}
}
