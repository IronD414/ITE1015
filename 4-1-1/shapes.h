#ifndef SHAPES_H
#define SHAPES_H

class Circle
{
// private:
	int x;
	int y;
	int r; // radius

public:
	Circle(int x, int y, int r);
	double area();
	double perimeter();
};

class Rectangle
{
// private:
	int x1; // top-left values
	int y1; 
	int x2; // bottom-right values
	int y2;

public:
	Rectangle(int x1, int y1, int x2, int y2);
	int area();
	int perimeter();
};

#endif