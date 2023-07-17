#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
    struct Node * next;
    struct Node * prev;
    Data data;
};

void list_init(struct Node * list) {
	list->next = list->prev = list;
}

int  list_is_empty(struct Node * list) {
	return list->next == list;
}

void list_insert(struct Node * list, struct Node * t) {
	t->next = list->next;
	t->prev = list;
	list->next->prev = t;
	list->next = t;
}

void list_insert_before(struct Node * list, struct Node * t) {
    list_insert(list->prev, t);
}

void list_remove(struct Node * list) {
    struct Node * p = list->prev;
	p->next = list->next;
	list->next->prev = p;
}

struct Node * list_push_front(struct Node * list, Data d) {
	struct Node * p = malloc(sizeof(struct Node));
	p->data = d;
	list_insert(list, p);

	return p;
}

struct Node * list_push_back(struct Node * list, Data d) {
	struct Node * p = malloc(sizeof(struct Node));
	p->data = d;
	list_insert_before(list, p);

	return p;
}

Data list_delete(struct Node * p) {
	list_remove(p);
	Data d = p->data;
	free(p);

	return d;
}

Data list_pop_front(struct Node * list) {
	if(list_is_empty(list)) {
		return 0;
    }

	return list_delete(list->next);
}

Data list_pop_back(struct Node * list) {
	if(list_is_empty(list)) {
		return 0;
    }

	return list_delete(list->prev);
}

void list_print(struct Node * list) {
    for (struct Node * p = list->next; p != list; p = p->next) {
        printf("%d ", p->data);
    }
	printf("\n");
}

void list_clear(struct Node * list) {
    while(!list_is_empty(list)) {
        list_delete(list->next);
    }
}

int main()
{
    struct Node x[10];
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * b = malloc(sizeof(struct Node));

	int i;
    list_init(a);
	list_init(b);
	// End of test 1
	
	for(i=0; i<10; i++) {
		x[i].data = i;
		list_insert(a, &x[i]);
	}
	list_print(a);   // 9 8 7 6 5 4 3 2 1 0 
	// End of test 2
	
	list_remove(&x[5]);
	list_print(a);
	list_remove(&x[0]);
	list_print(a);
	list_remove(&x[9]);
	list_print(a);
	// End of test 3
	
	list_insert_before(a, &x[0]);
	list_print(a);
	list_insert(a, &x[9]);
	list_print(a);
	list_insert(&x[6], &x[5]);
	list_print(a);
	// End of test 4
	
	while(!list_is_empty(a))
		list_remove(a->next);
	// End of test 5

	for(i=0; i<10; i++)
		list_push_back(a, i);
	list_print(a);
	// End of test 6
	
	for(i=0; i<10; i++)
		list_push_front(b, list_pop_back(a));
	list_print(b);
	// End of test 7
	
	for(i=0; i<10; i++) {
		list_push_front(a, i);
		list_pop_front(b);
	}
	list_print(a);
	// End of test 8

	for(i=0; i<10; i++)
		list_push_back(b, list_pop_front(a));
	list_print(b);
	// End of test 9
	
	list_clear(a);
	list_clear(b);
	// End of test 10

    free(a);
    free(b);

    return 0;
}