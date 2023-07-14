#include <stdio.h>

int cmp_int(const void * p1, const void * p2) {
    const int * ip1 = p1;
    int a = *ip1;
    int b = * (const int *)p2;
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    
    return 0;
}

int main() 
{
    int x, y;
    int res;
    x = -2000000000;
    y = 2000000000;
    res = cmp_int(&x, &y);
    printf("%d\n", res); 
    
    return 0;
}