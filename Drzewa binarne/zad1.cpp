#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

node *search(node *tree, int x)
{
    while (tree != NULL && tree->data != x)
    {
        if (x < tree->data)
        {
            tree = tree->left;
        }
        else
        {
            tree = tree->right;
        }
    }
    return tree;
}
