#include "animal.h"
#include <iostream>
using namespace std;

int main()
{
	Zebra* zebras[10];
	string name;
	int age;
	int numStripes;
	int flag = 0;

	while (flag <= 10)
	{
		cin >> name;
		if (name == "0")
		{
		    break;
		}
		else
		{
		cin >> age >> numStripes;
		zebras[flag] = new Zebra(name, age, numStripes);
		flag++;
		}
	}
	for (int i = 0; i < flag; ++i)
	{
		zebras[i]->printZebra();
		delete zebras[i];
	}
	return 0;
}