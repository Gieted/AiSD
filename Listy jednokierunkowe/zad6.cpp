#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *nast;
};

void destroy(elem *&lista)
{
    elem *tmp = NULL;
    while (lista !=
           NULL)
    {
        tmp = lista;
        lista = lista->nast;
        delete tmp;
    }
}
