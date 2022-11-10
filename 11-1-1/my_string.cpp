#include "my_string.h"

MyString& MyString::operator=(const std::string& str)
{
	this->str = str;
	return *this;
}
MyString& MyString::operator=(const MyString& b)
{
    this->str = b.str;
    return *this;
}
MyString MyString::operator+(const MyString& b)
{
	MyString newString;
	newString.str = this->str + b.str;
	return newString;
}
MyString MyString::operator*(const int b)
{
	MyString newString;
	for (int i=0; i<b; i++)
	{
	    newString.str += this->str;
	}
	return newString;
}
std::ostream& operator<<(std::ostream& out, MyString& my_string)
{
	out << my_string.str;
	return out;
}
std::istream& operator>>(std::istream& in, MyString& my_string)
{
	in >> my_string.str;
	return in;
}