#include "animal.h"
#include <iostream>
using namespace std;

int main()
{
	char user_input = '.';
	string name; int age; int numStripes; string favoriteToy;
	Animal* animals[10];
	int n = 0;

	while (user_input != '0' && n <= 10)
	{
		cin >> user_input;
		switch (user_input)
		{
			case 'z':
			cin >> name >> age >> numStripes;
			animals[n] = new Zebra(name, age, numStripes);
			break;

			case 'c':
			cin >> name >> age >> favoriteToy;
			animals[n] = new Cat(name, age, favoriteToy);
			break;

			case '0':
			for (int i = 0; i < n; ++i)
			{
				animals[i]->printInfo();
				delete animals[i];
			}
			break;
		}
		n++;
	}
	return 0;
}