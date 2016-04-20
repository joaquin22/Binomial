#include "binomialheap.h"

BinomialHeap::BinomialHeap(int tipo)
{
    this->tipo = tipo;
}

void BinomialHeap::Merge()
{
    int nivelAnterior = -1;
    for (list<Nodo*>::iterator it=hijos.begin(); it != hijos.end(); ++it){
        if(nivelAnterior == (*it)->nivel){

            list<Nodo*>::iterator prevIt = prev(it);
            if(Comparar((*it)->key,(*prevIt)->key)){
                (*it)->Merge((*prevIt));
                (*prevIt)->padre = (*it);
                prevIt =  hijos.erase(prevIt);
            }else{
                (*prevIt)->Merge((*it));
                (*it)->padre = (*prevIt);
                if(it == hijos.end()){
                    hijos.pop_back();
                    return;
                }
                hijos.erase(it);
                it = prevIt;
            }
        }
        nivelAnterior = (*it)->nivel;
    }
}

bool BinomialHeap::Comparar(int a, int b)
{
    if(!tipo){
        return a<b;
    }else{
        return a>b;
    }
}

void BinomialHeap::Add(Nodo * nodo)
{
    if (Search(nodo->key)) return;

    if(hijos.empty()){
        hijos.push_front(nodo);
        menor_mayor = nodo;
        return;
    }

    if(Comparar(nodo->key, menor_mayor->key )){
        menor_mayor = nodo;
    }

    for (list<Nodo*>::iterator it=hijos.begin(); it != hijos.end(); ++it){
        if((*it)->nivel >= nodo->nivel){
            cout<<nodo->key<<endl;
            hijos.insert(it,nodo);
            //Merge();
            return;
        }
    }
    hijos.push_back(nodo);
    //Merge();
}

void BinomialHeap::DeleteMin()
{
    Nodo * tmp = menor_mayor;
    hijos.remove(menor_mayor);
    for (list<Nodo*>::iterator it=tmp->hijos.begin(); it != tmp->hijos.end(); ++it){
        (*it)->padre = 0;
        cout<<(*it)->key<<endl;
        Add(*it);
    }
    delete tmp;
    menor_mayor = *(hijos.begin());
    for (list<Nodo*>::iterator it=hijos.begin(); it != hijos.end(); ++it){
        if(Comparar((*it)->key,menor_mayor->key)){
            menor_mayor = (*it);
        }
    }
    Merge();
}

Nodo* BinomialHeap::Search(int key)
{
    for (list<Nodo*>::iterator it=hijos.begin(); it != hijos.end(); ++it){
        if((*it)->key == key){
            return (*it);
        }
        if(Comparar( (*it)->key, key)){
            Nodo * nod = Search((*it), key);
            if(nod){
                return nod;
            }
        }
    }
    return 0;
}

Nodo *BinomialHeap::Search(Nodo *nodo, int key)
{
    if(nodo->key == key){
        return nodo;
    }
    if(nodo->hijos.empty()){
        return 0;
    }

    for (list<Nodo*>::iterator it2=nodo->hijos.begin(); it2 != nodo->hijos.end(); ++it2){
        Nodo * nod = Search((*it2), key);
        if(nod){
            return nod;
        }
    }
    return 0;
}

void BinomialHeap::Delete(int key)
{
    Nodo *tmp  = Search(key);
    if(tmp){
        DecreaseKey(tmp,-1);
        DeleteMin();

    }

}

void BinomialHeap::DecreaseKey(Nodo *nodo, int valor)
{
    nodo->key = valor;
    if(nodo->padre){
        if(Comparar(nodo->key , nodo->padre->key)){
            int tmp = nodo->key;
            nodo->key = nodo->padre->key;
            nodo->padre->key = tmp;
            if(nodo->padre->key < menor_mayor->key) {
                menor_mayor = nodo->padre;
            }
            DecreaseKey(nodo->padre, nodo->padre->key);
        }
    }

}

void BinomialHeap::PrintDot(Nodo *p, ofstream &os)
{
    if(p->nivel == 0)return;
    for (list<Nodo*>::iterator it=p->hijos.begin(); it != p->hijos.end(); ++it){
        os<<p->key<<"->"<<(*it)->key<<endl;
        PrintDot((*it),os);
    }
}

void BinomialHeap::PrintDot(char *p)
{
    ofstream file(p);
    file<<"digraph {"<<endl;
    for (list<Nodo*>::iterator it=hijos.begin(); it != hijos.end(); ++it){
        file<<(*it)->key<<endl;
        PrintDot((*it),file);
    }
    file<<" }"<<endl;
}

BinomialHeap::~BinomialHeap()
{
    while (!hijos.empty()) {
        cout<<menor_mayor->key<<endl;
        DeleteMin();

    }
    cout<<"todo elminiado"<<endl;
}
