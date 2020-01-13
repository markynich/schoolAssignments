#include <iostream>
#include <fstream>
#include <sstream>
#include <string> //to use string
#include <queue>
#include "BST.h"

using namespace std;
/*
  constructor, makes root ptr NULL
*/
BST::BST(){
  root = NULL;
}
/*
  destructor,Makes root NULL and destroys root.
*/
BST::~BST() {
  root = NULL;
  delete root;
}
/*
  Public Function
  Will read file and insert each number into queue and binary search tree
*/
void BST::readList(ifstream& store){
  string line;
  while (getline(store, line))
  {
    if (line != "")
    {
      int num = stoi(line);
      origList.push(num);
      BST::insertNode(root,num);
    }
  }
}
/*
  Private Function
  Create a new node to insert into Binary Search Tree
  Set left and right pointer to NULL
  set value to passing data
*/
BST::treeNode BST::newNode(int data) {
  treeNode newNode = new nodeT;
  newNode->value = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
/*
  Private function
  Adds node into Binary Search Tree
  Finds location where the node should be placed
*/
void BST::insertNode(treeNode ptr, int data)
{
  if (root == NULL)
  {
    root = BST::newNode(data);
  }
  else if (data <= ptr->value)
  {
    if (ptr->left != NULL)
      BST::insertNode(ptr->left, data);
    else
      ptr->left = BST::newNode(data);
  }
  else if (data > ptr->value)
  {
    if (ptr->right != NULL)
      BST::insertNode(ptr->right, data);
    else
      ptr->right = BST::newNode(data);
  }
}
/*
  public function that main can call to print tree and queue
  prints tree in order
  Prints values into a file
*/
void BST::printTreeIO(ofstream& out)
{
  out << "Before    InOrder\n";
  BST::printTreeInOrder(root,out);
}
/*
  Prints tree in order from least to greatest
*/
void BST::printTreeInOrder(treeNode ptr,ofstream& out){
  if (root != NULL)
  {
    if (ptr->left != NULL)
      BST::printTreeInOrder(ptr->left,out);
    out << origList.front() << "         " << ptr->value << "\n";
    origList.pop();
    if (ptr->right != NULL)
      BST::printTreeInOrder(ptr->right,out);
  }
  else
    cout << "Tree is Empty\n";
}
