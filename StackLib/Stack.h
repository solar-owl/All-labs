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
  TStack(int S = 0);
  TStack(TStack<T>&m);
  ~TStack();

  int GetSize();// кол-во элементов в стеке
  bool IsFull(); // проверка на полноту
  bool IsEmpty(); // проверка на пустоту
  void Put(const int Val); // добавить значение
                  //void Put(T el); // положить элемент
  T Get(); // получить элемент
};

template<class T>
TStack<T>::TStack(int S)
{
  if (S < 0)
    throw TExсeption(DataErr);
  else if (S == 0)
  {
    size = 0;
    top = 0;
    Elem = NULL;
  }
  else
  {
    size = S;
    top = 0;
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
  if (top >= size)
    return 1;
  return 0;
}

template<class T>
bool TStack<T>::IsEmpty()
{
  if (top == 0)
    return 1;
  return 0;
}

/*template<class T>
void TStack<T>::Put(T el)
{
  if (IsFull())
    throw TException(DataFull);
  else
  {
    Elem[++top] = el;
  }
}*/
template<class ValType>
void TStack<ValType>::Put(const int Val)
{
  if (IsFull())
    throw TExeption(DataFull);
  Elem[++top] = Val;
}

template<class T>
T TStack<T>::Get()
{
  if (IsEmpty())
    throw TException(DataEmpty);
  else
  {
    return Elem[top--];
  }
}

#endif

 