#include <stdio.h>
double cube (const double* pd) 
{
	double result = *pd;
	result *= *pd;
	result *= *pd;
	
	return result;
}
int main(void) 
{
 // Implement this function
	double* pnum;
	double num;
	scanf("%lf", &num);
	pnum = &num;
 // Print here
	printf("%f", cube(pnum));
}
