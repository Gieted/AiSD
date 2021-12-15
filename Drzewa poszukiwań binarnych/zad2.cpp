#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *reconstruct(int *a, const int k)
{
    if (k == 1)
    {
        node *nowy = new node;
        nowy->data = a[0];
        nowy->left = NULL;
        nowy->right = NULL;
        return nowy;
    }
    else
    {
        node *nowy = new node;
        nowy->data = a[k / 2];
        nowy->left = reconstruct(a, k / 2);
        nowy->right = reconstruct(a + k / 2 + 1, k / 2);
        return nowy;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    node *root = reconstruct(a, n);
    cout << root->data << endl;
    return 0;
}
