#include <iostream>
#include <cstdlib>
#include <string>
#include "ItemType.h"
#include "list.h"

using namespace std;
List::List(){
  head = NULL;
  curr = NULL;
  temp = NULL;
}; //constructor

List::~List(){
  head = NULL;
  curr = NULL;
  temp = NULL;
  delete head;
  delete curr;
  delete temp;
}; //deconstructor

void List::addNode(int addData)
{
  nodePtr n = new node;
  n->next = NULL;
  n->data = addData;
  /*
  if there is a list, point to last node
  and add n to end of list
  */
  if (head != NULL)
  {
    curr = head;
    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = n;
  }
  /*
  if there is no list yet, head equals to n
  new list is created
  */
  else
  {
    head = n;
  }
}//end of addNode

bool List::DeleteNode(int delData)
{
  nodePtr dPtr = NULL;
  curr = head;
  temp = head;
  /*
    If curr is not at end of list
    & curr is not equal to delData, continue
  */
  while (curr != NULL && curr->data != delData)
  {
    temp = curr;
    curr = curr->next;
  }
  /*
    If curr is at end of list, delData is not in List
    delete node "d" to clear memory space for no
    memory leak
  */
  if (curr == NULL)
  {
     //cout << delData << " was not in the list" << endl;
     delete dPtr;
     check = false;
  }
  /*
    If curr has found delData node, "d" becomes curr
    curr points to next node, temp points to curr
    delete delData node "d"
  */
  else
  {
    dPtr = curr;
    //if first node is going to be deleted
    if (head == curr)
      head = head->next;
    curr = curr->next;
    temp->next = curr;
    delete dPtr;
    //cout << delData << " was deleted from the list" << endl;
    check = true;
  }
  return check;
}

void List::printList()
{
  curr = head;
  while (curr != NULL)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}
string List::printList(string sentence)
{
  curr = head;
  if (curr == NULL)
  {
    sentence = "List is empty";
  }
  else
  {
    while (curr != NULL)
    {
      sentence = sentence + to_string(curr->data) + " ";
      curr = curr->next;
    }
  }
  return sentence;
}

bool List::searchNode(int findData)
{
  temp = head;
  curr = head;
  /*
    If curr is not at end of list
    & curr is not equal to findData, continue
  */
  while (curr != NULL && curr->data != findData)
  {
    temp = curr;
    curr = curr->next;
  }
  /*
    If curr is at end of list, findData is not in List
  */
  if (curr == NULL)
  {
     //cout << findData << " does not exist in the list" << endl;
     check = false;
  }
  /*
    If curr has found findData node, print out
    to tell user it is found
  */
  else
  {
    //cout << findData << " found in the list" << endl;
    check = true;
  }
  return check;
}
int List::getSize()
{
  int count = 0;
  temp = head;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}
void List::emptyList()
{
  while (head != NULL)
  {
    nodePtr e = head;
    if (head->next == NULL)
    {
      e = head;
      head = NULL;
      delete e;
    }
    else
    {
      e = head;
      while (e->next != NULL)
      {
        temp = e;
        e = e->next;
      }
      e->next = NULL;
      delete e;
    }
  }
  head = NULL;
}
