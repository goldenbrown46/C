#include <stdio.h>

int foo2 (int *px, int *py)
{
  int sum = *px + *py;
  *px = *px + 1;
  *py = *py - 1;
  printf("foo2 : res=%d x=%d y=%d\n", sum, *px, *py);

  return sum;
}

int main()
{
  int  x;
  int  y;
  int res;
  x = 2;
  y = 10;
    
  res = foo2(&x, &y);
  
    
  return 0;
}