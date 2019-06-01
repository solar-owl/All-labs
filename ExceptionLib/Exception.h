#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#define DataErr -1
#define DataEmpty -101 // СД пуста
#define DataFull -102 // СД переполнена
#define DataNoMem -103 // нет памяти

class TException {
protected:
  int RetCode; // Код завершения
public:
  TException(int ex);
};

#endif