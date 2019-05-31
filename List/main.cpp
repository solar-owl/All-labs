#include "List.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    TList<int> list;
    cout << "\nВВедите номер элемента, который нужно поместить в начало списка ";
    int start, end;
    cin >> start;
    for (int i = 1; i <= start; i++)
      list.PutBegin(i);
    cout << "\nВведите номер элемента, который нужно поместить в конец списка ";
    cin >> end;
    for (int i = 1; i <= end; i++)
      list.PutEnd(i);

    cout << "\n\nСоздать список\n";
    list.Print();

    cout << "\n\nЭлемент в начале списка " << list.GetBegin();
    cout << "\nЭлемент в конце списка  " << list.GetEnd();

    cout << "\n\nСписок\n";
    list.Print();


  return 0;
}