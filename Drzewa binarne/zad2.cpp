#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

int node_count(node *tree)
{
    int i = 1;
    if (tree->left != NULL)
        i = i + node_count(tree->left);
    if (tree->right != NULL)
        i = i + node_count(tree->right);
    return i;
};

int leaves_count(node *tree)
{
    int i = 0;
    if (tree->left == NULL && tree->right == NULL)
        i++;
    if (tree->left != NULL)
        i = i + leaves_count(tree->left);
    if (tree->right != NULL)
        i = i + leaves_count(tree->right);
    return i;
};

int right_children_count(node *tree)
{
    int i = 0;
    if (tree->left != NULL)
        i = i + right_children_count(tree->left);
    if (tree->right != NULL)
    {
        i++;
        i = i + right_children_count(tree->right);
    }
    return i;
};

int tree_height(node *tree)
{
    int l = 1;
    int r = 1;
    if (tree->left != NULL)
        l = l + tree_height(tree->left);
    if (tree->right != NULL)
        r = r + tree_height(tree->right);

    if (l > r)
        return l;
    else
        return r;
};

int main()
{
    node *tree = new node;
    tree->data = 1;
    tree->left = new node;
    tree->left->data = 2;
    tree->left->left = new node;
    tree->left->left->data = 3;
    tree->left->right = new node;
    tree->left->right->data = 4;
    tree->right = new node;
    tree->right->data = 5;
    tree->right->left = new node;
    tree->right->left->data = 6;
    tree->right->right = new node;
    tree->right->right->data = 7;

    std::cout << "Liczba wezlow: " << node_count(tree) << std::endl;
    std::cout << "Liczba lisci: " << leaves_count(tree) << std::endl;
    std::cout << "Liczba wezlow z prawej strony: " << right_children_count(tree) << std::endl;
    std::cout << "Wysokosc drzewa: " << tree_height(tree) << std::endl;

    return 0;
}
