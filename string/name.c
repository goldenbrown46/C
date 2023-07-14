#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int m = 0;
    int w = 0;
    for (int i = 0; i < n; i++) {
        char ho[100], ten[100], dem[100];
        scanf("%s%s%s", ten, dem, ho);
        printf("%s %s %s ", ho, ten, dem);
        if ((strcmp(&dem[strlen(dem) - 2], "ч") == 0)) {
            printf("м\n");
            m = m + 1;
        }
        else {
            printf("ж\n");
            w = w + 1;
         }
    }
    printf("%d %d\n", m, w);

    return 0;
}