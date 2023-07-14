#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define N 1000

char* replace(const char* src)
{
    char* d;
    char a[] = "watermelon";
    char s[] = "bomb";
    int i = 0, count = 0;
    int alen = strlen(a);
    int slen = strlen(s);
    for (i = 0; src[i] != '\0'; i++) {
        if (strstr(&src[i], s) == &src[i]) {
            count++;
            i += slen - 1;
        }
    }
    d = (char*)malloc(i + count*(alen - slen) + 1);
    i = 0;
    while(*src){
        if (strstr(src, s) == src) {
            strcpy(&d[i], a);
            i += alen;
            src += slen;
        }
        else d[i++] = *src++;
    }
    d[i] = '\0';
    return d;
}

int main ()
{
    char s[N]; 
    char* d = NULL;
    while (NULL != fgets(s, N, stdin)) {
        d = replace(s);                  
        printf("%s", d);
        free(d);                          
    }
    return 0;
}