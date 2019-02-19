#pragma once
#include "TVector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &mt); // копирование 
  TMatrix(const TVector<TVector<T> > &mt); // преобразование типа 
  bool operator==(const TMatrix &mt); // сравнение 
  bool operator!=(const TMatrix &mt); // сравнение 
  TMatrix & operator= (const TMatrix &mt); // присваивание 
  TMatrix operator+ (const TMatrix &mt); // сложение 
  TMatrix operator- (const TMatrix &mt); // вычитание 
  TMatrix operator* (const TMatrix &mt); // умножение 
  // ввод / вывод
  friend istream & operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.size; i++)
      in >> mt.pVector[i];
    return in;
  }

  friend ostream & operator<<(ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};


template<class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T> >(s)
{
  if (s <= 0)  throw - 1;
  for (int i = 0; i < s; i++)
    this->pVector[i] = TVector<T>(s - i, i);
}

template<class T>//конструктор копирования
TMatrix<T>::TMatrix(const TMatrix & mt) : TVector<TVector<T> >(mt)
{
  for (int i = 0; i < this->Size; i++)
    this->pVector[i] = TVector<T>(mt.pVector[i]);;
}

template<class T>//конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> >& mt) : TVector<TVector<T> >(mt)
{
}

template<class T>//сравнение
bool TMatrix<T>::operator==(const TMatrix<T> & mt)
{
  return TVector<TVector<T> >::operator==(mt);
}

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) 
{
  return !(*this == mt);
}

template<class T>//присваивание
TMatrix<T> & TMatrix<T>::operator=(const TMatrix & mt)
{
  if (this != &mt)
  {
    this->Size = mt.Size;
    delete[] this->pVector;
    this->pVector = new TVector<T>[this->Size];
    for (int i = 0; i < this->Size; i++)
      this->pVector[i] = mt.pVector[i];
  }
  return *this;
}
template<class T> //сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix & mt)
{
  if (this->Size != mt.Size)
    throw -1;
  TMatrix tmp(this->Size);
  for (int i = 0; i < this->Size; i++)
    tmp.pVector[i] = this->pVector[i] + mt.pVector[i];
  return tmp;
}

template<class T>//вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix & mt)
{
  if (this->Size != mt.Size)
    throw -1;
  TMatrix tmp(this->Size);
  for (int i = 0; i < this->Size; i++)
    tmp.pVector[i] = this->pVector[i] - mt.pVector[i];
  return tmp;
}

template<class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix & mt)
{
  if (this->Size != mt.Size)
    throw -1;
  TMatrix tmp(this->Size);
  for (int i = 0; i < this->Size; i++)
    for (int j = i; j < this->Size; j++)
      for (int k = i; k < j + 1; k++)
        tmp.pVector[i][j] += this->pVector[i][k] * mt.pVector[k][j];
  return tmp;
}
