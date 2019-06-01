#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>
#include "Exception.h"

using namespace std;


template <class T>
class TVector
{
protected:
  T * pVector;
  int Size; // ������ �������
  int StartIndex; // ������ ������� �������� �������
public:
  TVector();
  TVector(int s, int si = 0);
  TVector(const TVector &v); // ����������� �����������
  ~TVector();
  int GetSize() { return Size; } // ������ �������
  int GetStartIndex() { return StartIndex; } // ������ ������� ��������

  T & operator[] (int pos); // ������
  bool operator==(const TVector &v); // ���������
  bool operator!=(const TVector &v); // ���������
  TVector & operator= (const TVector &v); // ������������
  // ��������� ��������
  TVector operator+ (const T &val); // ��������� ������
  TVector operator- (const T &val);// ������� ������
  TVector operator* (const T &val);// �������� �� ������
  //��������� ��������
  TVector operator+ (const TVector &v); // ��������
  TVector operator- (const TVector &v); // ���������
  T operator* (const TVector &v); // ��������� ������������
  //����-����� 
  friend istream & operator>>(istream &in, TVector<T> &v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream & operator<<(ostream &out,  TVector<T> &v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template<class T>
TVector<T>::TVector()
{
  pVector = NULL;
  Size = 0;
  StartIndex = 0;
}

template<class T>
TVector<T>::TVector(int s, int si)
{
  if ((s < 0) || (si < 0)) throw - 1;
  Size = s;
  pVector = new T[Size];
  for (int i = 0; i < Size; i++)
    pVector[i] = 0;
  StartIndex = si;
}

template<class T> //����������� �����������
TVector<T>::TVector(const TVector & v)
{
  Size = v.Size;
  StartIndex = v.StartIndex;
  pVector = new T[Size];
  for (int i = 0; i < Size; i++)
    pVector[i] = v.pVector[i];
}


template<class T>
TVector<T>::~TVector()
{
  delete[]pVector;
}


template<class T>//������
T & TVector<T>::operator[](int pos)
{
  if ((pos - StartIndex < 0) || (pos - StartIndex > Size)) throw - 1;
  return pVector[pos - StartIndex];
}

template<class T>//���������
bool TVector<T>::operator==(const TVector & v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex)) return false;
  for (int i = 0; i < Size; i++)
    if (pVector[i] != v.pVector[i]) return false;
  return true;
}

template <class T> // ���������
bool TVector<T>::operator!=(const TVector &v) 
{
  return !(*this == v);
}

template<class T> //������������
TVector<T> & TVector<T>::operator=(const TVector &v)
{
  if (this != &v)
  {
    delete[] pVector;
    Size = v.Size;
    StartIndex = v.StartIndex;
    pVector = new T[Size];
    for (int i = 0; i < Size; i++)
    {
      pVector[i] = v.pVector[i];
    }
  }
  return *this;
}

template<class T> //��������� ������
TVector<T> TVector<T>::operator+(const T & val)
{
  TVector<T> tmp(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] += val;
  return tmp;
}
template<class T>//������� ������
TVector<T> TVector<T>::operator-(const T & val)
{
  TVector<T> tmp(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] -= val;
  return tmp;
}

template <class T> // �������� �� ������
TVector<T> TVector<T>::operator*(const T &val)
{
  TVector<T> tmp(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] *= val;
  return tmp;
}

template<class T>//��������
TVector<T> TVector<T>::operator+(const TVector & v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex)) throw - 1;
  TVector<T> tmp(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] += v.pVector[i];
  return tmp;
}
template<class T>//���������
TVector<T> TVector<T>::operator-(const TVector & v)
{
  if((Size != v.Size) || (StartIndex != v.StartIndex)) throw - 1;
  TVector<T> tmp(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] -= v.pVector[i];
  return tmp;
}

template<class T> //��������� ������������
T TVector<T>::operator*(const TVector & v)
{
  T tmp = 0;
  if (Size != v.Size) throw - 1;
  for (int i = 0; i < Size; i++)
    tmp += pVector[i] * v.pVector[i];
  return tmp;
}
#endif