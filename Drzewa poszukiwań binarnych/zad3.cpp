#include <iostream>

struct node {
    int value;
    node *left;
    node *right;
};

bool search(node *root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->value == value) {
        return true;
    }
    if (root->value > value) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

int main() {
    node *root = new node;
    root->value = 5;
    root->left = new node;
    root->left->value = 3;
    root->left->left = new node;
    root->left->left->value = 2;
    root->left->right = new node;
    root->left->right->value = 4;
    root->right = new node;
    root->right->value = 7;
    root->right->left = new node;
    root->right->left->value = 6;
    root->right->right = new node;
    root->right->right->value = 8;
    std::cout << search(root, 6) << std::endl;
    std::cout << search(root, 9) << std::endl;
    return 0;
}
