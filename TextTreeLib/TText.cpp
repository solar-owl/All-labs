#include "TText.h"

TText::TText(char * s)
{
  TTextLink::InitMemory(100);
  pFirst = new TTextLink(0);
  pCurrent = pFirst;
  if (s != NULL)
  {
    TTextLink* buff = new TTextLink(1);
    pCurrent = buff;
    pFirst->SetDown(buff);
    buff->SetDown(new TTextLink(s));
  }
}

void TText::GoNextLink()
{
  pCurrent = pCurrent->GetNext();
}

void TText::GoDownLink()
{
  pCurrent = pCurrent->GetDown();
}

TTextLink * TText::GetCurrent()
{
  return pCurrent;
}

int TText::Reset()
{
  while (!st.IsEmpty())
    st.Get();
  pCurrent = pFirst;
  st.Put(pCurrent);
  if (pCurrent->pNext != NULL)
    st.Put(pCurrent->pNext);
  if (pCurrent->pDown != NULL)
    st.Put(pCurrent->pDown);
  return IsEnded();
}

int TText::GoNext()
{
  if (!IsEnded())
  {
    pCurrent = st.Get();
    if (pCurrent != pFirst)
    {
      if (pCurrent->pNext != NULL)
        st.Put(pCurrent->pNext);
      if (pCurrent->pDown != NULL)
        st.Put(pCurrent->pDown);
    }
  }
  return IsEnded();
}

int TText::IsEnded()
{
  return !st.GetSize();
}

TTextLink * TText::GetLine()
{
  return pCurrent;
}

void TText::Print(TTextLink *pLink)
{
  if (pLink != NULL)
  {
    std::cout << *pLink;
    Print(pLink->GetDown());
    if (pLink->pNext != NULL)
    {
      switch (pLink->level)
      {
      case(1):
        std::cout << '\n';
        break;
      case(2):
        std::cout << ' ';
        break;
      }
      Print(pLink->GetNext());
    }
  }
}

void TText::Print()
{
  Print(pFirst);
}

void TText::InsertNext(char s)
{
  if (pCurrent->level != 3)
    return;
  TTextLink* res = new TTextLink(s);
  InsertNext(res);
}

void TText::InsertNext(char * s)
{
  TTextLink* res = new TTextLink(s);
  if (pCurrent->level == 2)
  {
    res->level = 2;
  }
  InsertNext(res);
}

void TText::InsertNext(TTextLink* s)
{
  if (pCurrent == NULL)
    throw TException(DataErr);
  TTextLink * pN = pCurrent->GetNext();
  pCurrent->SetNext(s);
  s->SetNext(pN);
}

void TText::InsertDown(char * s)
{
  if(pCurrent->level < 2)
  {
    TTextLink* res = new TTextLink(s);
    if (pCurrent->level == 2)
    {
      res->level = 2;
    }
    InsertDown(res);
  }
}

void TText::InsertDown(TTextLink * s)
{
  if (pCurrent == NULL)
    throw TException(DataErr);
  TTextLink * pN = pCurrent->GetDown();
  if (pN == NULL)
  {
    pCurrent->pDown = s;
  }
  else
  {
    while (pN->pNext != NULL)
    {
      pN = pN->pNext;
    }
    pN->pNext = s;
  }
}

void TText::DelNext()
{
  if(pCurrent == NULL)
    throw TException(DataErr);
  TTextLink * pN = pCurrent->GetNext();
  if (pN != NULL)
  {
    pCurrent->SetNext(pN->GetNext());
    delete pN;
  }
}

void TText::DelDown()
{
  if (pCurrent == NULL)
    throw TException(DataErr);
  TTextLink * pD = pCurrent->GetDown();
  if (pD != NULL)
  {
    pCurrent->SetDown(pD->GetNext());
    delete pD;
  }
}

