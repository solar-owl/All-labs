#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include "Exception.h"

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
  int IsEmpty(); // контроль пустоты
  int GetSize();// кол-во элементов в стеке
  bool IsFull(); // проверка на полноту
  bool IsEmpty(); // проверка на пустоту
  void Put(const int Val); // положить элемент
  T Get(); // получить элемент
  void Print();
};


#endif

