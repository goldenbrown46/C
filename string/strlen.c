#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

int main() 
{
    char s[N+1];
    char a[N];
    size_t length = 0;

    while (scanf("%1000s", s) == 1) {
        for (char * p = strtok(s, " "); p != NULL; p = strtok (NULL, " ") ) {
            if (strlen(p) > length) {
                length = strlen(p);
                strcpy (a, p);
            }
        }
    }
    printf("%s %zu", a, length);

    return 0;
}