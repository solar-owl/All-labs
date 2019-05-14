#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#define DataErr -1
#define DataEmpty -101 // СД пуста
#define DataFull -102 // СД переполнена
#define DataNoMem -103 // нет памяти

template <class T>
class TException {
protected:
  int RetCode; // Код завершения
public:
  TException(int ex);
};

template <class T>
TException<T>::TException(int ex)
{
  RetCode = ex;
}
#endif