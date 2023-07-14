#include <stdio.h>
#define N 1000

int main() 
{
    int n, i;
    scanf("%d", &n);
    long long int a[N];
    a[0] = 1;
    for (i = 1; i < n + 1; i++) {
        a[i] = 0;
    }
    int t = 1;
    while (t <= n) {
        for (i = t; i > 0; i--) {
            a[i] = a[i] + a[i-1];
        }
        t = t + 1;
    }
    for (i = 0; i < n + 1; i++) {
        if (a[i] != 0) {
            printf("%lld ", a[i]);
        }
    }

    return 0;
}