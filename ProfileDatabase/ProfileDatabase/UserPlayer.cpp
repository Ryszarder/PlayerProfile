#include "UserPlayer.h"
#include <iostream>

UserPlayer::UserPlayer()
{
	//initialize the variables which didn't need to be 
	strcpy_s(m_szName, 64, "Test");
	m_nScore = 0;
}

//Destructor
UserPlayer::~UserPlayer()
{
}

//Sets the name for the User when called
void UserPlayer::SetName(char* szName)
{
	strcpy_s(m_szName, 64, szName);
}

//Gets the name of the User when called
char* UserPlayer::GetName()
{
	return m_szName;
}

//Sets the score for the User when called
void UserPlayer::SetHighScore(int nScore)
{
	m_nScore = nScore;
}

//Gets the score of the User when called
int UserPlayer::GetHighScore()
{
	return m_nScore;
}