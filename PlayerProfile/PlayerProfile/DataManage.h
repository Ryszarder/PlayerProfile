#pragma once
class UserProfile;
class DataManage
{
public:
	DataManage();
	void* WriteFile(UserProfile pUser[], int count);
	void ReadFile(DataManage pdata, int count);

private:

};

