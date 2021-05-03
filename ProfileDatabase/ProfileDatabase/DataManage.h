#pragma once
class DataManage
{
public:
	DataManage();
	void WriteFile();
	void ReadFile();
	void Sort();
	void Edit();
	void Add();

private:
	UserPlayer** List;

};

