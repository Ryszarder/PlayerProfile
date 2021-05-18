#pragma once
class UserPlayer;
class DataManage
{
public:
	//Creates the public functions that are used throughout the program
	DataManage();
	~DataManage();
	void Save();
	void Load();
	void Add(char* szName, int nScore);
	bool EditName(char* nameFinder, char* newName, int newScore);
	void Sort();
	void Print();

private:
	//Creates the private variables that only the DataManage files can use
	UserPlayer** List;
	int count;
};