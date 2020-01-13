#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream> //print onto ofstream
#include <string> //strings
#include <queue>

class BST
{
  public:
    BST(); //constructor
    ~BST(); //deconstructor
    void readList(std::ifstream&);
    void printTreeIO(std::ofstream&);

  private:
  //struct for nodes for Binary Search Tree
  typedef struct nodeT{
      int value;
      nodeT* left;
      nodeT* right;
    }* treeNode;
    treeNode root;
    //queue to store old list into queue to print later
    std::queue <int> origList;
    treeNode newNode(int data); //create new node for insertion
    void insertNode(treeNode ptr,int data);
    void printTreeInOrder(treeNode ptr,std::ofstream&);
};
#endif
