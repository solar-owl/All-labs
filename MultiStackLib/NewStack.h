#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
class TNewStack : public TStack<T>
{
public:
  TNewStack(int _size, T* _Elem);
  TNewStack(TNewStack<T>& A);
  int GetFreeMem();
  T Get();
  void Push(T _A);
  int GetSize();
  int GetTop();
  void SetMas(int _size, T* _Elem);
  void PrintNewStack();
};

template <class T>
TNewStack<T>::TNewStack(int _size, T* _Elem)
{
  if (_size <= 0)
    throw TException(DataErr);
  TStack<T>::top = 0;
  TStack<T>::size = _size;
  TStack<T>::Elem = _Elem;
}

template <class T>
TNewStack<T>::TNewStack(TNewStack<T>& A)
{
  TStack<T>::top = A.top;
  TStack<T>::size = A.size;
  TStack<T>::Elem = A.Elem;
}

template <class T>
int TNewStack<T>::GetFreeMem()
{
  return TStack<T>::size - TStack<T>::top;
}

template <class T>
void TNewStack<T>::SetMas(int _size, T* _Elem)
{
  if (_size <= 0)
    throw TException(DataErr);
  TStack<T>::size = _size;
  TStack<T>::Elem = _Elem;
}

template <class T>
int TNewStack<T>::GetTop()
{
  return TStack<T>::top;
}

template <class T>
int TNewStack<T>::GetSize()
{
  return TStack<T>::size;
}

template <class T>
void TNewStack<T>::Push(T _A)
{
  TStack<T>::Elem[TStack<T>::top] = _A;
  TStack<T>::top++;
}

template <class T>
T TNewStack<T>::Get()
{
  TStack<T>::top--;
  return TStack<T>::Elem[TStack<T>::top];
}

template <class T>
void TNewStack<T>::PrintNewStack()
{
  for (int i = 0; i < TStack<T>::top; i++)
    cout << " " << TStack<T>::Elem[i];
}