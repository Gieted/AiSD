#include <iostream>

struct elem
{
    int expo;
    int coef;
    elem *nast;
};

void append(int expo, int coef, elem *&a)
{
    if (a == NULL)
    {
        a = new elem{expo, coef, NULL};
        return;
    }
    elem *tail = a;
    for (; tail->nast != NULL; tail = tail->nast)
        ;
    tail->nast = new elem{expo, coef, NULL};
}

void append_list(elem *&l1, elem *l2)
{
    elem *tail = l1;
    for (; tail->nast != NULL; tail = tail->nast)
        ;
    tail->nast = l2;
}

elem *polyadd(elem *l1, elem *l2)
{
    elem *res = NULL;
    while (true)
    {
        if (l1->expo > l2->expo)
        {
            append(l1->expo, l1->coef, res);
            l1 = l1->nast;
        }
        else if (l1->expo == l2->expo)
        {
            append(l1->expo, l1->coef + l2->coef, res);
            l1 = l1->nast;
            l2 = l2->nast;
        }
        else
        {
            append(l2->expo, l2->coef, res);
            l2 = l2->nast;
        }

        if (l1 == NULL)
        {
            append_list(res, l2);
            return res;
        }
        if (l2 == NULL)
        {
            append_list(res, l1);
            return res;
        }
    }
}

void print(elem *a)
{
    for (; a != NULL; a = a->nast)
    {
        char sign = a->coef > 0 ? +'+' : ' ';
        std::cout << sign << a->coef << "x^(" << a->expo << ")\n";
    }
}

int main()
{
    elem *l1 = NULL;
    elem *l2 = NULL;

    append(6, -2, l1);
    append(3, 1, l1);
    append(2, 4, l1);
    append(1, 4, l1);
    append(0, 4, l1);

    append(7, 2, l2);
    append(5, 1, l2);
    append(2, 8, l2);
    print(polyadd(l1, l2));

    return 0;
}
