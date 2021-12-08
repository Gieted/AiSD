#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *nast;
};

void push(elem *&stos, int x)
{
    elem *tmp = new elem;
    tmp->dane = x;
    tmp->nast = stos;
    stos = tmp;
}

int pop(elem *&stos)
{
    if (stos != NULL)
    {
        elem *tmp = stos;
        stos = stos->nast;
        int
            wynik = tmp->dane;
        delete tmp;
        return wynik;
    }
    else
    {
        cout << "stos jest pusty!" << endl;
        return 0;
    }
}

void wypiszWspakStosem(elem *lista)
{
    elem *stos = NULL;
    while (lista !=
           NULL)
    {
        push(stos, lista->dane);
        lista = lista->nast;
    }
    while (stos != NULL)
    {
        cout << pop(stos) << " ";
    }
}
