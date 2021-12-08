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
        int wynik = tmp->dane;
        delete tmp;
        return wynik;
    }
    else
    {
        cout << "stos jest pusty!" << endl;
        return 0;
    }
}

void addKolStos(elem *&glowny, int x)
{
    push(glowny, x);
}

int nextKolStos(elem *&glowny, elem *&pom)
{
    while (glowny != NULL)
    {
        push(pom, pop(glowny));
    }
    int wynik = pop(pom);
    while (pom != NULL)
    {
        push(glowny, pop(pom));
    }
    return wynik;
}
