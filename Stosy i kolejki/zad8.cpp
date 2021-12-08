#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

struct elem {
	int dane;
	elem * nast;
};

void push(elem* &stos, int x) {
	elem* element = new elem();
	element -> dane = x;
	element -> nast = stos;
	stos = element;
}

int pop(elem* &stos) {
	if(isEmpty(stos)) return -1;
	elem* element = stos;
	stos = stos -> nast;
	free(element);
}

bool isEmpty(elem* stos) {
	return !stos;
}

elem *kopiujStos(elem *stos)
{
    if (stos == NULL)
        return NULL;
    else
    {
        elem *stosKopia = (elem *)malloc(sizeof(elem));
        stosKopia->dane = stos->dane;
        stosKopia->nast = kopiujStos(stos->nast);
        return stosKopia;
    }
}

elem *sortujStos(elem *oryginalnyStosDoPosortowania)
{

    elem *stosDoPosortowania = kopiujStos(oryginalnyStosDoPosortowania);
    elem *stosPosortowany = NULL;
    int bufor;

    while (!isEmpty(stosDoPosortowania))
    {

        bufor = topEl(stosDoPosortowania);
        pop(stosDoPosortowania);

        while (!isEmpty(stosPosortowany) && bufor < topEl(stosPosortowany))
        {
            push(stosDoPosortowania, topEl(stosPosortowany));
            pop(stosPosortowany);
        }
        push(stosPosortowany, bufor);
    }
    return stosPosortowany;
}

int topEl(elem* stos) {
	if(isEmpty(stos)) return -1;
	return stos->dane;
}

int main()
{
    elem *posortujMnie = NULL;
    push(posortujMnie, 3);
    push(posortujMnie, 765);
    push(posortujMnie, 21);
    push(posortujMnie, INT_MAX);
    push(posortujMnie, -666);
    push(posortujMnie, 21);
    push(posortujMnie, 37);
    push(posortujMnie, 0);
    push(posortujMnie, INT_MIN);

    elem *stosPosortowany = sortujStos(posortujMnie);

    cout << "Nieposortowany stos:\n";
    while (!isEmpty(posortujMnie))
    {
        cout << topEl(posortujMnie) << "\n";
        pop(posortujMnie);
    }

    cout << "\nPosortowany malejaco stos:\n";
    while (!isEmpty(stosPosortowany))
    {
        cout << topEl(stosPosortowany) << "\n";
        pop(stosPosortowany);
    }
}
