#include "my_vector.h"

// Implement constructor & destructor
MyVector::MyVector(): length(0), a(nullptr){}
MyVector::MyVector(int length)
{
	this->a = new double[length];
	this->length = length;
}
MyVector::~MyVector()
{
    delete[] this->a;
}
// Implement operators
MyVector& MyVector::operator=(const MyVector& b)
{
	if (this->length != b.length)
	{
	    this->a = new double[b.length];
		this->length = b.length;
	}
	for (int i = 0; i < b.length; ++i)
	{
		this->a[i] = b.a[i];
	}
	return *this;
}
MyVector MyVector::operator+(const MyVector& b)
{
	MyVector newVector(this->length);
	for (int i = 0; i < this->length; ++i)
	{
		newVector.a[i] = this->a[i] + b.a[i];
	}
	return newVector;
}
MyVector MyVector::operator-(const MyVector& b)
{
	MyVector newVector(this->length);
	for (int i = 0; i < this->length; ++i)
	{
		newVector.a[i] = this->a[i] - b.a[i];
	}
	return newVector;
}
MyVector MyVector::operator+(const int b)
{
	MyVector newVector(this->length);
	for (int i = 0; i < this->length; ++i)
	{
		newVector.a[i] = this->a[i] + b;
	}
	return newVector;
}
MyVector MyVector::operator-(const int b)
{
	MyVector newVector(this->length);
	for (int i = 0; i < this->length; ++i)
	{
		newVector.a[i] = this->a[i] - b;
	}
	return newVector;
}
std::ostream& operator<< (std::ostream& out, MyVector& b)
{
	for (int i = 0; i < b.length; ++i)
	{
		out << b.a[i] << " ";
	}
	return out;
}
std::istream& operator>> (std::istream& in, MyVector& b)
{
	for (int i = 0; i < b.length; ++i)
	{
		in >> b.a[i];
	}
	return in;
}