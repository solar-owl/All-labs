#include "StackList.h"
#include <iostream>

int main()
{
  setlocale(LC_ALL, "Russian");

  cout << "Введите размер стека: ";
  int lenght;
  cin >> lenght;

    TStackList<int> s(lenght);

    for (int i = 0; i < lenght; i++)
    {
      s.Put(i);
    }

    if (s.IsFull())
    {
      cout << "\nСтек выбранной вами длинны: \n";
      s.Print();
      cout << "\nСтек полон.\n";
    }

    cout << "\nПервый элемент в стеке: " << s.Get() << endl;
    cout << "Теперь это стек:\n";
    s.Print();
    cout << "\nЕго текущая длина = " << s.GetSize() << "\nМаксимальная длина = " << s.GetMaxSize() << endl;

    cout << "\nОставшийся стек:\n";
    int j = 1;

    while (!s.IsEmpty())
      cout << "Элемент под номером " << j++ << " : " << s.Get() << endl;
    cout << "Стек пуст.\n";
  
  return 0;
}