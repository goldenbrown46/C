#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
    Data val;
    struct Node * left;
    struct Node * right;
};

struct Node * tree_add (struct Node * tree, Data x) {
    if (tree == NULL) {
        struct Node * p = malloc(sizeof(struct Node));
        p->val = x;
        p->left = p->right = NULL;
        return p;
    }
    if (x < tree->val) {
        tree->left = tree_add(tree->left, x);
    }
    if (x > tree->val) {
        tree->right = tree_add(tree->right, x);
    }
    return tree;
}

void tree_print (struct Node * tree) {
    if (tree == NULL) {
        return;
    }
    tree_print(tree->left);
    if (tree->right == NULL && tree->left == NULL) {
        printf("%d ", tree->val);
    }
    tree_print(tree->right);
}

void tree_destroy (struct Node * tree) {
    if (tree == NULL) {
        return;
    }
    tree_destroy(tree->left);
    tree_destroy(tree->right);
    free(tree);
}

int main() {
    struct Node * tree = NULL;
    Data x = -1;
    while (x != 0) {
        scanf("%d", &x);
        if (x != 0) {
            tree = tree_add(tree, x);
        }
    }
    tree_print(tree);
    printf("\n");
    tree_destroy(tree);

    return 0;
}