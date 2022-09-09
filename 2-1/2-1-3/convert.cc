#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int ex = 1;

void lower_case(char** a) 
{
	char str[100];
	strcpy(str, *a);
	int lenof_str = sizeof(str) / sizeof(char);

	for (int i=0; i<lenof_str; i++)
	{
		if ((int)str[i] >= 65 && (int)str[i] < 91)
		{
			str[i] = (char) ((int)str[i] + 32);
		}
	}
	*a = str;
	return;
}

void convert_case(char** a, int l) 
{
	char str[100];
	int i=0; 

	while ((int)(*a)[i]>0)
	{
		int each_char = (int)(*a)[i];
		if (each_char >= 97 && each_char < 123)
		{
			str[i] = (char) (each_char - 32);
		}
		else if (each_char >= 65 && each_char < 91)
		{
			str[i] = (char) (each_char + 32);
		}
		else
		{
			printf("Error: Wrong input!\n");
			ex = 0;
			return;
		}
		i++;
	}
	printf("%s\n", str);
	return;
}
int main(void) 
{
	char init[100];
	int lenof_init;
	char check_exit[100];
	char* ptr_check_exit;
	char** pptr_check_exit;
	while (ex)
	{
		scanf(" %s", init);
		lenof_init = sizeof(init)/sizeof(char);
		strcpy(check_exit, init);
		ptr_check_exit = check_exit;
		pptr_check_exit = &ptr_check_exit;

		lower_case(pptr_check_exit);
		if (strcmp(ptr_check_exit, "exit")==0)
		{
			ex = 0;
		}
		else
		{
			char* ptr_init = (char*) malloc(sizeof(char) * lenof_init);
			strcpy(ptr_init, init);
			char** pptr_init = &ptr_init;

			convert_case(pptr_init, lenof_init);

			free(ptr_init);
		};
	};
	return 0;
}