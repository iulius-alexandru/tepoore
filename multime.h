#pragma once
#include<istream>
#include<ostream>
#include<iostream>
#include "pereche.h"
using namespace std;
template<class T>
class multime
{
   protected:
    int dim;
   e_multime<T> *v;
   public:
  virtual e_multime<T> pop(){return v[0];}
   multime();
   multime(int n);
   multime(const multime &);
   void redim(int);
   template<class T2>
   friend istream& operator>>(istream &,multime<T2> &);
   virtual bool add(e_multime<T> x);
   e_multime<T> pop(int);
   multime<T> operator =(const multime<T> &);
   multime<T> operator +(const multime<T> &);
   multime<T> operator *(const multime<T> &);
   multime<T> operator -(const multime<T> &);
   multime< pereche<T> >prod(multime<T>);
   template<class T2>
   friend ostream& operator<<(ostream &,const multime<T2> &);
   ~multime();
};
template<class T>multime<T>::multime()
{
    dim=0;
}
template<class T>multime<T>::multime(int n)
{
    dim=n;
    v=new e_multime<T>[dim];
}
template<class T>multime<T>::~multime()
{
    if(dim)
    delete []v;
}
template<class T>multime<T>::multime(const multime<T> &B)
{
    dim=B.dim;
    v=new e_multime<T>[dim];
    for(int i=0;i<dim;i++)
        v[i]=B.v[i];

}
template<class T>
void multime<T>::redim(int n)
{
  multime<T> c=*this;
  if(dim)
  delete []v;
  dim=n;
  v=new e_multime<T>[n];
  for(int i=0;i<min(c.dim,n);i++)
    v[i]=c.v[i];
}
template<class T2>
istream& operator>>(istream &in,multime<T2> &A)
{
    int x; in>>x;
    A.redim(x);
    for(int i=0;i<x;i++)
        in>>A.v[i];
    return in;
}
template<class T2>
ostream& operator<<(ostream &out,const multime<T2> &A)
{
    out<<A.dim<<'\n';
    for(int i=0;i<A.dim;i++)
        out<<A.v[i]<<' ';
    return out;
}
template<class T>
multime<T> multime<T>::operator=(const multime<T> &B)
{
    redim(B.dim);
    for(int i=0;i<B.dim;i++)
        v[i]=B.v[i];
    return *this;
}
template<class T>
bool multime<T>::add(e_multime<T> x)
{
    bool ok=0;
    for(int i=0;i<dim;i++)
        if(x==v[i])
    {
        ok=1;
        break;
    }
    if(!ok)
    {redim(dim+1);
     v[dim-1]=x;
    }
    return ok;
}
template<class T>
multime<T> multime<T>::operator +(const multime<T> &B)
{
    multime C=*this;
    for(int i=0;i<B.dim;i++)
    {
        bool ok=1;
        for(int j=0;j<dim;j++)
        {
            if(v[j]==B.v[i])
            {
                ok=0;
                break;
            }
        }
        if(ok)
            C.add(B.v[i]);
    }
    return C;
}
template<class T>
multime<T> multime<T>::operator *(const multime<T> &B)
{
    multime C;
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<B.dim;j++)
            if(v[i]==B.v[j])
        {
            C.add(v[i]);
            break;
        }
    }
    return C;
}
template<class T>
multime<T> multime<T>::operator -(const multime<T> &B)
{
    multime C;
    for(int i=0;i<dim;i++)
    {
        int j=0;
        for(j=0;j<B.dim;j++)
            if(v[i]==B.v[j])
            break;
        if(j==B.dim)
            C.add(v[i]);
    }
    return C;

}
template<class T>
e_multime<T> multime<T>::pop(int k)
{
    for(int i=k;i<dim-1;i++)
        v[i]=v[i+1];
    e_multime<T> x=v[k];
    redim(dim-1);
    return x;
}
template<class T>
multime< pereche<T> > multime<T>::prod(multime<T> B)
{
    multime< pereche<T> > C;
    for(int i=0;i<dim;i++)
        for(int j=0;j<B.dim;j++)
    {
        pereche<T> x(v[i].get(),(B.v[j]).get());
        C.add(x);
    }
    return C;
}
