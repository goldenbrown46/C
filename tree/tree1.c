#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок
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
    tree_print(tree);

    return 0;
}