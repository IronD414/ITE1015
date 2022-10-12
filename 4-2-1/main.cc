#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(void)
{
	int n;
	Person* head = NULL;
	LinkedList list(head);

	do
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			char name[10];
			int age;
			cin >> name >> age;

			list.addPerson(name, age);
		}
	} while (n != 0);

	list.printPerson();
	list.destructor();

	return 0;
}