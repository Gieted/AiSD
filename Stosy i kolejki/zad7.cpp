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

void OdwrocStos(elem *&stos)
{
    elem *tmp = NULL;
    while (stos != NULL)
    {
        push(tmp, pop(stos));
    }
    stos = tmp;
}

void add(elem *&pocz_kolejki, elem *&kon_kolejki, int x)
{
    elem *tmp = new elem;
    tmp->dane = x;
    tmp->nast = NULL;
    if (pocz_kolejki != NULL)
    {
        kon_kolejki->nast = tmp;
        kon_kolejki = tmp;
        if (pocz_kolejki->nast == NULL)
            pocz_kolejki->nast = kon_kolejki;
    }
    else
    {
        kon_kolejki = pocz_kolejki = tmp;
    }
}

int next(elem *&pocz_kolejki, elem *&kon_kolejki)
{
    if (pocz_kolejki != NULL)
    {
        elem *tmp = pocz_kolejki;
        pocz_kolejki = pocz_kolejki->nast;
        int wynik = tmp->dane;
        delete tmp;
        return wynik;
    }
    else
    {
        cout << "kolejka jest pusta!" << endl;
        return 0;
    }
}

void OdwrocStosKol(elem *&stos)
{
    elem *pocz_kolejki = NULL;
    elem *kon_kolejki = NULL;
    while (stos != NULL)
    {
        add(pocz_kolejki, kon_kolejki, pop(stos));
    }
    while (pocz_kolejki != NULL)
    {
        push(stos, next(pocz_kolejki, kon_kolejki));
    }
}
