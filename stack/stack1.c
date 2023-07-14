#include <stdio.h>
#define N 100

typedef int Data;

struct Stack {
    int n;
    Data a[N];
};

void stack_create(struct Stack * s) {
    s->n = 0;
}

void stack_push(struct Stack * s, Data x) {
    s->a[s->n] = x;
    s->n ++;
}

Data stack_pop(struct Stack * s) {
    s->n --;
    Data res = s->a[s->n];
    
    return res;
}

Data stack_get(struct Stack * s) {
    return s->a[s->n - 1];
}

void stack_print(struct Stack * s) {
    if (s->n==0) {
        printf("Empty stack\n");
    }
    else {
        for(int i = 0; i < s->n; i++)
            printf("%d ", s->a[i]);
        printf("\n");
    }
}

int stack_size(struct Stack * s) {
    return s->n;
}

void stack_clear(struct Stack *s) {
    s->n = 0;
}