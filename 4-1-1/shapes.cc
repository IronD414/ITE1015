#include "shapes.h"

const double PI = 3.14;

Circle::Circle(int x, int y, int r)
: x(x), y(y), r(r)
{}

double Circle::area()
{
	return PI * this->r * this->r;
}

double Circle::perimeter()
{
	return 2 * PI * this->r;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
: x1(x1), y1(y1), x2(x2), y2(y2)
{}

int Rectangle::area()
{
	return (this->x2 - this->x1) * (this->y1 - this->y2);
}

int Rectangle::perimeter()
{
	return 2 * (this->x2 - this->x1 + this->y1 - this->y2);
}