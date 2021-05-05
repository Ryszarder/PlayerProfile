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
	//Just do the min, mid, max
	//i dont need to do the seekg, seekp stuff
	//just strcmp for the word that was ask to be edit and replace it with the new name they want
	std::cout << "Which of the Users would you like to edit" << std::endl;
	char wordFinder;
	std::cin >> wordFinder;

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


