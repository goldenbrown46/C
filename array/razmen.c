#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld", &n);
    int a[9] = {5000, 1000, 500, 100, 50, 10, 5, 2, 1};
    int b[9];
    int i;
    for (i = 0; i < 9; i++) {
        b[i] = 0;
    }
    for (i = 0; i < 9; i++) {
        if (n / a[i] != 0) {
            b[i] = n / a[i];
            n = n % a[i];
        }
        printf("%d %d\n", a[i], b[i]);
    }

    return 0;
}