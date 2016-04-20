#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H
#include "nodo.h"
#include <fstream>
#include <list>


using namespace std;

class BinomialHeap
{
public:
    BinomialHeap(int tipo);//0 - min; 1 - max;

    void Merge();
    bool Comparar(int a, int b);
    void Add(Nodo*);
    void DeleteMin();

    Nodo *Search(int key);
    Nodo *Search(Nodo* nodo, int key);
    void Delete(int key);
    void DecreaseKey(Nodo * nodo, int valor);
    void PrintDot(Nodo *p,ofstream & os);
    void PrintDot(char *p);

    ~BinomialHeap();

// privadooooooooooooooooooooooo
    int tipo;
    list<Nodo*> hijos;
    Nodo* menor_mayor;

};

#endif // BINOMIALHEAP_H
