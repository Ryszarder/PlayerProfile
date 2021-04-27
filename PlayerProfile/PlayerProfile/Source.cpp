#include <crtdbg.h>
#include <iostream>
#include <fstream>

#include "UserProfile.h"


void Print()
{

}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	UserProfile** pUser = new UserProfile*[3];

	getchar();

	return 0;
}