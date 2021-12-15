#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

node *reconstruct(int *a, const int k)
{
    if (k == 0)
    {
        return nullptr;
    }
    node *root = new node;
    root->data = a[k - 1];
    root->left = reconstruct(a, k / 2);
    root->right = reconstruct(a + k / 2, k / 2);
    return root;
}

int main()
{
    int n;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    node *root = reconstruct(a, n);
    delete[] a;
    std::cout << root->data << std::endl;
    return 0;
}
