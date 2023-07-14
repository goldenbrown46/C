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
    int b[N] = {0};
    int c[N];
    int n, i;
    int j = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            b[i] = a[i];
        }
        else {
            c[j] = a[i];
            j = j + 1;
        }
    }
    qsort(c, j, sizeof(int), cmp_int);
    int t = 0;
    for (i = 0; i < n; i++) {
        if (b[i] == 0) {
            b[i] = c[t];
            t = t + 1;
            if (t == j) {
                goto A;
            }
        }
    }
    A:
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    return 0;
}
