#include <iostream>
#include"Queue.h"
using namespace std;

int main()
{
  TQueue<int> Que(2);
  if (Que.IsEmpty())
  {
    Que.Put(1);
    Que.Put(2);
  }
  if (Que.IsFull())
  {
    cout << "1:" << Que.Get() << endl;
    cout << "2:" << Que.Get() << endl;
  }

  return 0;
}