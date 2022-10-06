#pragma once
#include <string>

class Animal
{
protected:
	std::string name;
	int age;

public:
    Animal();
	Animal(std::string n, int a);
	virtual ~Animal();
	void virtual printInfo();
};

class Zebra: public Animal
{
	int numStripes;
public:
	Zebra(std::string n, int a, int s);
	~Zebra();
	void printInfo();
};

class Cat: public Animal
{
	std::string favoriteToy;
public:
	Cat(std::string n, int a, std::string f);
	~Cat();
	void printInfo();
};