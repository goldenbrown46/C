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
    printf("%d ", tree->val);
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

int main()
{
    struct Node * tree=NULL;
    tree = tree_add(tree, 7);
    tree = tree_add(tree, 3);
    tree = tree_add(tree, 2);
    tree = tree_add(tree, 1);
    tree = tree_add(tree, 9);
    tree = tree_add(tree, 5);
    tree = tree_add(tree, 4);
    tree = tree_add(tree, 6);
    tree = tree_add(tree, 8);
    tree_print(tree);   // напечатает 1 2 3 4 5 6 7 8 9
    tree_destroy(tree);

    return 0;
}