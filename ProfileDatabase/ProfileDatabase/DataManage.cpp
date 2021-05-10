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

DataManage::~DataManage()
{

	for (int i = 0; i < count; ++i)
	{
		delete List[i];
		++count;
	}
	delete[] List;
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

bool DataManage::EditName(char* nameFinder, char* newName, int newScore)
{
	//Binary Search
	//Just do the min, mid, max
	//i dont need to do the seekg, seekp stuff
	//just strcmp for the word that was ask to be edit and replace it with the new name they want

	int min = 0;
	int max = count - 1;
	int mid = (min + max) / 2;
	

	while (true)
	{
		if (min > max)
			return false;
		int result = strcmp(List[mid]->GetName(), nameFinder);
		if (result == 0)
		{
			List[mid]->SetName(newName);
			List[mid]->SetHighScore(newScore);
			return true;
		}
		else if (result > 0)
		{
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}
		mid = (min + max) / 2;
	}


}

void DataManage::Add(char* szName, int nScore)
{
	List[count]->SetName(szName);
	List[count]->SetHighScore(nScore);

	count++;
}

void DataManage::Print()
{
	//Print Out the Users
	for (int i = 0; i < count; ++i)
	{
		std::cout << " " << List[i]->GetName() << "  " << List[i]->GetHighScore() << std::endl;
		std::cout << "pos " << i << std::endl;
	}
}


