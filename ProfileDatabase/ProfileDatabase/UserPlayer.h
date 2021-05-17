#pragma once
class UserPlayer
{
public:
	//Creates the public functions as for the Get and Set 
	UserPlayer();
	~UserPlayer();
	void SetName(char* szName);
	char* GetName();

	void SetHighScore(int nScore);
	int GetHighScore();

private:
	//Creates the variables that are only accessible in the UserPlayer file
	char m_szName[64];
	int m_nScore;
};