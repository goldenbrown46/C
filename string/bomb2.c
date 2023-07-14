#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

int main() {
    char s[N];
    
    
    while (NULL != fgets(s, N, stdin)) {
        for (char * p = strtok(s, " "); p != NULL; p = strtok (NULL, " ") ) {
            if (strstr(p, "bomb") != NULL) {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}