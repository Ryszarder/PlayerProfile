#pragma once
class UserPlayer;
class DataManage
{
public:
	DataManage();
	void WriteFile();
	void ReadFile();
	void Sort();
	bool Edit(char* wordFinder, char* newName);
	void Add(char* szName, int nScore);
	void Print();

private:
	UserPlayer** List;
	int count;
};

