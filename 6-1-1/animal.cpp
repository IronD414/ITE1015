#include <iostream>
#include "animal.h"

Animal::Animal(){}

Animal::Animal(std::string n, int a)
: name(n), age(a) {}

void Animal::printInfo(){}

Animal::~Animal(){}

Zebra::Zebra(std::string n, int a, int s)
: Animal(n, a), numStripes(s) {}

void Zebra::printInfo()
{
	std::cout << "Zebra, Name: " << this->name << ", Age: " << this->age << ", Number of stripes: " << this->numStripes << std::endl;
}

Zebra::~Zebra(){}

Cat::Cat(std::string n, int a, std::string f)
: Animal(n, a), favoriteToy(f) {}

void Cat::printInfo()
{
	std::cout << "Cat, Name: " << this->name << ", Age: " << this->age << ", Favorite toy: " << this->favoriteToy << std::endl;
}

Cat::~Cat(){}