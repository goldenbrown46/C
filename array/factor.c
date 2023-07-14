#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld", &n);
    int i = 2;
    while (i <=n) {
        if (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
        else {
            i = i + 1;
        }
    }

    return 0;
}