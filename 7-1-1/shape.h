class Shape
{
protected:
	double width, height;
public:
	Shape(double w, double h);
	virtual double getArea() = 0;
	virtual ~Shape();
};

class Triangle: public Shape
{
public:
	Triangle(double w, double h);
	double getArea();
};

class Rectangle: public Shape
{
public:
	Rectangle(double w, double h);
	double getArea();
};