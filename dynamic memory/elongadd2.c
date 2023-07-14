#include <stdio.h>
#include <math.h>

struct _Decimal {
    char * a;          // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;    // наибольшая степень десяти
    unsigned int size; // размер выделенной динамической памяти в а (можно это поле не использовать).
};
typedef struct _Decimal Decimal;

void add (const Decimal * a, const Decimal * b, Decimal * res) 
{

}

int main(){
    Decimal a;  
    Decimal b;  
    Decimal res;
    
                         // написать set_int самим или просто выделить память 
                         // под эти две структуры и записать в них числа
    a = set_int(147);   // 147 is {{7, 4, 1}, 2};
    b = set_int(13);    // 13  is {{3, 1}, 1};
    
    add(&a, &b, &res);           // res = a+b = 147+13 = 160
    
    print(res);                  // print 160
    printf("\n");
    
    return 0;
}