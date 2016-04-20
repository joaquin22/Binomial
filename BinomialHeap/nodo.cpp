#include "nodo.h"

Nodo::Nodo()
{

}

Nodo::Nodo(int key)
{
    this->key = key;
    nivel = 0;
    padre = 0;
}

void Nodo::Merge(Nodo * nodo)
{
    cout<<nodo->key<<endl;
    nivel++;
    hijos.push_front(nodo);
}
