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

int topEl(elem *stos)
{
    if (stos != NULL)
        return stos->dane;
    else
    {
        cout << "stos jest pusty" << endl;
        return 0;
    }
}

bool isEmpty(elem *stos)
{
    if (stos == NULL)
        return true;
    else
        return false;
}
