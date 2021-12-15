#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

bool is_leaf(node *n)
{
    return n->left == NULL && n->right == NULL;
}

void delete_leaves(node *tree)
{
    if (tree != NULL)
    {
        if (is_leaf(tree->left))
        {
            delete tree->left;
            tree->left = NULL;
        }
        else
            delete_leaves(tree->left);
        if (is_leaf(tree->right))
        {
            delete tree->right;
            tree->right = NULL;
        }
        else
            delete_leaves(tree->right);
    }
}
