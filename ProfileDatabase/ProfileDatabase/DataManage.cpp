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
void DataManage::Load()
{
	std::fstream file;
	//Looks for the txt file name "data.dat"
	file.open("data.dat", std::ios_base::in | std::ios_base::binary);
	//If file doesn't exists run
	if (!file)
	{
		//Creates the file
		file.open("data.dat", std::ios_base::out | std::ios_base::binary);
	}
	//Else Reads the file
	else if (file.is_open())
	{
		while (!file.eof() && file.peek() != EOF)
		{
			//Reads into the file 
			UserPlayer Order;
			file.read((char*)&Order, sizeof(UserPlayer));
			Add(Order.GetName(), Order.GetHighScore());
		}
		//Close the file
		file.close();
	}
}

//Writes/Saves to the file
void DataManage::Save()
{
	std::fstream file;
	//Looks for the txt file name "data.dat" and opens the file
	file.open("data.dat", std::ios_base::out | std::ios_base::binary);
	if (file.is_open())
	{
		//Loops through the List array and write them into the file
		for (int i = 0; i < count; ++i)
		{
			file.write((char*)List[i], sizeof(UserPlayer));
		}
		//Close the file
		file.close();
	}
}

//Creates the new UserPlayer
void DataManage::Add(char* szName, int nScore)
{
	//Checks to see if count value is Larger or equal to MAX_ENTRIES 
	if (count >= MAX_ENTRIES)
	{
		//Write to the console that storge is full
		char Restart[64];
		std::cout << "Max proflie have been meet" << std::endl;
		std::cout << "Write any character to go back to the start" << std::endl;
		//A way for the String above to stay so they can read before the console refresh
		std::cin >> Restart;
	}
	//Sets the name and score to the List array to the at the position at the count
	else
	{
		List[count]->SetName(szName);
		List[count]->SetHighScore(nScore);

		count++;
	}
}

//Edits the UserPlayer name and score by doing a Binary Search
bool DataManage::EditName(char* nameFinder, char* newName, int newScore)
{
	//Set the variables need for the binary search
	int min = 0;
	int max = count - 1;
	int mid = (min + max) / 2;
	
	//While loop
	while (true)
	{
		//If min value is bigger than the max value return false
		if (min > max)
			return false;
		//Initialize the result which is a strcmp of the array name with the name seach for
		int result = strcmp(List[mid]->GetName(), nameFinder);
		//This means that the result equals true so run if statement
		if (result == 0)
		{
			List[mid]->SetName(newName);
			List[mid]->SetHighScore(newScore);
			return true;
		}
		//If result bigger than 0 means the result in it the left halve of the binary search
		else if (result > 0)
		{
			//max now equals the mid - 1 as thats the new range of the binary search for the result
			max = mid - 1;
		}
		//If this runs means result in the right side of the binary search
		else
		{
			//min now equals mid + 1 as thats the new range for the result
			min = mid + 1;
		}
		//mid equal min + max divide by 2
		mid = (min + max) / 2;
	}
}

//Sorts the UserPlayer name in alphabetical order using Bubble Sort
void DataManage::Sort()
{
	//variables need for the bubble sort
	bool sorted = false;
	UserPlayer* temp;

	//While loop that loops till it's alphabetical order
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < count - 1; ++i)
		{
			//Strcmp that if the first name is after the second name it == 1, run if statement
			if (strcmp(List[i]->GetName(), List[i + 1]->GetName()) == 1)
			{
				//basically moves the Names around till the second is in the first spot and the first is in the second spot
				(temp = List[i]);
				(List[i] = List[i + 1]);
				(List[i + 1] = temp);

				//set the variable flase so it will run again to see if it's alphabetical order
				sorted = false;
			}
		}
	}
}

//Prints the User 
void DataManage::Print()
{
	//Print Out the Users
	for (int i = 0; i < count; ++i)
	{
		//Writes out how the UserPlayer values will be presented
		std::cout << " " << List[i]->GetName() << "  " << List[i]->GetHighScore() << std::endl;
	}
}