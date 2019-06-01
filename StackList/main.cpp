#include "StackList.h"
#include <iostream>

int main()
{
  setlocale(LC_ALL, "Russian");

  cout << "������� ������ �����: ";
  int lenght;
  cin >> lenght;

    TStackList<int> s(lenght);

    for (int i = 0; i < lenght; i++)
    {
      s.Put(i);
    }

    if (s.IsFull())
    {
      cout << "\n���� ��������� ���� ������: \n";
      s.Print();
      cout << "\n���� �����.\n";
    }

    cout << "\n������ ������� � �����: " << s.Get() << endl;
    cout << "������ ��� ����:\n";
    s.Print();
    cout << "\n��� ������� ����� = " << s.GetSize() << "\n������������ ����� = " << s.GetMaxSize() << endl;

    cout << "\n���������� ����:\n";
    int j = 1;

    while (!s.IsEmpty())
      cout << "������� ��� ������� " << j++ << " : " << s.Get() << endl;
    cout << "���� ����.\n";
  
  return 0;
}