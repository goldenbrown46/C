#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

int main() {
    char s[N];
    int i = 0;
    
    while (NULL != fgets(s, N, stdin)) {
        for (char * p = strtok(s, " "); p != NULL; p = strtok (NULL, " ") ) {
            if (strstr(p, "bomb") != NULL) {
                i = i + 1;
            }
        }
    }
    printf("%d", i);
    return 0;
}