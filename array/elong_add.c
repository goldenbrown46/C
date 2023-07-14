#include <stdio.h>
#include <math.h>
#define N 100

struct _Decimal {
    char a[N];
    unsigned int n;
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};

Decimal add (Decimal a, Decimal b) {
    Decimal x = {{0}, N};
    if (a.n >= b.n) {
        x.n = a.n;
    }
    else {
        x.n = b.n;
    }
    int i;
    int sum = 0;
    x.n = x.n + 1;
    for (i = a.n + 1; i <= x.n; i++) {
        a.a[i] = 0;
    }
    for (i = b.n + 1; i <= x.n; i++) {
        b.a[i] = 0;
    }
    for (i = 0; i <= x.n; i++) {
        sum = sum + a.a[i] + b.a[i];
        x.a[i] = sum % 10;
        sum = sum / 10;
    }
    if (x.a[x.n] == 0) {
        x.n = x.n - 1;
    }

    return x;
}

int main(){
    Decimal a = {{9}, 0};
    Decimal b = {{1}, 0};
    Decimal res;
    
    res = add(a, b);
    int d = 0;
    for (int i = 0; i <= res.n; i++) {
        d = d + res.a[i] * pow(10, i);
    }
    printf("%d\n", d);
    
    return 0;
}