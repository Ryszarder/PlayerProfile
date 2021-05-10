#include "DataManage.h"
#include "UserPlayer.h"
#include <iostream>
#include <fstream>

//This sets the max amnout of UserPlayers there can be created/have at a time
#define MAX_ENTRIES 5

DataManage::DataManage()
{
	//Creates the dynamic array which can have up to the Max Users set above
	List = new UserPlayer*[MAX_ENTRIES];
	//Loops thorugh the List array to initialize each array
	for (int i = 0; i < MAX_ENTRIES; ++i)
	{
		List[i] = new UserPlayer();
	}
	//Set to 0 so it can be used for for loops that loop the List array
	count = 0;
}

//Destructor
DataManage::~DataManage()
{
	//Loops through to delete all the UserPlayers that are created
	for (int i = 0; i < count; ++i)
	{
		delete List[i];
	}
	//Deletes the array of List
	delete[] List;
}

//Read the File
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

//Writes/Saves to the file
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

//Sorts the UserPlayer name in alphabetical order
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

//Edits the UserPlayer name and score
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

//Creates the new UserPlayer
void DataManage::Add(char* szName, int nScore)
{
	List[count]->SetName(szName);
	List[count]->SetHighScore(nScore);

	count++;
}

//Prints the User 
void DataManage::Print()
{
	//Print Out the Users
	for (int i = 0; i < count; ++i)
	{
		std::cout << " " << List[i]->GetName() << "  " << List[i]->GetHighScore() << std::endl;
	}
}


