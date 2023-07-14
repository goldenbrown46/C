#include <stdio.h>
#include <string.h>

char * my_strcat (char *dest, const char *src)
{
    size_t i,j;
    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}

int main() {
    char a[100];           // нужно место куда копировать

    strcpy(a, "abc");
    printf("%s\n", a);     // abc
    my_strcat(a, "world");
    printf("%s\n", a);     // abcworld

    strcpy(a, "abc");
    my_strcat(a, "hello");
    printf("%s\n", a);    // abchello

    return 0;
}