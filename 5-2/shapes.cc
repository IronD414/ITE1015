#include <iostream>
#include "shapes.h"
using namespace std;

Shape::Shape(int x, int y, char b)
: topleft_x(x), topleft_y(y), brush(b)
{}

Square::Square(int x, int y, size_t z1, char b)
: Shape(x, y, b), side(z1)
{}

double Square::GetArea() 
{
	return this->side * this->side;
}

int Square::GetPerimeter() 
{
	return 4 * this->side;
}

void Square::Draw(int canvas_width, int canvas_height, Canvas* c)
{
	for (int i1 = 0; i1 < this->side; ++i1)
	{
		for (int i2 = 0; i2 < this->side; ++i2)
		{
			c->DrawPixel(this->topleft_x + i1, this->topleft_y + i2, this->brush);
		}
	}
}

Rectangle::Rectangle(int x, int y, size_t z1, size_t z2, char b)
: Shape(x, y, b), width(z1), height(z2)
{}

double Rectangle::GetArea()
{
	return this->width * this->height;
}

int Rectangle::GetPerimeter()
{
	return 2 * (this->width + this->height);
}

void Rectangle::Draw(int canvas_width, int canvas_height, Canvas* c)
{
	for (int i1 = 0; i1 < this->width; ++i1)
	{
		for (int i2 = 0; i2 < this->height; ++i2)
		{
			c->DrawPixel(this->topleft_x + i1, this->topleft_y + i2, this->brush);
		}
	}	
}

Canvas::Canvas(const size_t row, const size_t col)
: row(row), col(col)
{
	this->canvas = new char*[row];
	for (int i = 0; i < row; ++i)
	{
		this->canvas[i] = new char[col];
	}
}

Canvas::~Canvas()
{
	for (int i = 0; i < this->row; ++i)
	{
		delete this->canvas[i];
	}
	delete this->canvas;
}

void Canvas::Resize(const size_t row, const size_t col)
{
    this->row = row;
    this->col = col;
}

bool Canvas::DrawPixel(const int x, const int y, const char brush)
{
	if ((x > 0 && x < this->col) && (y > 0 && y < this->row))
	{
		this->canvas[y][x] = brush;
		return true;
	}
	else
	{
		return false;
	}
}

void Canvas::Print() const
{
	cout << " ";
	for (int i = 0; i < this->col; ++i)
	{
		cout << i;
	}
	cout << endl;

	for (int j1 = 0; j1 < this->row; ++j1)
	{
		cout << j1;
		for (int j2 = 0; j2 < this->col; ++j2)
		{
			cout << this->canvas[j1][j2];
		}
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i1 = 0; i1 < this->row; ++i1)
	{
		for (int i2 = 0; i2 < this->col; ++i2)
		{
			this->canvas[i1][i2] = '.';
		}
	}
}