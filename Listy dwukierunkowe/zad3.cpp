#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *poprz;
    elem *nast;
};

void to_cyclic(elem *&lista)
{
    if (lista != NULL)
    {
        elem *pom = lista;
        while (pom->nast != NULL)
        {
            pom = pom->nast;
        }
        pom->nast = lista;
        lista->poprz = pom;
    }
}
