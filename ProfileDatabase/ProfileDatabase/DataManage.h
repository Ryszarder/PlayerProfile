#pragma once
class UserPlayer;
class DataManage
{
public:
	DataManage();
	void WriteFile();
	void ReadFile();
	void Sort();
	bool EditName(char* nameFinder, char* newName);
	bool EditScore(int* scoreFinder, int newScore);
	void Add(char* szName, int nScore);
	void Print();

private:
	UserPlayer** List;
	int count;
};

