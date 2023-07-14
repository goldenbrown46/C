#include <stdio.h>

int main()
{
    int y;
    int x;
    int a[3][3];
    
    for (y = 0; y < 3; y++) {
        for (x = 0; x < 3; x++) {
            scanf("%d", &a[y][x]);
        }
    }
    int d1 = 0;
    int d2 = 0;
    for (y = 0; y < 3; y++) {
        for (x = 0; x < 3; x++) {
            if (x == y) {
                d1 = d1 + a[y][x];
            }
            if (x + y == 2) {
                d2 = d2 + a[y][x];
            }
        }
    }
    int col0 = 0;
    int col1 = 0;
    int col2 = 0;
    for (y = 0; y < 3; y++) {
        col0 = col0 + a[y][0];
        col1 = col1 + a[y][1];
        col2 = col2 + a[y][2];
    }
    int row0 = 0;
    int row1 = 0;
    int row2 = 0;
    for (x = 0; x < 3; x++) {
        row0 = row0 + a[0][x];
        row1 = row1 + a[1][x];
        row2 = row2 + a[2][x];
    }
    if ((d1 == d2) & (d2 == col0) & (col0 == col1) & (col1 == col2) & (col2 == row0) & (row0 == row1) & (row1 == row2)) {
        printf("MAGIC\n");
    }

    return 0;
}