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

const char * bra_open = "({[<";
const char * bra_close = ")}]>";

int ind(Data x) {
    int res = 0;
    for (int j = 0; j < 4; j++) {
        if ((x == bra_open[j]) || (x == bra_close[j])) {
            res = j;
        }
    }
    return res;
}

int true_bra(char s[], struct Stack * c) {
    for(int i = 0; i < strlen(s); i++) {
        if (strchr(bra_open, s[i]) != NULL) {
            stack_push(c, s[i]);
        }
        if (strchr(bra_close, s[i]) != NULL) {
            if (stack_is_empty(c)) {
                return 0;
            }
            else {
                if (ind(s[i]) == ind(c->a[c->n-1])) {
                    stack_pop(c);
                } 
                else {
                    return 0;
                }
            }
        }
    }
    if (stack_is_empty(c)) {
        return 1;
    }
    else {
        return 0;
    }

    return 1;
}

int main()
{
    struct Stack stack;
    struct Stack * st = &stack;
    char * s = NULL;
    scanf("%ms", &s);
    st = stack_create(strlen(s));
    int x = true_bra(s, st);
    if (x == 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    stack_clear(st);
    stack_destroy(st);
    free(s);

    return 0;
}


