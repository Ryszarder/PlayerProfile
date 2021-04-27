#include <iostream>
#include <fstream>

struct Data
{
	/*Data(int h, int s)
	{
		health = h;
		speed = s;
	}
	Data()
	{
		health = 0;
		speed = 0;
	}*/

	int health;
	int speed;
};

void Save();
Data* Load();

int main()
{
	 Save();
	
	Data* enemies = Load();

	delete enemies;
	return 0;
}

void Save()
{
	Data enemies[] = { {100, 15}, {50, 5}, {200, 40}, {300, 10}, {70, 30} };
	int count = sizeof(enemies) / sizeof(Data);

	std::fstream file;
	file.open("data.dat", std::ios_base::out | std::ios_base::binary);
	if (file.is_open())
	{
		for (int i = 0; i < count; ++i)
		{
			file.write((char*)&enemies[i], sizeof(Data));
		}
		file.close();
	}
}

Data* Load()
{
	int count = 5;
	Data* enemies = new Data[count];

	std::fstream file;
	file.open("data.dat", std::ios_base::in | std::ios_base::binary);
	if (file.is_open())
	{
		for (int i = 0; i < count; ++i)
		{
			Data enemy;
			file.read((char*)&enemy, sizeof(Data));
			enemies[i] = enemy;
			std::cout << enemy.health << std::endl;
			std::cout << enemy.speed << std::endl;
		}
		file.close();
	}
	return enemies;
}