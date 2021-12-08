#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *nast;
};

int size(elem *lista)
{
    int n = 0;
    while (lista != NULL)
    {
        n++;
        lista = lista->nast;
    }
    return n;
}

void wypiszWspak(elem *lista)
{
    int n = size(lista);
    while (n > 0)
    {
        int m = 1;
        elem *pom = lista;
        while (m < n)
        {
            pom = pom->nast;
            m++;
        }
        cout << pom->dane << " ";
        n--;
    }
}
