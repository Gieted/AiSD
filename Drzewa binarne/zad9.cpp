#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

void print_tree(node* tree, int depth = 0, char prefix = '.')
{
    if (tree == nullptr)
        return;
    print_tree(tree->right, depth + 1, prefix);
    std::cout << std::string(depth, prefix) << tree->data << std::endl;
    print_tree(tree->left, depth + 1, prefix);
}

int main()
{
    node *root = new node;
    root->data = 1;
    root->left = new node;
    root->left->data = 2;
    root->right = new node;
    root->right->data = 3;
    root->left->left = new node;
    root->left->left->data = 4;
    root->left->right = new node;
    root->left->right->data = 5;
    root->right->left = new node;
    root->right->left->data = 6;
    root->right->right = new node;
    root->right->right->data = 7;
    root->right->right->left = new node;
    root->right->right->left->data = 8;
    root->right->right->right = new node;
    root->right->right->right->data = 9;
    print_tree(root);
    
    return 0;
}
