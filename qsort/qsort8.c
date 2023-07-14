#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
	int y;
};

int cmp_Point(const void * p1, const void * p2)
{
    struct Point a = * (struct Point *)p1;
    struct Point b = * (struct Point *)p2;
    int lengtha = a.x * a.x + a.y * a.y;
    int lengthb = b.x * b.x + b.y * b.y;

    return lengtha-lengthb;
}

int main()
{
    struct Point a = {2, 1};
    struct Point b = {4, 2};
    int res;
    res = cmp_Point(&a, &b);
    printf("%d\n", res); 
    
    return 0;
}
