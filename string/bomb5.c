#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
#define K 2500

void replace(char * dst, const char * src)
{
    size_t lenbomb = strlen("bomb");

    char * s;
    char * p;

    s = (char *)src;
    dst[0] = '\0';

    while (strstr(s, "bomb") != NULL) {
        p = strstr(s, "bomb");

        size_t n = p - s;
        strncat(dst, s, n);
        strcat(dst, "watermelon");

        s = p + lenbomb;

    }

    strcat(dst, s);
}

int main()
{
    char s[N];
    char d[K];
    while (NULL != fgets(s, N, stdin)) {
        replace(d, s);
        printf("%s", d);
    }

    return 0;
}