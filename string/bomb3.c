#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 1000

char * stringtolower(char * s) {
    for(int i = 0; i <= strlen(s); i++) {
        if(s[i] >= 65 && s[i] <= 90)
        s[i] = s[i]+32;
    }
    return s;
}

int main() {
    char s[N];
    while (NULL != fgets(s, N, stdin)) {
        for (char * p = strtok(s, " "); p != NULL; p = strtok (NULL, " ") ) {
            p = stringtolower(p);
            if (strstr(p, "bomb") != NULL) {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO\n");

    return 0;
}