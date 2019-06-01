#include "ArrList.h"
#include <iostream>
#include "Exception.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  cout << "An example of using the ArrList will be implemented here" << endl;
  cout << "Enter size list: ";
  int n;
  cin >> n;
  cout << endl;
 
    TArrList<int> AList(n);
    int i;
    for (i = 1; i <= n / 2; i++)
    {
      cout << "Put start: " << i << endl;
      AList.PutStart(i);
    }
    for (i; i <= n; i++)
    {
      cout << "Put end: " << i << endl;
      AList.PutEnd(i);
    }

    cout << "\n\nList create" << endl;
    AList.Print();
    cout << "\n\n";


    for (i = 1; i <= n / 2; i++)
      cout << "Get start: " << AList.GetStart() << endl;
    for (i; i <= n; i++)
      cout << "Get end: " << AList.GetEnd() << endl;

  return 0;
}