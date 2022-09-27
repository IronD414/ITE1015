#include <string>

class Animal
{
public:
    Animal();
	Animal(std::string _name, int _age);
	void printInfo(){};
	void printAnimal();

protected:
	std::string name;
	int age;
};

class Zebra: public Animal
{
public:
    Zebra();
	Zebra(std::string _name, int _age, int _numStripes);
	void printZebra();

private:
	int numStripes;
};