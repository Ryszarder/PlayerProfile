#pragma once
class DataManage
{
public:
	DataManage();
	void WriteFile();
	void ReadFile();
	void Sort();
	void Edit();
	void Add(char* szName, int nScore);

private:
	UserPlayer** List;
	int count;
};

