#include "TText.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
  TText txt;
  bool flag = true;
  int cmd = 0;
  std::cout << "Press Enter to Start";
  while (flag)
  {
    getchar();
    char buff[256];
    txt.Print();
    std::cout << endl;
    std::cout << "Current Level " << txt.GetCurrent()->GetLevel() << endl;
    std::cout << "Current link '" << (txt.GetCurrent())->ToStr() << "'"<< endl;
    std::cout << "0 - exit" << endl;
    std::cout << "1 - go down" << endl;
    std::cout << "2 - go next" << endl;
    std::cout << "3 - insert next" << endl;
    std::cout << "4 - insert down" << endl;
    std::cout << "5 - delete next" << endl;
    std::cout << "6 - delete down" << endl;
    std::cout << "7 - reset" << endl;
//   scanf_s("%d", &cmd);
    cin >> cmd;
    switch (cmd)
    {
    case 0:
      flag = false;
      break;
    case 1:
      txt.GoDownLink();
      break;
    case 2:
      txt.GoNextLink();
      break;
    case 3:
      std::cout << "Enter sentence" << endl;
      cin >> buff;
      txt.InsertNext(buff);
      break;
    case 4:
      std::cout << "Enter sentence" << endl;
      cin >> buff;
      txt.InsertDown(buff);
      break;
    case 5:
      txt.DelNext();
      break;
    case 6:
      txt.DelDown();
      break;
    case 7:
      txt.Reset();
      break;
    }
  }
}