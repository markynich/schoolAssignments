// The following declarations and definitions go into file
// ItemType.h.
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <fstream>
#include <string>
#include "list.h"

const int MAX_ITEMS = 5;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType : public List
{
public:
  ItemType();
  ~ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&,std::string sentence) const;
  void Initialize();
  void getLength(std::ostream&);
  void PutItem(int addItem, std::ostream&);
  void getItem(int findItem, std::ostream&);
  void isFull(std::ostream&);
  void DeleteItem(int dItem, std::ostream&);
  void MakeEmpty(std::ostream&);
  int FunctionList(std::string strFun);
private:
  int value;
};
#endif
