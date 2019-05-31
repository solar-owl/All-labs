#include <iostream>
#include "Stack.h"
#include "Exception.h"

using namespace std;

int  main() {
  TStack<int> St(2);
  if (St.IsEmpty())
  {
    St.Put(5);
    St.Put(6);
  }
  if (St.IsFull())
  {
    cout << "2:" << St.Get() << endl;
    cout << "1:" << St.Get() << endl;
  }

  return 0;
}