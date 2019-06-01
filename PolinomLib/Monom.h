#include "Exception.h"
#include <iostream>

using namespace std;

class TMonom
{
protected:
  TMonom* next;  //��������� �� ��������� �����
  int *power;    //������ ��������
  double coeff;  //�����������
  int n;         //���-�� ���������� � ������
public:
  TMonom();
  TMonom(int _n, int* _power, double _c);
  TMonom(const TMonom& A);
  virtual ~TMonom();

  TMonom* GetNext();
  int* GetPower();
  double GetC();
  int GetN();

  void SetNext(TMonom* _next);
  void SetPower(int* _power);
  void SetC(double _c);
  void SetN(int _n);

  TMonom& operator=(const TMonom& A);
  TMonom operator+(TMonom& A);
  TMonom operator+=(TMonom& A);
  TMonom operator*(const TMonom& A) const;
  TMonom operator*=(TMonom& A);
  TMonom operator-(TMonom& A);
  TMonom operator-=(TMonom& A);
  bool operator==(TMonom& A);
  bool operator>(TMonom& A);
  bool operator<(TMonom& A);

  friend istream& operator>>(istream& istr, TMonom& A);
  friend ostream& operator<<(ostream& ostr, TMonom& A);
};