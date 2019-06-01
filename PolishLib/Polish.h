#ifndef __POLISH_H
#define __POLISH_H
#include <Exception.h>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<StackList.h>
#include<Stack.h>

using namespace std;

class TInfixToPolish {
protected:
  int GetOperationPrt(char op); // получить приоритет операции
  int IsOperation(char op); // проверка на знак операции
public:
  double Calculate(char* mem, int len);
  char* ConvertToPolish(char * exp, int len); // проебразование к польской записи
};
#endif