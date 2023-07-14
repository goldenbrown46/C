#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x =0;
    int y= 0;
    char s[10];
    int steps;
    while(1 == scanf("%9s", s)) {
        if (0 == strcmp(s, "North")) {
            scanf("%d", &steps);
            y = y + steps;
        }
        if (0 == strcmp(s, "South")) {
            scanf("%d", &steps);
            y = y - steps;
        }
        if (0 == strcmp(s, "East")) {
            scanf("%d", &steps);
            x = x + steps;
        }
        if (0 == strcmp(s, "West")) {
            scanf("%d", &steps);
            x = x - steps;
        }
        if (0 == strcmp(s, "Treasure!")) {
            break;
        }   
    }
    printf("%d %d\n", x, y);

    return 0;
}