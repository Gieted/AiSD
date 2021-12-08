#include <iostream>

using namespace std;

struct elemChar
{
    char dane;
    elemChar *nast;
};

void pushChar(elemChar *&stos, char x)
{
    elemChar *tmp = new elemChar;
    tmp->dane = x;
    tmp->nast = stos;
    stos = tmp;
}

char popChar(elemChar *&stos)
{
    if (stos != NULL)
    {
        elemChar *tmp = stos;
        stos = stos->nast;
        char wynik = tmp->dane;
        delete tmp;
        return wynik;
    }
    else
    {
        cout << "stos jest pusty!" << endl;
        return 0;
    }
}

int main()
{
    elemChar *stosChar = NULL;
    string ciag = "EAS*Y*QUE***ST***IO*N***";
    cout << "Ciag wejsciowy: " << ciag << endl;
    cout << "Ciag wyjsciowy: ";
    int n = 0;
    while (n < ciag.length())
    {
        if (ciag[n] != '*')
            pushChar(stosChar, ciag[n]);
        else
            cout << popChar(stosChar);
        n++;
    }
    return 0;
}
