#include <stdio.h>
#define N 1000

int main()
{
    int n, x, y, i;
    scanf("%d", &n);
    int a[N][3];
    for (x = 0; x < n; x++) {
        for (y = 0; y < 3; y++) {
            scanf("%d", &a[x][y]);
        }
    }
    int b[1000];
    for (i = 0; i < 1000; i++) {
        b[i] = 0;
    }
    for (i = 0; i < 1000; i++) {
        for (x = 0; x < n; x++) {
            if (a[x][1] == i + 1) {
                b[i] = b[i] + 1;
            }
        }
    }
    int sum = 0;
    for (i = 0; i < 1000; i++) {
        if (b[i] != 0) {
            sum = sum + b[i] - 1;
        }
    }
    printf("%d\n", n - sum);

    return 0;
}