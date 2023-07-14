#include <stdio.h>
#define N 100

int main() {
  int n, i, re;
  scanf("%d", &n);
  int a[N];
  for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
  }
  re = 0;
  int count = 0;
  while (count < (n - 1)) {
    count = 0;
    for (i = 1; i < n; i++) {
        if (a[0] == a[i]) {
            count = count + 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (i == (n - 1)) {
            if ((a[i] + a[0]) % 2 == 0) {
                a[i] = (a[i] + a[0]) / 2;
                a[0] = a[i];
            }
            else {
                a[i] = (a[i] + a[0] - 1) / 2;
                a[0] = a[i];
                re = re + 1;
            }
        }
        else {
            if ((a[i] + a[i + 1]) % 2 == 0) {
                a[i] = (a[i] + a[i + 1]) / 2;
                a[i + 1] = a[i];
            }
            else {
                a[i + 1] = a[i] = (a[i] + a[i + 1] - 1) / 2;
                re = re + 1;
            }
        }
    }
  }
  printf("%d %d\n", re, a[0]);

  return 0;
}