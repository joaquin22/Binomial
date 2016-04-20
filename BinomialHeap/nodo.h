#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <list>

using namespace std;
class Nodo
{
public:
    Nodo();
    Nodo(int key);


    int nivel;
    int key;
    Nodo * padre;
    list<Nodo*> hijos;
    void Merge (Nodo*);
};

#endif // NODO_H
