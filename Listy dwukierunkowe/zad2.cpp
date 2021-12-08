#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *poprz;
    elem *nast;
};

void reverse(elem *&lista)
{
    while (lista->nast != NULL)
    {
        lista = lista->nast;
    }
    elem *pom = lista;
    while (pom !=
           NULL)
    {
        elem *pom2 = pom->poprz;
        pom->poprz = pom->nast;
        pom->nast =
            pom2;
        pom = pom->nast;
    }
}
