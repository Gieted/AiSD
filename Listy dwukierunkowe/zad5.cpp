#include <iostream>

using namespace std;


struct elem {
    char dane;
    elem * poprz;
    elem * nast;
};

elem* arrayToList(char array[], int arraySize) {
    struct elem* firstElement = (struct elem*) malloc(sizeof(firstElement));
    firstElement->dane = array[0];
    elem* previousElement = firstElement;
    
    for (int i = 1; i < arraySize; ++i) {
        struct elem* nextElement = (struct elem*) malloc(sizeof(firstElement));
        nextElement->dane = array[i];
        previousElement->nast = nextElement;
        nextElement->poprz = previousElement;
        previousElement = nextElement;
    }
    
    return firstElement;
}

char operators[] = {'+', '-', '*', '/'};

bool isOperator(char character) {
    for (int i = 0; i < sizeof(operators); ++i) {
        if (operators[i] == character) {
            return true;
        }
    }
    
    return false;
}

elem* findLastArgument(elem* theOperator) {
    elem* pointer = theOperator->nast;
    if (pointer == NULL) {
        return NULL;
    }
    if (isOperator(pointer->dane)) {
        pointer = findLastArgument(pointer);
        if (pointer == NULL) {
            return NULL;
        }
    }

    pointer = pointer->nast;
    if (pointer == NULL) {
        return NULL;
    }
    if (isOperator(pointer->dane)) {
        pointer = findLastArgument(pointer);
        if (pointer == NULL) {
            return NULL;
        }
    }

    return pointer;
}

bool is_valid_pn(elem* lista) {
    if (isOperator(lista->dane)) {
        elem* lastArgument = findLastArgument(lista);
        if (lastArgument == NULL) {
            return false;
        }
        
        return lastArgument->nast == NULL;
    } else {
        return lista->nast == NULL;
    }
}

int main()
{
    char np1[] {'/', '+', 'a', 'b', 'c'};
    
    cout << is_valid_pn(arrayToList(np1, sizeof(np1))) << endl;
    
    char np2[] {'/', '+', 'a', 'b', '-', 'c', 'd'};
    
    cout << is_valid_pn(arrayToList(np2, sizeof(np2))) << endl;

    char np3[] {'a'};
    
    cout << is_valid_pn(arrayToList(np3, sizeof(np3))) << endl;

    char bad_np1[] {'/', '+', 'a', 'b', 'c', 'd'};
    
    cout << is_valid_pn(arrayToList(bad_np1, sizeof(bad_np1))) << endl;
    
    char bad_np2[] {'/'};
    
    cout << is_valid_pn(arrayToList(bad_np2, sizeof(bad_np2))) << endl;

    return 0;
}
