#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include "Exception.h"

using namespace std;

template <class T>
class TStack
{
protected: 
  T * Elem; // элементы стека
  int top; // вершина стека 
  int size;//размер стека
public:
  TStack(int S = 10);
  TStack(TStack<T>&m);
  ~TStack();

  int GetSize();// кол-во элементов в стеке
  bool IsFull(); // проверка на полноту
  bool IsEmpty(); // проверка на пустоту
  void Put(const int el); // добавить значение
  T Get(); // получить элемент
  T Top();
};

template<class T>
TStack<T>::TStack(int S)
{
  if (S < 0)
    throw TException(DataErr);
  else if (S == 0)
  {
    size = 0;
    top = -1;
    Elem = NULL;
  }
  else
  {
    size = S;
    top = -1;
    Elem = new T[S];
    for (int i = 0; i < size; i++)
      Elem[i] = 0;
  }
}

template <class T>
TStack<T>::TStack(TStack<T>&m)
{
  size = m.size;
  top = m.top;
  if (size == 0)
    Elem = NULL;
  else
  {
    Elem = new T[size];
    for (int i = 0; i < size; i++)
      Elem[i] = m.Elem[i];
  }
}

template<class T>
TStack<T>::~TStack()
{
  if (Elem != NULL)
    delete[]Elem;
  top = 0;
  size = 0;
  Elem = NULL;
}

template<class T>
int TStack<T>::GetSize()
{
  return size;
}

template<class T>
bool TStack<T>::IsFull()
{
  if (top >= size-1)
    return 1;
  return 0;
}

template<class T>
bool TStack<T>::IsEmpty()
{
  if (top == -1)
    return 1;
  return 0;
}

template<class T>
void TStack<T>::Put(const int el)
{
  if (IsFull())
    throw TException(DataFull);
  Elem[++top] = el;
}


template<class T>
T TStack<T>::Get()
{
  if (IsEmpty())
    throw TException(DataEmpty);
  return Elem[top--];
}

template<class T>
T TStack<T>::Top()
{
  if (IsEmpty())
    throw "Empty";
  else
  {
    return Elem[top - 1];
  }
}

#endif

 