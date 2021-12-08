#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *nast;
};

void print(elem *lista)
{
    cout << "zawartosc listy: ";
    while (lista != NULL)
    {
        cout << lista->dane << " ";
        lista = lista->nast;
    }
}
