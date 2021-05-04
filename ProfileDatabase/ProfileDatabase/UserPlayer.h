#pragma once
class UserPlayer
{
public:
	UserPlayer();
	void SetName(char* szName);
	char* GetName();

	void SetHighScore(int nScore);
	int GetHighScore();

private:
	char m_szName[128];
	int m_nScore;
	
};

