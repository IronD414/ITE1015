class Person
{
public:
	char name[10];
	int age;
	Person *next;
};

class LinkedList
{
private:
	Person *head;
public:
// Implement LinkedList(initialize member variables)
	LinkedList(Person* head);
// Implement destructor of LinkedList
    void destructor();
// Implement addPerson functions
	void addPerson(char* name, int age);
// Implement printPerson functions
	void printPerson();
};