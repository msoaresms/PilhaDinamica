#include <iostream>
#include "Item.h"
#include "Pilha.h"
using namespace std;

int main(){
    Pilha<Item> p;
    Item x;

    Item a(1, "A");
    Item b(2, "B");
    Item c(3, "C");
    Item d(42, "M");

    p.empilha(a);

    p.empilha(a);
    p.empilha(b);
    p.empilha(c);

    p.desempilha(&x);

    p.empilha(d);

    p.desempilha(&x);
    p.desempilha(&x);
    p.desempilha(&x);

    return 0;
}