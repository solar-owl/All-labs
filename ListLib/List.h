#pragma once 
#include "Elem.h"
#include "Exception.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:
  TElem<T>* begin;            //указатель на элемент в начале списка
  int count;                  //кол-во элементов в списке 
protected:
  void DelLink(TElem<T>* pLink); // удаление звена
public:
  TList();                    
  TList(TList<T> &L);         
  virtual ~TList();           
  int GetSize();              //получить кол-во элементов в листе
  void Put(int n, T elem);   //установть элемент на позицию n в списке
  T Get(int n);              //получить элемент из списка
  void PutBegin(T A);         //положить в начало 
  void PutEnd(T A);           //положить в конец 
  T GetBegin();               //получить элемент в начале списка 
  T GetEnd();                 //получить элемент в конце списка 
  bool IsFull();              //проверка на полноту 
  bool IsEmpty();             //проверка на пустоту 
  void Print();               //печать листа 
  void Del(int num); // произвольное звено
  void DelFirst(); // удалить первое звено 
};

template <class T>
TList<T>::TList()
{
  begin = 0;
  count = 0;
}

template<class T>
void TList<T>::DelLink(TElem<T>* pLink)
{
  if (pLink)
    delete pLink;
}

template <class T>
TList<T>::TList(TList<T> &L)
{
  count = L.count;
  TElem<T>* a = L.begin;
  TElem<T>* b;
  if (L.begin == 0)
    begin = 0;
  else
  {
    begin = new TElem<T>(*L.begin);
    b = begin;
    while (a->GetNext() != 0)
    {
      b->SetNext(new TElem<T>(*(a->GetNext())));
      a = a->GetNext();
      b = b->GetNext();
    }
  }
}

template <class T>
TList<T>::~TList()
{
  while (begin != 0)
  {
    TElem<T>* temp = begin;
    begin = begin->GetNext();
    delete temp;
  }
}

template<class T>
int TList<T>::GetSize()
{
  return count;
}

template<class T>
void TList<T>::Put(int n, T elem)
{
  if (this->IsFull())
    throw TException(DataFull);
  if (n < 1 || n > count - 1)
    throw TException(DataErr);
  else
  {
    int i = 0;
    TElem<T>* a = begin;
    while (i != n - 1)
    {
      a = a->GetNext();
      i++;
    }
    TElem<T>* temp = new TElem<T>(elem, a->GetNext());
    a->SetNext(temp);
    count++;
  }
}

template<class T>
T TList<T>::Get(int n)
{
  if (this->IsEmpty())
    throw TException(DataEmpty);
  if (n < 1 || n > count - 1)
    throw TException(DataErr);
  else
  {
    int i = 0;
    count--;
    TElem<T>* a = begin;
    TElem<T>* b = begin->GetNext();
    while (i != n - 1)
    {
      a = b;
      b = b->GetNext();
      i++;
    }
    T temp = b->GetData();
    a->SetNext(b->GetNext());
    delete b;
    return temp;
  }
}

template <class T>
void TList<T>::PutBegin(T A)
{
  if (this->IsFull())
    throw TException(DataFull);
  if (begin == 0)
  {
    TElem<T>* temp = new TElem<T>(A, 0);
    begin = temp;
  }
  else
  {
    TElem<T>* temp = new TElem <T>(A, begin);
    begin = temp;
  }
  count++;
}

template <class T>
void TList<T>::PutEnd(T A)
{
  if (this->IsFull())
    throw TException(DataFull);
  if (begin != 0)
  {
    TElem<T>* a = begin;
    while (a->GetNext() != 0)
      a = a->GetNext();
    a->SetNext(new TElem <T>(A, 0));
  }
  else
    begin = new TElem<T>(A, 0);
  count++;
}

template <class T>
T TList<T>::GetBegin()
{
  if (IsEmpty())
    throw TException(DataEmpty);
  else
  {
    TElem<T>* a = begin;
    T temp = begin->TElem<T>::GetData();
    begin = begin->TElem<T>::GetNext();
    delete a;
    count--;
    return temp;
  }
}

template <class T>
T TList<T>::GetEnd()
{
  if (IsEmpty())
    throw TException(DataEmpty);
  else
  {
    count--;
    TElem<T>* a = begin;
    TElem<T>* b = begin->GetNext();
    if (b == 0)
    {
      T temp = a->TElem<T>::GetData();
      delete a;
      begin = 0;
      return temp;
    }
    else
    {
      while (b->GetNext() != 0)
      {
        a = b;
        b = b->GetNext();
      }
      T temp = b->GetData();
      delete b;
      a->SetNext(0);
      return temp;
    }
  }
}

template <class T>
bool TList<T>::IsFull()
{
  try
  {
    TElem<T>* a = new TElem<T>();
    if (a == NULL)
      return 1;
    else
    {
      delete a;
      return 0;
    }
  }
  catch (...)
  {
    return 0;
  }
  return true;
}

template <class T>
bool TList<T>::IsEmpty()
{
  if (begin == 0)
    return 1;
  return 0;
}

template<class T>
inline void TList<T>::Print()
{
  if (begin == 0)
    throw TException(DataEmpty);
  else
  {
    TElem<T>* a = begin;
    while (a->GetNext() != 0)
    {
      cout << a->GetData() << " ";
      a = a->GetNext();
    }
    cout << a->GetData() << " ";
  }

}

template<class T>
void TList<T>::DelFirst()
{
  if (count)
  {
    Elem<T>* tmp = begin;
    begin = begin->GetDate();
    DelLink(tmp);
    count--;
  }
}

template<class T>
void TList<T>::Del(int num)
{
  if ((num < 0) || (num >(count - 1)))
    throw TException(DataErr);
  if (num == 0)
    DelFirst();
  else
  {
    Elem<T>* pTemp = begin;
    Elem<T>* pTempPrev;
    for (int i = 0; i < (num - 1); i++)
    {
      pTempPrev = pTemp;
      pTemp = pTemp->GetNext();
    }
    pTempPrev->SetNext(pTemp->GetNext());
    DelLink(pTemp);
  }
  count--;
}