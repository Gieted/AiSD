#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *nast;
};

void insert(int x, int i, elem *&a)
{
    elem *tmp = new elem;
    tmp->dane = x;
    tmp->nast = NULL;
    if ((i <= 1) || (a == NULL))
    {
        tmp->nast = a;
        a = tmp;
        cout << "dodano na poczatek listy wartosc " << x << endl;
    }
    else
    {
        int n = 1;
        elem *
            pom = a;
        while ((n < i - 1) && (pom->nast != NULL))
        {
            pom = pom->nast;
            n++;
        }
        if (pom->nast == NULL)
        {
            pom->nast = tmp;
            cout << "Dolaczono na koniec listy wartosc " << x << endl;
        }
        else
        {
            tmp->nast = pom->nast;
            pom->nast = tmp;
            cout << "dodano wewnatrz listy wartosc " << x << endl;
        }
    }
}

void remove(int i, elem *&lista)
{
    if (i < 1)
    {
        cout << "indeks ponizej zakresu!" << endl;
    }
    else if (i == 1)
    {
        if (lista->nast == NULL)
            delete lista;
        else
        {
            elem *pom = lista;
            lista = lista->nast;
            delete pom;
        }
    }
    else
    {
        int n = 1;
        elem *pom = lista;
        while ((n < i - 1) && (pom->nast != NULL))
        {
            n++;
            pom = pom->nast;
        }
        if (pom->nast == NULL)
            cout << "indeks powyzej zakresu!" << endl;
        else
        {
            elem *pom2 = pom->nast;
            if (pom2->nast != NULL)
                pom->nast = pom2->nast;
            else
                pom->nast = NULL;
            delete pom2;
        }
    }
}

int read(int i, elem *lista)
{
    if (i < 1)
    {
        cout << "indeks ponizej zakresu!" << endl;
        return 0;
    }
    else
    {
        int n = 1;
        while ((n < i) && (lista != NULL))
        {
            lista = lista->nast;
            n++;
        }
        if (lista == NULL)
        {
            cout << "indeks powyzej zakresu!" << endl;
            return 0;
        }
        else
            return lista->dane;
    }
}
