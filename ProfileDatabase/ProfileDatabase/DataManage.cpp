#include "DataManage.h"
#include "UserPlayer.h"
#include <iostream>
#include <fstream>

#define MAX_ENTRIES 10;

DataManage::DataManage()
{
	UserPlayer* pUser = new UserPlayer;

	int count = 0;
}

void DataManage::ReadFile()
{
	std::fstream file;
	file.open("data.dat", std::ios_base::in | std::ios_base::binary);
	if (file.is_open())
	{
		while (!file.eof() && file.peek() != EOF)
		{
			UserPlayer pUser;
			file.read((char*)&pUser, sizeof(UserPlayer));
			std::cout << pUser.GetName() << ", " << pUser.GetHighScore() << std::endl;
		}
	}
}

void DataManage::WriteFile()
{
	UserPlayer pUser[];
	int count = 0;

	std::fstream file;
	file.open("data.dat", std::ios_base::out | std::ios_base::binary);
	if (file.is_open())
	{
		for (int i = 0; i < count; ++i)
		{
			file.write((char*)&pUser[i], sizeof(UserPlayer));
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
