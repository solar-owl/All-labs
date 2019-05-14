#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
class TQueue : public TStack <T> { // Очередь - наследник стека
protected:
  int start; // начало очереди
  int count; // кол-во элементов
public:
  TQueue(int n = 0);
  TQueue(TQueue <T> &Q);

  void Put(T el); //положить в конец
  T Get(); //взять первый элемент
  bool IsFull(); //проверка на полноту
  bool IsEmpty(); //проверка на пустоту
};

template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n)
{
      start = 0;
      count = 0;
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &Q) : TStack<T>(Q) {
  start = Q.start;
  count = Q.count;
}

template <class T>
void TQueue<T>::Put(T el) {
  if (IsFull())
    throw Exception(DataFull);
  else {
    TStack<T>::Elem[start] = el;
    start = (start + 1) % TStack<T>::size;
    count++;
  }
}

template <class T>
T TQueue<T>::Get() {
  if (IsEmpty())
    throw Exception(DataEmpty);
  else {
    T tmp = TStack<T>::Elem[TStack<T>::top];
    TStack<T>::top = (TStack<T>::top + 1) % TStack<T>::size;
    count--;

    return tmp;
  }
}

template <class T>
bool TQueue<T>::IsFull() {
  if (count == TStack<T>::size)
    return 1;
  return 0;
}

template <class T>
bool TQueue<T>::IsEmpty() {
  if (count == 0)
    return 1;
  return 0;
}