#include <stdio.h>
#include <stdlib.h>

typedef struct
{
int xpos;
int ypos;
}Point;

Point getScalePoint(Point* p, int s)
{
	printf("Calling getScalePoint() for (%d, %d)\n", (*p).xpos, (*p).ypos);
	(*p).xpos *= s;
	(*p).ypos *= s;
	return (*p);
}

void swapPoints(Point* p1, Point* p2)
{
	printf("Calling swapPoints()\n");
	Point temp = (*p1);
	(*p1) = (*p2);
	(*p2) = temp;
}

int main(void)
{
	// initialize
	Point p1; Point p2; 
	Point* p_p1; Point* p_p2;
	int p1_1; int p1_2; int p1_3;
	int p2_1; int p2_2; int p2_3;

	scanf("%d %d %d", &p1_1, &p1_2, &p1_3);
	scanf("%d %d %d", &p2_1, &p2_2, &p2_3);

	// substitute values into Point struct
	p1.xpos = p1_1; p1.ypos = p1_2;
	p2.xpos = p2_1; p2.ypos = p2_2;
	p_p1 = &p1; p_p2 = &p2;


	// terminate functions
	getScalePoint(p_p1, p1_3); getScalePoint(p_p2, p2_3);
	swapPoints(p_p1, p_p2);

	// printing domain
	printf("p1 : %d %d\n", p1.xpos, p1.ypos);
	printf("p2 : %d %d\n", p2.xpos, p2.ypos);

	return 0;
}
