#pragma once
#include "multime.h"
#include<iostream>
template<class T>
class stiva:public multime<T>
{
   protected:
   int varf;
   public:
   stiva();
   stiva(int);
   stiva(const stiva<T>&);
   template<class T2>
   friend istream& operator>>(istream &,stiva<T2> &);
   bool null();
   template<class T2>
   friend ostream& operator<<(ostream &,const stiva<T2> &);
   bool add(e_multime<T>);
   e_multime<T> pop();

};
template<class T>stiva<T>::stiva(const stiva<T>& A):multime<T>(A){varf=A.varf;}
template<class T>bool stiva<T>::null(){if(varf)return 1; else return 0;}
template<class T>stiva<T>::stiva(){varf=0;}
template<class T>stiva<T>::stiva(int n):multime<T>(n){varf=0;}
template<class T>
bool stiva<T>::add(e_multime<T> x)
{
    int l=multime<T>::dim;
    if(varf==l)
       multime<T>::redim(l+1);

    multime<T>::v[varf]=x;
   ++varf;
}
template<class T>
e_multime<T> stiva<T>::pop()
{
    if(varf)
    {
        --varf;
        return (multime<T>::pop(varf));
    }
    else
    {
        cout<<"nu puteti goli o stiva goala";
        return 1/0;
    }

}
template<class T2>
istream& operator>>(istream &in,stiva<T2> &A)
{
    int x; in>>x;
    A.redim(x);
    A.varf=x;
    for(int i=0;i<x;i++)
        in>>A.v[i];
    return in;
}
template<class T2>
ostream& operator<<(ostream &out,const stiva<T2> &A)
{
    for(int i=0;i<A.varf;i++)
        out<<A.v[i]<<' ';
    return out;
}
