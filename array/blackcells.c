#include <stdio.h>
#define N 100

int main()
{
    int n, i, j;
    scanf("%d", &n);
    char a[N][N];
    int count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%c", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            if (a[i][j] == 42) {
                count = count + 1;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}