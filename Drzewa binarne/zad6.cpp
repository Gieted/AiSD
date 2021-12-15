#include <stdio.h>
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void preorder(node *tree)
{
    if (tree != NULL)
    {
        cout << tree->data << endl;
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(node *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        cout << tree->data << endl;
        inorder(tree->right);
    }
}

void postorder(node *tree)
{
    if (tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        cout << tree->data << endl;
    }
}

void dodaj(int dana, node *&tree)
{
    if (tree == NULL)
    {
        tree = new node;
        tree->data = dana;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (dana < tree->data)
        dodaj(dana, tree->left);
    else if (dana > tree->data)
        dodaj(dana, tree->right);
}

int main()
{
    node *tree = NULL;
    dodaj(10, tree);
    dodaj(5, tree);
    dodaj(20, tree);
    dodaj(30, tree);
    dodaj(15, tree);
    dodaj(13, tree);
    dodaj(4, tree);
    dodaj(6, tree);
    dodaj(7, tree);
    dodaj(0, tree);
    dodaj(9, tree);

    if (p->left == 0)
    {
        p->right = 0;
        preorder(tree);
        inorder(tree);
        postorder(tree);
    }

    if (p->left != 0 && p->data - p->left->data < 2)
    {
        p->left->data += 2;
        preorder(tree);
        inorder(tree);
        postorder(tree);
    }

    cout << endl;
    return 0;
}
