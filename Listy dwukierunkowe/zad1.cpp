#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *poprz;
    elem *nast;
};

void insert(int x, int i, elem *&poczatek)
{
    elem *tmp = new elem;
    tmp->dane = x;
    tmp->nast = NULL;
    tmp->poprz = NULL;
    if (poczatek == NULL)
    {
        poczatek = tmp;
        cout << "dodano do listy: " << x << endl;
    }
    else
    {
        if (i <= 1)
        {
            poczatek->poprz = tmp;
            tmp->nast = poczatek;
            poczatek = tmp;
            cout << "podano zbyt niski indeks! dolaczono na poczatek listy: " << x << endl;
        }
        else
        {
            int n = 1;
            elem *pom = poczatek;
            while ((n < i - 1) && (pom->nast != NULL))
            {
                n++;
                pom = pom->nast;
            }
            if (pom->nast == NULL)
            {
                cout << "indeks powyzej zakresu, dodano na koniec listy: " << x << endl;
                tmp->poprz = pom;
                pom->nast = tmp;
            }
            else
            {
                elem *pom2 = pom->nast;
                pom2->poprz = tmp;
                tmp->nast = pom2;
                tmp->poprz = pom;
                pom->nast = tmp;
                cout << "dodano wewnatrz listy: " << x << endl;
            }
        }
    }
}

void remove(elem *&poczatek)
{
    elem *pom = poczatek;
    poczatek = poczatek->nast;
    delete pom;
}

void remove(int i, elem *&poczatek)
{
    if (i < 1)
    {
        cout << "indeks ponizej zakresu!" << endl;
    }
    else if (poczatek != NULL)
    {
        elem *pom = poczatek;
        int n = 1;
        while ((n < i - 1) && (pom->nast != NULL))
        {
            pom = pom->nast;
            n++;
        }
        if (pom->nast == NULL)
        {
            cout << "indeks powyzej zakresu!" << endl;
        }
        else
        {
            elem *pom2 = pom->nast;
            if (pom2->nast != NULL)
            {
                elem *pom3 = pom2->nast;
                pom->nast = pom3;
                pom3->poprz = pom;
            }
            else
            {
                pom->nast = NULL;
            }
            delete pom2;
        }
    }
}
