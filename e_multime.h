#pragma once
#include<istream>
#include<ostream>
using namespace std;
template <class T>
class e_multime
{  protected:
   T x;
   public:
  e_multime(T);
  e_multime();
  template<class T2>
  friend istream& operator>>(istream &,e_multime<T2> &);
  T get(){return x;}
  template<class T2>
  friend ostream& operator<<(ostream &,const e_multime<T2> &);
  bool operator ==(const e_multime<T> &B);
};
template <class T>e_multime<T>::e_multime(T a)
{
    x=a;
}
template <class T>e_multime<T>::e_multime(){};
template<class T2>
istream& operator>>(istream &in,e_multime<T2> &A)
{
    in>>A.x;
    return in;
}
template<class T2>
ostream& operator<<(ostream &out,const e_multime<T2> &A)
{
    out<<A.x;
    return out;
}
template <class T3>
bool e_multime<T3>::operator ==(const e_multime<T3> &B)
{
    return(x==B.x);
}
