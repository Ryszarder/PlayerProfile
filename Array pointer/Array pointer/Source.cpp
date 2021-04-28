#include <crtdbg.h>
#include <iostream>
#include "Player.h"
#include <time.h>
#include <random>
#include <chrono>

//Standard Template Library
#include <vector>



//void Print(Player* player)
//{
//	//Do stuff with Player
//	std::cout << (player[1]).GetHealth() << std::endl;
//}


void Print(Player* player)
{
	//Do stuff with Player
	std::cout << player->GetHealth() << std::endl;
}

static void Print(int** board) //copy of 9 bytes
{
	std::cout << board[0][0];
}

//pasing the point to the pointer
static void CreatePlayer(Player** player)
{	
	//Dereferencing the outer pointer to assign the memory to the underlying inner pointer
	*player = new Player();
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//int count = 3;
	//int someArray[count]; //static array - size must be specified at compile time
	//int* myPtr = new int;


	////dynamically allocated array (not Dynamic Array)
	//int* myArray = new int[10];	//pointer to some number of integers
	//myArray[0] = 4;
	//std::cout << myArray[0] << std::endl;


	//int staticArray[3];
	//int* ptr = staticArray;
	//ptr[4] = 5;


	int count = 3;

	//an array of 3 players on the stack
	//Rarely used beacuse lots of data on the stack is bad
	Player* playerArray;

	//an array of 3 pointers on the stack that point to players on the heap 
	//okay if it's a small array of fixed array
	Player* arrayOfPointers[3];
	arrayOfPointers[0] = new Player();
	arrayOfPointers[1] = new Player();
	arrayOfPointers[2] = new Player();
	delete arrayOfPointers[0];
	delete arrayOfPointers[1];
	delete arrayOfPointers[2];


	//A pointer on the stack to 1 player on the heap
	//best approach if you have just one object
	Player* singlePointer = new Player();
	delete singlePointer;

	//A pointer on the stack to an array of 3 player on the heap
	//Not common because the players are not pointers
	Player* pointerToArray = new Player[count];
	delete[] pointerToArray;

	//A pointer on the stack to an array of 3 pointers to players on heap
	Player* pointerToPointers2[3];
	pointerToPointers2[0] = new Player();
	pointerToPointers2[1] = new Player();
	pointerToPointers2[2] = new Player();

	//Or

	//A pointer on the stack to an array of 3 pointers to players on heap
	//most common if you need a large collection of unknown size (e.g. enemies in a level)
	Player** pointerToPointers = new Player*[count];
	pointerToPointers[0] = new Player();
	pointerToPointers[1] = new Player();
	pointerToPointers[2] = new Player();

	for (int i = 0; i < count; ++i)
	{
		Print(pointerToPointers[i]);
	}

	delete pointerToPointers[0];
	delete pointerToPointers[1];
	delete pointerToPointers[2];
	delete[] pointerToPointers;


	//int board[3][3];


	//create a point on the stack and start it at null
	Player* player1 = nullptr;

	//pass the adderss of the pointer into the function that will create it
	//It's the pointer to the pointer that will copied and destoryed,
	//protectiong out actual pointer
	CreatePlayer(&player1);

	std::cout << player1 << std::endl;




	std::vector<int> myArray;
	myArray.push_back[1];
	myArray.push_back[2];
	myArray.push_back[3];
	myArray.push_back[4];
	myArray.push_back[5];

	/*myArray[0] = 3;
	std::cout << myArray[0];*/

	////std::vector<int>::iterator first = myArray.begin();
	////auto first = myArray.begin();

	//myArray.insert(myArray.begin() + 1, 10);

	//myArray.erase(myArray.end() - 1);

	for (int i = 0; i < myArray.size(); ++i)
	{
		std::cout << myArray[i] << std::endl;
	}

	for (int value : myArray)
	{
		std::cout << value << std::endl;
	}

	for (std::vector<int>::iterator iter = myArray.begin(); iter < myArray.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
 

	//random number
	//C-style Random numbers
	srand(time(nullptr));
	int myNumber = rand() % 6 + 1; //1 to 6
	float myFloat = rand() / RAND_MAX; //0.0f to 1.0f

	//c++ style Random number
	std::default_random_engine random;	//make the random number generator
	random.seed(time(nullptr)); //seed with time
	std::uniform_int_distribution<int> dice(1, 6);	//creates the range and distribution
	int value = dice(random);	//generate the number

	std::uniform_real_distribution<float> floatDice(0.0f, 1.0f); //float distribution
	float floatvalue = floatDice(random); //generate float

	getchar();

	return 0;
}