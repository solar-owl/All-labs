#ifndef __EXEPTION_H
#define __EXEPTION_H

#define DataErr -1
#define DataEmpty -101 // СД пуста
#define DataFull -102 // СД переполнена
#define DataNoMem -103 // нет памяти

template <class T>
class TExeption {
protected:
  int RetCode; // Код завершения
public:
  TExeption(int ex);
};

template <class T>
TExeption<T>::TExeption(int ex)
{
  RetCode = ex;
}
#endif