#include <stdio.h>
#include <stdlib.h>
#define N 1000

int cmp_float(const void * p1, const void * p2) 
{
    const float * ip1 = p1;
    float a = *ip1;
    float b = * (const float *)p2;
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    
    return 0;
}

int main()
{
    float a[N];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
    qsort(a, n, sizeof(float), cmp_float);
    for (i = 0; i< n; i++) {
        printf("%.2f ", a[i]);
    }

    return 0;
}