#include <stdio.h>
#define N 100000

typedef struct
{
	int num;
	int denum;
}Fract;

int main()
{
    Fract x;
    scanf("%d%d", &x.num, &x.denum);
    int a[N];
    int b[N];
    int i, j, k, c = 0;
    printf("0,");
    a[0] = x.num;
    for (i = 1; i < 100000; i++) {
        x.num = x.num * 10;
        a[i] = x.num / x.denum;
        b[i] = x.num % x.denum;
        x.num = b[i];
        if (b[i] == 0) {
            for (j = 0; j <= i; j++) {
                printf("%d", a[j]);
            }
            printf("(0)");
            return 0;
        }
        else {
            j = 0;
            while (j < i) {
                if (b[j] == b[i]) {
                    for (k = 0; k < j; k++) {
                        printf("%d", a[k + 1]);
                    }
                    printf("(");
                    for (k = j; k < i; k++) {
                        printf("%d", a[k + 1]);
                    }
                    printf(")");
                    return 0;
                }
                    j = j + 1;
            }
        
        }

    }

    return 0;
}