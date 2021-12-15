#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

int tree_height(node *tree)
{
    if (tree == NULL)
        return 0;
    else if (tree != NULL && tree->left == NULL && tree->right == NULL)
        return 0;
    int heightL = tree_height(tree->left);
    int heightR = tree_height(tree->right);
    if (heightL > heightR)
        return heightL + 1;
    else
        return heightR + 1;
}

bool is_balanced(node *tree)
{
    if (tree == NULL)
        return true;
    int left = 0;
    int right = 0;
    left = tree_height(tree->left);
    right = tree_height(tree->right);
    int r = right - left;
    if ((r == 0 || r == 1 || r == -1) && is_balanced(tree->right) && is_balanced(tree->left))
        return true;
    else
        return false;
}
