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
