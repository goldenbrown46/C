#include <stdio.h>
#include <stdlib.h>
#define N 1000

int cmp_int(const void * p1, const void * p2) {
    const int * ip1 = p1;
    int a = *ip1;
    int b = * (const int *)p2;
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    
    return 0;
}

int main()
{
    int a[N];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp_int);
    for (i = 0; i< n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}