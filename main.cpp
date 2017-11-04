#include <iostream>
#include "Item.h"
using namespace std;


template <class T>
class No{
private:
    T item;
    No<T> *prox;
public:
    const T &getItem() const {
        return item;
    }
    void setItem(const T &item) {
        this->item = item;
    }
    No<T> *getProx() const {
        return prox;
    }
    void setProx(No<T> *prox) {
        this->prox = prox;
    }
};

template <class T>
class Pilha{
private:
    No<T> *topo, *fundo;
    bool vazia() {
        return (this->topo == this->fundo);
    }
public:
    Pilha(){
        this->fundo = new No<T>();
        this->fundo->setProx(NULL);
        this->topo = this->fundo;
    }

    No<T> *getTopo() const {
        return topo;
    }
    void setTopo(No<T> *topo) {
        this->topo = topo;
    }
    No<T> *getFundo() const {
        return fundo;
    }
    void setFundo(No<T> *fundo) {
        this->fundo = fundo;
    }

    void empilha(T);
    void desempilha(T *);
};



template <typename T>
void Pilha<T>::empilha(T pItem) {
    No<T> *aux = new No<T>();
    this->topo->setItem(pItem);
    aux->setProx(this->topo);
    this->topo = aux;
}

template <typename T>
void Pilha<T>::desempilha(T *x) {
    if (!this->vazia()) {
        No<T> *aux = this->topo;
        this->topo = this->topo->getProx();
        *x = this->topo->getItem();
        delete aux;
    }
}

int main(int argc, const char * argv[]){
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