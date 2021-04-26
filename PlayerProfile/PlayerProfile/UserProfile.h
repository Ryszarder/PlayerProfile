#pragma once
class UserProfile
{
public:
	UserProfile();
	void SetName(char* szText);
	char* GetName();

	void SetHighScore(int nScore);
	int GetHighScore();

private:
	char m_szName[64];
	int m_nScore;
};

