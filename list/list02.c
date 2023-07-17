#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
    Data val;
    struct Node * next;
};

struct Node * list_create () {
    return NULL;
}

struct Node * list_push (struct Node * list, Data x) {
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    p->val = x;
    p->next = list;
    list = p;

    return list;
}

struct Node * list_pop (struct Node * list, Data * px) {
    struct Node * p = list;
    * px = p->val;
    list = p->next;
    free(p);

    return list;
}

Data list_get(struct Node * list) {
    return list->val;
}

void list_print (struct Node * list) {
    for (struct Node * p = list; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");
}

int list_size(struct Node * list) {
    int n = 0;
    for (struct Node * p = list; p != NULL; p = p->next) {
        n++;
    }
    return n;
}

int list_is_empty(struct Node * list) {
    return list == NULL;
}

struct Node * list_clear(struct Node * list) {
    struct Node * p = list;

    while( p != NULL ){
        list = list->next;
        free(p);
        p = list;
    }
    
    return NULL;
}

int main() {
    Data x;
    struct Node * list = list_create();
    list = list_push(list, 5);
    list_print(list);          // 5
    list = list_pop(list, &x);
    printf("x = %d\n", x);     // x = 5
    list = list_clear(list);

    return 0;
}