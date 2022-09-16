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
	strcpy(header->name, name);
	header->age = age;
}

void increaseAge(Person* header)
{
	Person* temp;
	while (header != NULL)
	{
		temp = header;
		printf("Name:%s, Age:%d\n", temp->name, ++(temp->age));
		header = header->next;
	}
}

int main(void)
{
	int n = 1;
	Person* head = NULL;
	Person* tail = NULL;
	Person* node;

	while (n > 0)
	{
		scanf("%d", &n);
		if (n > 0)
		{
			for (int i = 0; i < n; ++i)
			{
				char name[10]; int age;
				node = (Person*) malloc(sizeof(Person));
				scanf("%s %d", name, &age);
				addPerson(node, name, age);

				if (head == NULL)
				{
					head = node;
				}
				else
				{
					tail->next = node;
				}

				tail = node;
			}
		}
		else
		{
			increaseAge(head);
		}
	}
	Person* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

	return 0;
}