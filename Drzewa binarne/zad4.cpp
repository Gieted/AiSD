#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

bool is_BST(node *tree)
{
    if (tree->left == NULL || tree->left != NULL && is_BST(tree->left) && tree->left->data < tree->data)
        if (tree->right == NULL || tree->right != NULL && is_BST(tree->right) && tree->right->data > tree->data)
            return true;
    return false;
};

