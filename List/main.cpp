#include "List.h"
#include <iostream>
#include "Exception.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    TList<int> list;
    cout << "\n������� ����� ��������, ������� ����� ��������� � ������ ������ ";
    int start, end;
    cin >> start;
    for (int i = 1; i <= start; i++)
      list.PutBegin(i);
    cout << "\n������� ����� ��������, ������� ����� ��������� � ����� ������ ";
    cin >> end;
    for (int i = 1; i <= end; i++)
      list.PutEnd(i);

    cout << "\n\n������� ������\n";
    list.Print();

    cout << "\n\n������� � ������ ������ " << list.GetBegin();
    cout << "\n������� � ����� ������  " << list.GetEnd();

    cout << "\n\n������\n";
    list.Print();


  return 0;
}