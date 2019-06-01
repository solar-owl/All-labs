#ifndef __TLISTHASH_H__
#define __TLISTHASH_H__

#include <iostream>
#include <TTabRecord.h>
#include <Exception.h>
#include <TScanTable.h>
#include <List.h>

using namespace std;


template<class ValType>
class TListHash
{
private:
  int dataCount;
  int tabSize;
  TList<TTabRecord<ValType>*>** pList;
  unsigned long HashFunc(TKey k);
  int currPos;
public:
  TListHash(int size = 3);
  ~TListHash();
  void Add(TTabRecord<ValType> *tr);
  void Delete(TKey k);
  TTabRecord<ValType>* Search(TKey k);
  ValType* operator[] (TKey k);
  friend ostream& operator<<(ostream &os, const TListHash &q)
  {
    if (q.dataCount == 0)
      return os;
    for (int i = 0; i < q.dataCount - 1; i++)
    {
      os << "Key :" << q.pRecs[i]->GetKey();
      os << " val :" << *q.pRecs[i]->GetVal();
      os << endl;
    }
    os << "Key :" << q.pRecs[q.dataCount - 1]->GetKey();
    os << " val :" << *q.pRecs[q.dataCount - 1]->GetVal();
    return os;
  }
};
#endif

template<class ValType>
unsigned long TListHash<ValType>::HashFunc(TKey k)
{
  unsigned  long hashval = 0;
  int len = k.GetLen();
  for (int i = 0; i < len; i++)
    hashval = (hashval << 3) + k[i];
  return hashval;
}

template<class ValType>
TListHash<ValType>::TListHash(int size)
{
  tabSize = size;
  dataCount = 0;
  pList = new TList<TTabRecord<ValType>*>*[size];
  for (int i = 0; i < tabSize; i++)
  {
    pList[i] = new TList<TTabRecord<ValType>*>;
  }
}

template<class ValType>
TListHash<ValType>::~TListHash()
{
  for (int i = 0; i < tabSize; i++)
  {
    delete pList[i];
  }
  delete[]pList;
}

template<class ValType>
void TListHash<ValType>::Add(TTabRecord<ValType>* tr)
{
  currPos = HashFunc(tr->key) % tabSize;
  pList[currPos]->PutEnd(tr);
}

template<class ValType>
void TListHash<ValType>::Delete(TKey k)
{
  currPos = HashFunc(k) % tabSize;
  TList<TTabRecord<ValType>*>* pL = pList[currPos];
  for (int i = 0; i < pL->GetSize(); i++)
  {
    if (pL->Get(i)->key == k)
      pL->Get(i);
  }
}

template<class ValType>
TTabRecord<ValType>* TListHash<ValType>::Search(TKey k)
{
  currPos = HashFunc(k) % tabSize;
  TList<TTabRecord<ValType>*>* pL = pList[currPos];
  for (int i = 0; i < pL->GetSize(); i++)
  {
    if (pL->Get(i)->key == k)
      return pL->Get(i);
  }
  return NULL;
}

template<class ValType>
ValType * TListHash<ValType>::operator[](TKey k)
{
  TTabRecord<ValType>* res = Search(k);
  if (res == NULL)
  {
    TTabRecord<ValType>* n = new TTabRecord<ValType>(k, NULL, true);
    Add(n);
    return n->value;
  }
  return res->value;
}
