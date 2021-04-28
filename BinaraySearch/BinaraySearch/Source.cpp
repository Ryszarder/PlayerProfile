#include <crtdbg.h>
#include <iostream>
#include <fstream>


static int BinarySearch(int* data, int count, int key)
{
	//static int BinarySearch(Player* playerlist, int count, const char* name)
	//{
		//strcmp(playerlist[mid]->name,name
	//}

	//Binary Search
	int min = 0;
	int max = count - 1;
	int mid = (min + max) / 2;

	while (true)
	{
		if (min > max)
			return -1;
		if (data[mid] == key)
		{
			//We found it
			return mid;
		}
		else if (key < data[mid])
		{
			//Result is in left half of data
			max = mid - 1;
		}
		else
		{
			//Result is in the right half of data
			min = mid + 1;
		}
		mid = (min + max) / 2;
	}
}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Test data
	int data[13] = {3, 6, 9, 12, 15, 18, 21, 24, 17, 30, 40, 50, 60};
	int key = 24;
	int answer = BinarySearch(data, 13, key);

	if(answer == -1)
	std::cout << "value was not found" << std::endl;
	else
	std::cout << "the value was found at index: " << answer << std::endl;

	return 0;
}