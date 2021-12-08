#include <iostream>

using namespace std;

struct Kolejka
{
    int el[100];
    int zajete;
};

void addTab(Kolejka &kol, int x)
{
    if (kol.zajete < 100)
    {
        kol.el[kol.zajete] = x;
        kol.zajete++;
    }
    else
    {
        cout << "Kolejka jest pelna!" << endl;
    }
}

int nextTab(Kolejka &kol)
{
    if (kol.zajete != 0)
    {
        int wynik = kol.el[0];
        for (int n = 0; n < kol.zajete - 1; n++)
        {
            kol.el[n] = kol.el[n + 1];
        }
        kol.zajete--;
        return wynik;
    }
    else
    {
        cout << "kolejka jest pusta" << endl;
        return 0;
    }
}

int firstElTab(Kolejka kol)
{
    if (kol.zajete != 0)
        return kol.el[0];
    else
    {
        cout << "kolejka jest pusta" << endl;
        return 0;
    }
}

bool isEmptyTab(Kolejka kol)
{
    if (kol.zajete == 0)
        return true;
    else
        return false;
}
