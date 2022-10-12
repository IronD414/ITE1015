#include "shape.h"

Shape::Shape(double w, double h)
: width(w), height(h) {}

Shape::~Shape(){}

Triangle::Triangle(double w, double h)
: Shape(w, h) {}

double Triangle::getArea()
{
	return 0.5 * this->width * this->height;
}

Rectangle::Rectangle(double w, double h)
: Shape(w, h) {}

double Rectangle::getArea()
{
	return this->width * this->height;
}