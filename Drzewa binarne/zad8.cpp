#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

node* mirror_tree(node* tree)
{
    if(tree == nullptr)
        return nullptr;
    node* tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;
    mirror_tree(tree->left);
    mirror_tree(tree->right);
    return tree;
}
