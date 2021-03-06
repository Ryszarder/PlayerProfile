#include <iostream>
#include <fstream>

#include "DataManage.h"
#include "UserProfile.h"

//#define Max_

DataManage::DataManage()
{

	ReadFile();
}

void* DataManage::WriteFile(UserProfile pUser)
{
	std::fstream file; 
	file.open("data.dat", std::ios_base::out | std::ios_base::binary);
	if (file.is_open())
	{
		for (int i = 0; i < count; ++i)
		{ 
			file.write((char*)&pUser[i], sizeof(count)); 
		}
		file.close(); 
	}
}

void DataManage::ReadFile()
{
	std::fstream file;
	file.open("data.dat", std::ios_base::in | std::ios_base::binary);
	if (file.is_open()) 
	{
		while (!file.eof() && file.peek() != EOF)
		{
			UserProfile pUser;
			file.read((char*)&pUser, sizeof(count));
			std::cout << pUser.GetName() << ", " << pUser.GetHighScore() << std::endl;
		}

		file.close();
	}
}

void DataManage::Sort()
{

}

