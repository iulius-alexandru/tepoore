#pragma once
#include "stiva.h"
template<class T>
class coada: public stiva<T>
{
    private:
    stiva<T> v1;
    public:
    coada();
    coada(int);
    coada(const coada&);
    e_multime<T>pop();

};
template<class T>coada<T>::coada(){}
template<class T>coada<T>::coada(int n):stiva<T>(n){}
template<class T>coada<T>::coada(const coada&A):stiva<T>(A){}
template<class T>
e_multime<T> coada<T>::pop()
{
    if(stiva<T>::varf)
   {while(stiva<T>::null())
    v1.add(stiva<T>::pop());
    e_multime<T> x=v1.pop();
    while(v1.null())
    stiva<T>::add(v1.pop());
    return x;
   }
   else {cout<<"nu poti sterge dintr-o coada nula";cout<<1/0;}
}
