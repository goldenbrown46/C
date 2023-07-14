#include <stdio.h>
#define N 1000

int main()
{
    int n, i;
    scanf("%d", &n);
    int a[N];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 2) {
            a[i] = 0;
        }
    }
    int t;
    for (i = 0; i < n; i++) {
        t = 2;
        while (t < a[i]) {
            if ((a[i] != 0) & (a[i] % t == 0)) {
                a[i] = 0;
                break;
            }
            t = t + 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (a[i] != 0) {
            printf("%d ", a[i]);
        }
    }

    return 0;
}