#include <stdio.h>
#include <stdio.h>
#include <malloc.h>

int main()
{
    int *a = NULL, i = 0, elem;
    int z = 1;
    while (z != EOF) {
        z = scanf("%d", &elem);
        a = (int*)realloc(a, (i + 1) * sizeof(int));
        a[i] = elem;
        i++;
    }
    for (int j = i-2; j >= 0; j--)
        printf("%d ", a[j]);

    free(a);
    return 0;
}