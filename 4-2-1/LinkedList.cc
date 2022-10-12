#include "LinkedList.h"
#include <cstring>
#include <iostream>
using namespace std;

LinkedList::LinkedList(Person* head)
{
//Initialize Linked_List
	this->head = head;
}

void LinkedList::printPerson()
{
//Print the result
	Person* searcher = this->head;

	while (searcher != NULL)
	{
		cout << "Name:" << searcher->name << ", Age:" << searcher->age << endl;
		searcher = searcher->next;
	}
}

void LinkedList::addPerson(char* name, int age)
{
//Implement this function
	Person* newPerson;
	Person* searcher;
	Person* temp = this->head;
	newPerson = new Person;

	if (this->head == NULL)
	{
		this->head = newPerson;
		searcher = this->head;
	}
	else
	{
		searcher = this->head->next;
		while (searcher != NULL)
		{
		    temp = searcher;
			searcher = searcher->next;
		}
		temp->next = newPerson;
		searcher = newPerson;
	}
	strcpy(searcher->name, name);
	searcher->age = age;
}

void LinkedList::destructor()
{
    Person* searcher = this->head;
    
    while (searcher != NULL)
    {
        delete searcher;
        searcher = searcher->next;
    }
}