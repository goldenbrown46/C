#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}
int main() {
    char * s = "abc";
    printf("%zd\n", strlen(s));     // 3, эталонная функция
    printf("%zd\n", my_strlen(s));   // 3, наша функция
    return 0;
}