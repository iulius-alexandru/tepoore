#pragma once
#include "e_multime.h"
template<class T>
class pereche:public e_multime<T>
{
    T y;
    public:
     pereche(T a,T b);
    pereche();
    template<class T2>
    friend istream& operator>>(istream &,pereche<T2> &);
    bool operator ==(pereche<T>);
    template<class T2>
    friend ostream& operator<<(ostream &,const pereche<T2> &);
};
template<class T>
bool pereche<T>::operator ==(pereche B)
{
    return((e_multime<T>::x==B.x)&&(y==B.y));
}
template<class T>
pereche<T>::pereche(T a,T b):e_multime<T>(a)
{
    y=b;
}
template<class T>
pereche<T>::pereche(){}
template<class T2>
istream& operator>>(istream &in,pereche<T2> &A)
{
    in>>(e_multime<T2> &)A>>A.y;
    return in;
}
template<class T2>
ostream& operator<< (ostream &out,const pereche<T2> &A)
{
    out<<'('<<(e_multime<T2> &)A<<','<<A.y<<')';
    return out;
}
