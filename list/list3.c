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

int list_is_empty(struct Node * list) {
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

struct Node * from_hand(struct Node * list) {
	//list->data = list_pop_front(list);
	struct Node * p = list->next;
	list_remove(p);
	return p;
}

void to_hand(struct Node * list, struct Node * a) {
	//list_push_back(list, a->data);
	list_insert_before(list, a);
}
	
void win_check(struct Node * list1, struct Node * list2) {
	struct Node * a = from_hand(list1);
	struct Node * b = from_hand(list2);
	//Data a = list_pop_front(list1);
	//Data b = list_pop_front(list2);

	if ((a->data > b->data)) {
		if ((a->data == 9) && (b->data == 0)) {
			//list_push_back(list2, a);
			//list_push_back(list2, b);
			to_hand(list2, a);
			to_hand(list2, b);
		}
		else {
			//list_push_back(list1, a);
			//list_push_back(list1, b);
			to_hand(list1, a);
			to_hand(list1, b);
		}
	}
	else {
		if ((a->data == 0) && (b->data == 9)) {
			//list_push_back(list1, a);
			//list_push_back(list1, b);
			to_hand(list1, a);
			to_hand(list1, b);
		}
		else {
			//list_push_back(list2, a);
			//list_push_back(list2, b);
			to_hand(list2, a);
			to_hand(list2, b);
		}
	}
		
}

int main()
{
	struct Node * list1 = malloc(sizeof(struct Node));
	struct Node * list2 = malloc(sizeof(struct Node));
	list_init(list1);
	list_init(list2);
	int i;
	for (i = 0; i < 5; i++) {
		Data x;
		scanf("%d", &x);
		list_push_back(list1, x);
	}

	for (i = 0; i < 5; i++) {
		Data y;
		scanf("%d", &y);
		list_push_back(list2, y);
	}
	
	int n = 0;
	for(; !list_is_empty(list1) && !list_is_empty(list2) && n <= 1000000; n++) {
		win_check(list1, list2);
	}

	if (list_is_empty(list1)) {
		printf("second %d\n", n);
	}
	else {
		if (list_is_empty(list2)) {
			printf("first %d\n", n);
		}
		else {
			printf("botva\n");
		}
	}

	list_clear(list1);
	list_clear(list2);
	free(list1);
	free(list2);

	return 0;
}