#include "DataManage.h"
#include "UserPlayer.h"
#include <iostream>
#include <fstream>

#define MAX_ENTRIES 10

DataManage::DataManage()
{
	//UserPlayer* pUser = new UserPlayer;

	UserPlayer** List = new UserPlayer*[MAX_ENTRIES];
	for (int i = 0; i < MAX_ENTRIES; ++i)
	{
		List[i] = new UserPlayer();
	}
	
	count = 0;
}

void DataManage::ReadFile()
{
	std::fstream file;
	file.open("data.dat", std::ios_base::in | std::ios_base::binary);
	if (file.is_open())
	{
		while (!file.eof() && file.peek() != EOF)
		{
			UserPlayer Post;
			file.read((char*)&Post, sizeof(UserPlayer));
			Add(Post.GetName(), Post.GetHighScore());
		}
	}
}

void DataManage::WriteFile()
{
	std::fstream file;
	file.open("data.dat", std::ios_base::out | std::ios_base::binary);
	if (file.is_open())
	{
		for (int i = 0; i < count; ++i)
		{
			file.write((char*)List[i], sizeof(UserPlayer));
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

void DataManage::Add(char* name, int score)
{
	List[count]->SetName(name);
	List[count]->SetHighScore(score);

	count++;
}
