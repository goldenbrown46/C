#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

int main() 
{
    char s[N+1];

    while (scanf("%1000s", s) == 1) {
        for (char * p = strtok(s, " "); p != NULL; p = strtok (NULL, " ") ) {
            if (strcmp(p, "bomb") == 0) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}