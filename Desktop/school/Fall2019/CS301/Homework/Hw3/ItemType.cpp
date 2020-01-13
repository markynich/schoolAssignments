// The following definitions go into file ItemType.cpp.
#include <fstream>
#include <iostream>
#include <string>
#include "ItemType.h"
#include "list.h"

using namespace std;

ItemType::ItemType() { value = 0; }
ItemType::~ItemType(){}
/*
LESS = 0
GREATER = 1
EQUAL = 2
To check if value exists in linked list
Also to compare value with obj::otherItem
*/
RelationType ItemType::ComparedTo(ItemType otherItem) const
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize() { value = MAX_ITEMS; }

void ItemType::Print(ostream& out, string sentence) const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
  out << sentence << endl;
}

void ItemType::PutItem(int addItem, ostream& out)
{
  string sentP;
  if (List::getSize() != value)
  {
    List::addNode(addItem);
    sentP = to_string(addItem) + " is added into list";
  }
  else
    sentP = "Cannot add " + to_string(addItem) + " into list";
  ItemType::Print(out, sentP);
}

void ItemType::getItem(int findItem, ostream& out)
{
  string sentS;
  if (List::searchNode(findItem) == true)
    sentS = to_string(findItem) + " is found in list";
  else
    sentS = to_string(findItem) + " is not found in list";
  ItemType::Print(out, sentS);
}

void ItemType::getLength(ostream& out)
{
  string sentL = "List has length of " + to_string(List::getSize());
  ItemType::Print(out, sentL);
}

void ItemType::isFull(ostream& out)
{
  string sentF;
  if (List::getSize() == value)
    sentF = "List is full(max is 5 numbers)";
  else
    sentF = "List is not full";
  ItemType::Print(out, sentF);
}
/*
*/
void ItemType::DeleteItem(int dItem, ostream& out)
{
  string sentD;
  if (List::DeleteNode(dItem) == true)
    sentD = to_string(dItem) + " is deleted from list";
  else
    sentD = to_string(dItem) + " is not found in list";
  ItemType::Print(out, sentD);
}

void ItemType::MakeEmpty(ostream& out)
{
  List::emptyList();
  string sentE = "List is now empty";
  ItemType::Print(out, sentE);
}

int ItemType::FunctionList(string strFun)
{
  string arr[8] = { "GetLength", "PutItem", "PrintList", "GetItem", "IsFull",
        "DeleteItem", "MakeEmpty", "Quit" };
  if (strFun.find(arr[0]) != string::npos)
    return 1;
  else if (strFun.find(arr[1]) != string::npos)
    return 2;
  else if (strFun.find(arr[2]) != string::npos)
    return 3;
  else if (strFun.find(arr[3]) != string::npos)
    return 4;
  else if (strFun.find(arr[4]) != string::npos)
    return 5;
  else if (strFun.find(arr[5]) != string::npos)
    return 6;
  else if (strFun.find(arr[6]) != string::npos)
    return 7;
  else if (strFun.find(arr[7]) != string::npos)
    return 8;
  else
    return 9;
}
