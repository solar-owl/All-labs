#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#define DataErr -1
#define DataEmpty -101 // �� �����
#define DataFull -102 // �� �����������
#define DataNoMem -103 // ��� ������

class TException {
protected:
  int RetCode; // ��� ����������
public:
  TException(int ex);
};

#endif