#include <stdio.h>
#include <math.h>

int check(int * b)
{
  for (int i = 1; i < 10; i++) {
    if (b[i] != 1) {
      return 0;
    }
  }
  return 1;
}

int check_row(int a[9][9], int row)
{
  int i;
  int b[10] = {};
  // если a[row][j] это 3
  // то b[3] += 1
  // от 1 до 9 все b[i] == 1
  for (i = 0; i < 9; i++) {
    b[a[row][i]] += 1;
  }
  return check(b);
}

int check_col(int a[9][9], int col) {
  int i;
  int b[10] = {};
  for (i = 0; i < 9; i++) {
    b[a[i][col]] += 1;
  }
  return check(b);
}

int check_sq33(int a[9][9], int row, int col) {
  int i, j;
  int b[10] = {};
  for (i = row; i < row + 3; i++) {
    for (j = col; j < col + 3; j++) {
      b[a[i][j]] += 1;
    }
  }
  return check(b);
}

int main()
{
  int a[9][9];
  int i, j;
  // read
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (i = 0; i < 9; i++) {
    if( !check_row(a, i) || !check_col(a, i))
        goto A;
  }
  for (i = 0; i < 9; i = i + 3) {
    for (j = 0; j < 9; j = j + 3) {
      if (!check_sq33(a, i, j))
        goto A;
    }
  }
  printf("YES\n");
  return 0;
  A:
  printf("NO\n");
  return 0;
}