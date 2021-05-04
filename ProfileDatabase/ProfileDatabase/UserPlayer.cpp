#include "UserPlayer.h"
#include <iostream>

UserPlayer::UserPlayer()
{
	strcpy_s(m_szName, 64, "Test");
	m_nScore = 0;
}

void UserPlayer::SetName(char* szName)
{
	strcpy_s(m_szName, 64, szName);
}

char* UserPlayer::GetName()
{
	return m_szName;
}

void UserPlayer::SetHighScore(int nScore)
{
	m_nScore = nScore;
}

int UserPlayer::GetHighScore()
{
	return m_nScore;
}


