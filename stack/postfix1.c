#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000

typedef char Data;

struct Stack {
    int n;
    int size;
    Data * a;
};

int stack_is_empty(struct Stack * s) {
    return s->n == 0;
}

int stack_is_full(struct Stack * s) {
    return s->n == s->size -1;
}

struct Stack * stack_create(int size) {
    struct Stack * s = malloc(sizeof(struct Stack));
    s->n = 0;
    s->size = N;
    s->a = malloc(s->size * sizeof(Data));

    return s;
}

void stack_push(struct Stack * s, Data x) {
    if (stack_is_full(s)) {
        s->size += N;
        s->a = realloc(s->a, s->size * sizeof(Data));
    }
    s->a[s->n] = x;
    s->n ++;
}

Data stack_pop(struct Stack * s) {
    if (stack_is_empty(s)) {
        return 0;
    }
    s->n --;
    return s->a[s->n];
}

Data stack_get(struct Stack *s) {
    if (stack_is_empty(s)) {
        return 0;
    }
    return s->a[s->n -1];
}

void stack_clear(struct Stack *s) {
    free(s->a);
    s->a = NULL;
    s->size = 0;
    s->n = 0;
}

void stack_destroy(struct Stack * s) {
    if (s != NULL) {
        free(s->a);
        free(s);
    }
}

int main()
{
    struct Stack stack;
    struct Stack * st = &stack;
    char * s = NULL;
    size_t len = 0;
    getline(&s, &len, stdin);
    st = stack_create(strlen(s));
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] == '0') || (s[i] == '1')) {
            stack_push(st, s[i]);
        }
        else {
            switch (s[i])
            {
            case '&':
                stack_push(st, stack_pop(st)&stack_pop(st));
                break;
            case '|':
                stack_push(st, stack_pop(st)|stack_pop(st));
                break;
            case '!':
                stack_push(st, !stack_pop(st));
                break;
        
            default:
                break;
            }
        }
    }

    Data t = stack_get(st);
    printf("%d\n", t-48);

    stack_clear(st);
    stack_destroy(st);
    free(s);

    return 0;
}