#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

struct _Decimal {
    char a[N];   // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;       // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};    // представление 0 в виде структуры

Decimal set (const char str[]) {
    int i;
    Decimal res;
    res.n = strlen(str) - 1;
    for (i = 0; i <= res.n; i++) {
        res.a[i] = str[res.n - i] - 48;
    }
    return res;
}

void print(Decimal res) {
    long long int sum = 0, i;
    for (i = 0; i <= res.n; i++) {
        printf("%c", res.a[i]);
    }
}
    
int main() 
{
    Decimal res;
    res = set("12345678901234567890");  // res = 12345678901234567890
    
    print(res);                         // print 12345678901234567890
    printf("\n");
    
    return 0;
}