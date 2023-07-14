#include <stdio.h>
#include <stdlib.h>
#define N 1000

int cmp_int(const void * p1, const void * p2) 
{
    int x = *(int *)p1;
    int y = *(int *)p2;
    int k = 10;
    if (x == y) {
        return 0;
    }
    else {
        A:
        if ((x%k) > (y%k)) {
            return 1;
        }
        if ((x%k) < (y%k)) {
            return -1;
        }
        if ((x%k) == (y%k)) {
            k = k * 10;
            goto A;
        }
    }
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
