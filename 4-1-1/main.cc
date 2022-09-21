#include <iostream>
#include "shapes.h"
using namespace std;

int main()
{
	int flag = 1;

	char req;
	int i1; int i2; int i3; int i4;

	while (flag)
	{
		cout << "shape?" << endl;
		cin >> req;

		if (req == 'C')
		{
			cin >> i1 >> i2 >> i3;
			Circle newCircle(i1, i2, i3);
			cout << "area: " << newCircle.area() << ", perimeter: " << newCircle.perimeter() << endl;
		}
		else if (req == 'R')
		{
			cin >> i1 >> i2 >> i3 >> i4;
			Rectangle newRectangle(i1, i2, i3, i4);
			cout << "area: " << newRectangle.area() << ", perimeter: " << newRectangle.perimeter() << endl;
		}
		else if (req == 'Q')
		{
			flag = 0;
		}
	}
	return 0;
}