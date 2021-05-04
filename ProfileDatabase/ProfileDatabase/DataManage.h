#pragma once
class UserPlayer;
class DataManage
{
public:
	DataManage();
	void WriteFile();
	void ReadFile();
	void Sort(UserPlayer List[]/*, int count*/);
	void Edit();
	void Add(char* szName, int nScore);
	void Print();

private:
	UserPlayer** List;
	int count;
};

