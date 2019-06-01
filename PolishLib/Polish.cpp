#include "Polish.h"
#include <Exception.h>

int TInfixToPolish::GetOperationPrt(char op)
{
  switch (op) {
  case '*': return 3;
  case '/': return 3;
  case '+': return 2;
  case '-': return 2;
  case '(': return 1;
  case '=': return 0;
  default: return-1;
  }
}

int TInfixToPolish::IsOperation(char op)
{
  if (op == ')' || op == '(' || op == '+' || op == '-' || op == '*' || op == '/' || op == '=')
    return 1;
  return 0;
}

double TInfixToPolish::Calculate(char* mem, int len)
{
  TStack<int> st;
  int res;
  int i = 0;
  int j;
  while (mem[i] != '=')
  {
    if (!IsOperation(mem[i]))
    {
      j = 0;
      char* buff = new char[len];
      while (mem[i] != ' ')
        buff[j++] = mem[i++];
      buff[j] = '\n';
      st.Put(atoi(buff));
      delete[] buff;
    }
    else
    {
      double x, y;
      y = st.Get();
      x = st.Get();
      double z;
      switch (mem[i])
      {
      case '*': z = x * y;
        break;
      case '/': z = x / y;
        break;
      case '+': z = x + y;
        break;
      case '-': z = x - y;
        break;
      default: throw(TException(DataErr));
      }
      st.Put(z);
    }
    i++;
  }
  res = st.Get();
  return res;
}

char* TInfixToPolish::ConvertToPolish(char * exp, int len)
{
  TStackList<char> operation, polish;
  int i = 0;
  char t;
  while (i < len)
  {
    if (!IsOperation(exp[i]))
    {
      while (!IsOperation(exp[i]))
      {
        polish.Put(exp[i++]);
      }
      i--;
      polish.Put(' ');
    }
    else if (exp[i] == '(')
      operation.Put('(');
    else if (exp[i] == ')')
    {
      while (1)
      {
        char k = operation.Get();
        if (k == '(')
          break;
        polish.Put(k);
      }
    }
    else
    {
      while (!operation.IsEmpty())
      {
        t = operation.Get();
        if (GetOperationPrt(exp[i]) <= GetOperationPrt(t))
          polish.Put(t);
        else
        {
          operation.Put(t);
          break;
        }
      }
      operation.Put(exp[i]);
    }
    if (exp[i] == '=')
      break;
    i++;
  }
  int pos = polish.GetSize() + operation.GetSize();
  char * mem = new char[pos + 1];
  mem[pos] = '\0';
  mem[--pos] = '=';
  while (!polish.IsEmpty())
    mem[--pos] = polish.Get();
  return mem;
}
