#ifndef __TEXTTREE_H
#define __TEXTTREE_H
#include <Exception.h>
#include <StackList.h>
#include <iostream>
#include <string.h>

class TTextLink;
class TText;
using namespace std;


class TTextMem
{
public:
  TTextLink* pFirst; // первое звено
  TTextLink* pLast; // последнее звено
  TTextLink* pFree; // первое свободное
  friend class TTextLink;
};


class TTextLink
{
  protected:
    TTextLink* pDown; // следующий уровень
    TTextLink* pNext; // соседи
    char d; // буква, только на нижнем уровне
    int level;//уровень, 0 -текст, 1 -строка 2 - слово, 3 - буква
    static TTextMem mem;
  public:
    TTextLink(char* st = 0);
    TTextLink(int l);
    TTextLink(char _d = 0);
    TTextLink(const TTextLink& a);
    ~TTextLink();
    static void InitMemory(int size);
    static void MemCleaner(TText &txt);
    void * operator new(const size_t size);
    void operator delete(void* pM);
    TTextLink& operator=(const TTextLink& a);
    TTextLink& operator+=(TTextLink& a);
    TTextLink& operator+=(char c);
    TTextLink& operator+=(char* c);
    friend ostream & operator<<(ostream& o, const TTextLink& a);
    char* ToStr();
    void SetDown(TTextLink* p);
    void SetNext(TTextLink* p);
    void SetD(char _d);
    void SetLevel(int _level);
    TTextLink* GetDown();
    TTextLink* GetNext();
    char GetD();
    int GetLevel();
    TTextLink* Clone();
    friend class TText;
  };
#endif