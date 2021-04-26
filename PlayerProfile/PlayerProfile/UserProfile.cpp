#include "UserProfile.h"
#include <iostream>

UserProfile::UserProfile()
{

}

void UserProfile::SetName(char* szText)
{
	strcpy_s(m_szName, 64, szText);
}

char* UserProfile::GetName()
{
	return m_szName;
}

void UserProfile::SetHighScore(int nScore)
{
	m_nScore = nScore;
}

int UserProfile::GetHighScore()
{
	return GetHighScore();
}


