#include <stdio.h>
void rotateLeft(int* pa, int* pb, int* pc) {
//Implement this function
	int temp = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = temp;
}
void rotateRight(int* pa, int* pb, int* pc) {
//Implement this function
	int temp = *pc;
	*pc = *pb;
	*pb = *pa;
	*pa = temp;
}
int main(void) {
//implement this function
	int a = 10;
	int b = 20;
	int c = 30;

	int* pa = &a;
	int* pb = &b;
	int* pc = &c;

	int exit = 1;

	do 
	{
		printf("%d:%d:%d\n", a, b, c);
		char key;
		scanf(" %c", &key);

		switch(key)
		{
			case 'L':
				rotateLeft(pa, pb, pc);
				break;
			case 'R':
				rotateRight(pa, pb, pc);
				break;
			case 'E':
				exit = 0;
				break;
			default:
				printf("Error: Wrong input!\n");
				exit = 0;
				break;
		}
	} while (exit);

	return 0;
}
