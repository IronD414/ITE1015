#include "animal.h"
#include <iostream>
using namespace std;

Animal::Animal(string _name, int _age)
: name(_name), age(_age)
{}

void Animal::printAnimal()
{
	cout << "Name: " << this->name << ", Age: " << this->age << endl;
}

Zebra::Zebra(string _name, int _age, int _numStripes)
: Animal(_name, _age)
{
	this->numStripes = _numStripes;
}

void Zebra::printZebra()
{
	cout << "Name: " << this->name << ", Age: " << this->age << ", Number of stripes: " << this->numStripes <<endl;
}