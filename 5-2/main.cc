#include "shapes.h"
#include <iostream>
using namespace std;

int main()
{
	size_t canvas_width, canvas_height;
	string req;
	int x, y;
	size_t z1, z2;
	char b;

	cin >> canvas_width >> canvas_height;
	Canvas myCanvas(canvas_width, canvas_height);

	while (req != "quit")
	{
		myCanvas.Clear();

		cin >> req;
		if (req == "rect")
		{
			cin >> x >> y >> z1 >> z2 >> b;
			Rectangle newRectangle(x, y, z1, z2, b);
			cout << "Area: " << newRectangle.GetArea() << endl;
			cout << "Perimeter: " << newRectangle.GetPerimeter() << endl;
			newRectangle.Draw(canvas_width, canvas_height, &myCanvas);
		}
		else if (req == "square")
		{
			cin >> x >> y >> z1 >> b;
			Square newSquare(x, y, z1, b);
			cout << "Area: " << newSquare.GetArea() << endl;
			cout << "Perimeter: " << newSquare.GetPerimeter() << endl;
			newSquare.Draw(canvas_width, canvas_height, &myCanvas);
		}
		else
		{
		    break;
		}
		myCanvas.Print();
	}

	return 0;
}