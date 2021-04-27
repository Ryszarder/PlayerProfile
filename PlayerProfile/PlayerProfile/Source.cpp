#include <crtdbg.h>
#include <iostream>
#include <fstream>

#include "UserProfile.h"
#include "DataManage.h"


void Profile(DataManage* data)
{
	int cout = 3;
	UserProfile** pUser = new UserProfile*[cout];
	pUser[0] = new UserProfile();
	pUser[1] = new UserProfile();
	pUser[2] = new UserProfile();

	char name[64] ="testsubject 0";
	char name1[64] ="testsubject 1";
	char name2[64] ="testsubject 2";

	pUser[0]->SetName(name);
	pUser[1]->SetName(name1);
	pUser[2]->SetName(name2);

	pUser[0]->SetHighScore(100);
	pUser[1]->SetHighScore(50);
	pUser[2]->SetHighScore(10);

	data->WriteFile();
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DataManage* data = new DataManage();
	
	Profile(data);

	/*UserProfile pUser = ->ReadFile();*/

	getchar();

	return 0;
}