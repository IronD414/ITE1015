#include "shape.h"
#include <iostream>
using namespace std;

int main()
{
	char user_input = '.'; double w, h;
	Shape* shapes[10]; int n = 0;

	while (user_input != '0')
	{
		cin >> user_input;
		switch (user_input)
		{
			case 't':
			cin >> w >> h;
			shapes[n++] = new Triangle(w, h);
			break;

			case 'r':
			cin >> w >> h;
			shapes[n++] = new Rectangle(w, h);
			break;

			case '0':
			break;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << shapes[i]->getArea() << endl;
		delete shapes[i];
	}

	return 0;
}