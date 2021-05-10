#pragma once
class UserPlayer;
class DataManage
{
public:
	//Creates the public functions that are used throughout the program
	DataManage();
	~DataManage();
	void WriteFile();
	void ReadFile();
	void Sort();
	bool EditName(char* nameFinder, char* newName, int newScore);
	void Add(char* szName, int nScore);
	void Print();

private:
	//Creates the private variables that only the DataManage files can use
	UserPlayer** List;
	int count;
};

