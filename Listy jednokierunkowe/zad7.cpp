#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *nast;
};

elem *search(int x, elem *lista)
{
    while ((lista != NULL) && (lista->dane != x))
    {
        lista = lista->nast;
    }
    if (lista == NULL)
    {
        cout << "brak takiego elementu na liscie!" << endl;
        return NULL;
    }
    else
        return lista;
}
