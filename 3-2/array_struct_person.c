#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
char name[10];
int age;
struct person *next;
};
typedef struct person Person;

void addPerson(Person* header, char* name, int age)
{
	Person* pointing = header->next;
	while(pointing != NULL)
	{
		pointing = (*pointing).next;
	}
	Person newPerson;
	strcpy(newPerson.name, name); newPerson.age = age;
	pointing = &newPerson;
}

void increaseAge(Person* header)
{
	Person* pointing = header->next;
	while(pointing != NULL)
	{
		pointing = (*pointing).next;
		printf("Name:%s, Age:%d\n", (*pointing).name, ++(*pointing).age);
	}
}

int main(void)
{
	int n;
	Person nullPerson;
	do
	{
		scanf("%d", &n);  // get the number of people from user

		for (int i = 0; i < n; ++i)
		{
			char* input_name; int input_age;
			scanf(" %s %d", input_name, &input_age);
			addPerson(&nullPerson, input_name, input_age);
		}
	} while (n != 0);
// call function to increase the age for each person and print them
	increaseAge(&nullPerson);
}