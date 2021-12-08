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

void PrzeniesStos(elem *&stos1, elem *&stos2)
{
    elem *tmp = NULL;
    while (stos1 != NULL)
    {
        push(tmp, pop(stos1));
    }
    while (tmp != NULL)
    {
        push(stos2, pop(tmp));
    }
}

// bez stosu
void Przenies(elem *&stos1, elem *&stos2)
{
    elem *licznik = stos1;
    int n = 0;
    while (licznik != NULL)
    {
        n++;
        licznik = licznik->nast;
    }
    int tab[n];
    for (int m = 0; m < n; m++)
    {
        tab[m] = pop(stos1);
    }
    n--;
    while (n >= 0)
    {
        push(stos2, tab[n]);
        n--;
    }
}
