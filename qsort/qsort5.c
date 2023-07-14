#include <stdio.h>
#include <stdlib.h>
#define N 1000

int cmp_char(const void * p1, const void * p2) {
  char x = *(char *)p1;
  char y = *(char *)p2;
  return x-y;
}

int main()
{
  char a[N];
  int i;
  for (i = 0; i < 1000; i++) {
    scanf("%c", &a[i]);
    if (a[i] == 46) {
      goto A;
    }
  }
  A:
  qsort(a, i, sizeof(char), cmp_char);
  for (int j = 0; j <= i; j++) {
    printf("%c", a[j]);
  }

  return 0;
}