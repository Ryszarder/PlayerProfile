#include "DataManage.h"
#include "UserPlayer.h"
#include <iostream>
#include <fstream>


#define MAX_ENTRIES 5

DataManage::DataManage()
{
	//UserPlayer* pUser = new UserPlayer;

	List = new UserPlayer*[MAX_ENTRIES];
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
			//std::cout << Post.GetName() << std::endl;
			//std::cout << Post.GetHighScore() << std::endl;
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
	//Bubble Sort
	bool sorted = false;
	UserPlayer* temp;

		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < count - 1; ++i)
			{
				if (strcmp(List[i]->GetName(), List[i + 1]->GetName()) == 1 )
				{
					(temp = List[i]);
					(List[i] = List[i + 1]);
					(List[i + 1] = temp);

					sorted = false;
				}	
			}
		}
}

void DataManage::Edit()
{
	//Binary Search
}

void DataManage::Add(char* szName, int nScore)
{
	List[count]->SetName(szName);
	List[count]->SetHighScore(nScore);

	count++;
}

void DataManage::Print()
{
	int board = 1;

	//Print Out the Users
	for (int i = 0; i < count; ++i)
	{
		std::cout << board << " " << List[i]->GetName() << "  " << List[i]->GetHighScore() << std::endl;

		++board;
	}
}


