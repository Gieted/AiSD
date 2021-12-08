#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *poprz;
    elem *nast;
};

void reverse_cyclic(elem *lista)
{
    if (lista != NULL)
    {
        elem *pom1 = lista;
        elem *pom2 = lista->nast;
        do
        {
            elem *pom3 = pom2;
            pom2 =
                pom2->nast;
            pom3->nast = pom1;
            pom1 =
                pom3;
        } while (pom1 != lista);
    }
}
