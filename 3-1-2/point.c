#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
int xpos;
int ypos;
}Point;

int getDistance(Point p_1, Point p_2)
{
    return sqrt(pow(p_1.xpos - p_2.xpos, 2) + pow(p_1.ypos - p_2.ypos, 2));
}

void getShortest(const Point* points, int n, Point* minP)
{
    
    int min = getDistance(points[0], points[1]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int k = getDistance(points[i], points[j]);
            if (k <= min)
            {
                min = k;
                minP[0] = points[i]; minP[1] = points[j];
            }
        }
    }
    
    printf("shortest: (%d, %d) (%d, %d)\n", minP[0].xpos, minP[0].ypos, minP[1].xpos, minP[1].ypos);
}

void getLongest(const Point* points, int n, Point* maxP)
{
    
    int max = getDistance(points[0], points[1]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int k = getDistance(points[i], points[j]);
            if (k >= max)
            {
                max = k;
                maxP[0] = points[i]; maxP[1] = points[j];
            }
        }
    }
    
    printf("longest: (%d, %d) (%d, %d)\n", maxP[0].xpos, maxP[0].ypos, maxP[1].xpos, maxP[1].ypos);
}

int main(void)
{
    // initialize
    int n;
    scanf("%d", &n);
    Point* plist = (Point*) malloc(sizeof(Point) * n);
    Point* min = (Point*) malloc(sizeof(Point) * 2);
    Point* max = (Point*) malloc(sizeof(Point) * 2);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &plist[i].xpos, &plist[i].ypos);
    }
    
    getLongest(plist, n, max);
    getShortest(plist, n, min);

    free(plist);
    free(min); free(max);

    return 0;
}