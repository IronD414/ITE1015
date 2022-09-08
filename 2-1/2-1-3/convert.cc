#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int exiting = 1;

void convert_case(char* a) {
	unsigned int len = (unsigned int)strlen(a);
	for (int i=0; i<len; i++)
	{
		if ((int)a[i] >= 97 && (int)a[i] < 123)
		{
			a[i] = (char) ((int)a[i] - 32);
		}
		else if ((int)a[i] >= 65 && (int)a[i] < 91)
		{
			a[i] = (char) ((int)a[i] + 32);
		}
		else
		{
			printf("Error: Wrong input!\n");
			exiting = 0;
			return;
		}
	}
}
int main(void) {
//Implement this function
	char init[10000];
	char* pstr;

	while (exiting)
	{
		scanf(" %s", init);
		unsigned int len = (unsigned int)strlen(init);

		pstr = (char*) malloc(sizeof(char) * len);
		for (int i=0; i<len; ++i)
		{
			pstr[i] = init[i];
		}


		convert_case(pstr);


		if (strcmp(pstr, "EXIT")==0 || strcmp(pstr, "eXIT")==0)
		{
			exiting = 0;
		}
		else if (exiting)
		{
			printf("%s\n", pstr);
		}
		free(pstr);

	};

	return 0;
}
