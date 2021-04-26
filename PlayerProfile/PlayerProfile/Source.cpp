#include <crtdbg.h>
#include <iostream>

#include "UserProfile.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UserProfile* pUser[5];
	pUser[0] = new UserProfile();
	pUser[1] = new UserProfile();
	pUser[2] = new UserProfile();
	pUser[3] = new UserProfile();
	pUser[4] = new UserProfile();
	getchar();

	return 0;
}