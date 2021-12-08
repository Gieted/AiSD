#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *nast;
};

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

int firstEl(elem *pocz_kolejki)
{
    if (pocz_kolejki != NULL)
        return pocz_kolejki->dane;
    else
    {
        cout << "kolejka jest pusta" << endl;
        return 0;
    }
}

bool isEmpty(elem *pocz_kolejki)
{
    if (pocz_kolejki == NULL)
        return true;
    else
        return false;
}

int main()
{
    elem *pocz = NULL;
    elem *kon = NULL;
    next(pocz, kon);
    int tab[] = {5, 66, 17, 0, 2, 157};
    for (int n = 0; n < 6; n++)
    {
        add(pocz, kon, tab[n]);
        cout << "dodano do kolejki element o wartosc: " << tab[n] << endl;
    }
    cout << "na poczatku kolejki znajduje sie: " << firstEl(pocz) << endl;
    cout << "teraz zdejmujemy nextem : ";
    while (!isEmpty(pocz))
    {
        cout << next(pocz, kon) << ", ";
    }
    return 0;
}
