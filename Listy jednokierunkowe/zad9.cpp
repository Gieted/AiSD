#include <iostream>

struct elem_farey
{
    int top;
    int bot;
    elem_farey *next;
};

void push(int top, int bot, elem_farey *&a)
{
    elem_farey *new_head = new elem_farey{top, bot, a};
    a = new_head;
}

void insert(int top, int bot, int i, elem_farey *&a)
{
    if (i == 1)
    {
        push(top, bot, a);
        return;
    }
    elem_farey *current_node = a;
    for (int index = 1; index != i - 1; current_node = current_node->next, ++index)
    {
        if (current_node->next == NULL)
            return;
    }
    elem_farey *current_node_next = current_node->next;
    current_node->next = new elem_farey{top, bot, current_node_next};
}

void print(elem_farey *a)
{
    for (; a != NULL; a = a->next)
        std::cout << a->top << "/" << a->bot << " " << std::endl;
}

elem_farey *make_farey(int n)
{
    elem_farey *list = new elem_farey{0, 1, NULL};
    list->next = new elem_farey{1, 1, NULL};
    for (int j = 1; j <= n; j++)
    {
        int i = 1;
        for (elem_farey *it = list; it->next != NULL; it = it->next, i++)
        {
            if (it->bot + it->next->bot <= j)
            {
                insert(it->top + it->next->top, it->bot + it->next->bot, i + 1, list);
            }
        }
    }
    return list;
}

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        print(make_farey(i));
    }
    return 0;
}
