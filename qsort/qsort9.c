#include <stdio.h>
#include <stdlib.h>
#define N 1000

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
    if (lengtha == lengthb) {
        if (a.x != b.x) {
            return a.x - b.x;
        }
        else {
            if (a.y != b.y) {
                return a.y - b.y;
            }
        }
    }

    return lengtha-lengthb;
}

int main()
{
    struct Point a[N];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    qsort(a, n, sizeof(struct Point), cmp_Point);
    for (i = 0; i < n; i++) {
        printf("%d %d\n", a[i].x, a[i].y);
    }
    
    return 0;
}