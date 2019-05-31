#include "TTextLink.h"
#include "TText.h"

TTextMem TTextLink::mem;

TTextLink::TTextLink(char * st)
{
  level = 1;
  pNext = NULL;
  pDown = NULL;
  d = 0;
  if (st != NULL)
  {
    int l = strlen(st);
    pDown = new TTextLink(2);
    TTextLink* pWord = pDown;
    pWord->pDown = new TTextLink(st[0]);
    TTextLink*buff = pWord->pDown;
    for (int i = 1; i < l; i++)
    {
      if (st[i] == ' ')
      {
        pWord->pNext = new TTextLink(2);
        pWord = pWord->pNext;
        i++;
        pWord->pDown = new TTextLink(st[i]);
        buff = pWord->pDown;
      }
      else
      {
        buff->pNext = new TTextLink(st[i]);
        buff = buff->pNext;
      }
    }
  }
}

TTextLink::TTextLink(int l)
{
  pDown = NULL;
  pNext = NULL;
  level = l;
  d = 0;
}

TTextLink::TTextLink(char _d)
{
  level = 3;
  d = _d;
  pNext = NULL;
  pDown = NULL;
}

TTextLink::TTextLink(const TTextLink & a)
{
  level = a.level;
  d = a.d;
  pDown = a.pDown;
  pNext = a.pNext;
}

TTextLink::~TTextLink()
{
}


void TTextLink::InitMemory(int size)
{
  mem.pFirst = (TTextLink*) new char[sizeof(TTextLink) * size];
  TTextLink::mem.pFree = TTextLink::mem.pFirst;
  TTextLink::mem.pLast = TTextLink::mem.pFirst + size - 1;
  TTextLink* buff = mem.pFirst;
  for (int i = 0; i < size - 1; i++, buff++)
  {
    buff->pNext = buff + 1;
    buff->level = 0;
  }
  buff->pNext = NULL;
}

void TTextLink::MemCleaner(TText &txt)
{
  for (txt.Reset(); !txt.IsEnded(); txt.GoNext())
    txt.GetLine()->level -=4;
  TTextLink* pLink = mem.pFree;
  for (; pLink != NULL; pLink = pLink->pNext)
    pLink->level -= 4;
  pLink = mem.pFirst;
  for (; pLink <= mem.pLast; pLink++)
    if (pLink->level < 0)
      pLink->level += 4;
    else
      delete pLink;
}

void * TTextLink::operator new(const size_t size)
{
  if (mem.pFree == NULL)
    throw TException(DataNoMem);
  TTextLink* res = mem.pFree;
  mem.pFree = res->pNext;
  return res;
}

void TTextLink::operator delete(void * pM)
{
  TTextLink* buff = mem.pFree;
  mem.pFree = (TTextLink*)pM;
  mem.pFree->pNext = buff;
}

TTextLink & TTextLink::operator=(const TTextLink & a)
{
  if (level != a.level)
    throw TException(DataErr);

  if (&a != this)
  {
    d = a.d;
    pDown = a.pDown;
    pNext = a.pNext;
  }

  return *this;
}

TTextLink & TTextLink::operator+=(TTextLink & a)
{
  TTextLink* copy = a.Clone();
  TTextLink* i = this;
  while (i->level != copy->level)
    i = i->pDown;
  while (i->pNext != 0)
    i = i->pNext;
  i->pNext = copy;
  return *this;
}

TTextLink & TTextLink::operator+=(char c)
{
  TTextLink symb(c);
  return (*this += symb);
}

TTextLink & TTextLink::operator+=(char * c)
{
  TTextLink symb(c);
  return (*this += symb);
}

char * TTextLink::ToStr()
{
  TStackList <TTextLink*> t;
  t.Put(this);
  int l = 0;
  while (!t.IsEmpty())
  {
    TTextLink* i = t.Get(); 
    if (i->level == 3)
      l++;
    if (i->pNext != 0)
      t.Put(i->pNext);
    if (i->pDown != 0)
      t.Put(i->pDown);
  }
  t.Put(this);
  char *res = new char[l + 1];
  int j = 0;

  while (!t.IsEmpty())
  {
    TTextLink* i = t.Get();
    if (i->level == 3)
    {
      res[j] = i->d;
      j++;
    }
    if (i->pNext != 0)
      t.Put(i->pNext);
    if (i->pDown != 0)
      t.Put(i->pDown);
  }
  res[l] = 0;
  return res;
}

void TTextLink::SetDown(TTextLink * p)
{
    pDown = p;
}

void TTextLink::SetNext(TTextLink * p)
{
  pNext = p;
}

void TTextLink::SetD(char _d)
{
  d = _d;
}

void TTextLink::SetLevel(int _level)
{
  level = _level;
}

TTextLink * TTextLink::GetDown()
{
  return pDown;
}

TTextLink * TTextLink::GetNext()
{
  return pNext;
}

char TTextLink::GetD()
{
  return d;
}

int TTextLink::GetLevel()
{
  return level;
}

TTextLink * TTextLink::Clone()
{
  TTextLink* resTree = new TTextLink(*this);
  TStackList<TTextLink*> st;
  TStackList<TTextLink*> copy;
  st.Put(this);
  copy.Put(resTree);
  while (!st.IsEmpty())
  {
    TTextLink* t1 = st.Get();
    TTextLink* c1 = copy.Get();
    if (t1->pDown != 0)
    {
      c1->pDown = new TTextLink(*t1->pDown);
      copy.Put(c1->pDown);
      st.Put(t1->pDown);
    }
    if (t1->pNext != 0)
    {
      c1->pNext = new TTextLink(*t1->pNext);
      copy.Put(c1->pNext);
      st.Put(t1->pNext);
    }
  }
  return resTree;
}

ostream & operator<<(ostream & o, const TTextLink & a)
{
  if (a.d != 0)
    o << a.d;
  return o;
}
