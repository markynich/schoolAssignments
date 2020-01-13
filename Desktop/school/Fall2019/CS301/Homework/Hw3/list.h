#ifndef LIST_H
#define LIST_H
#include <string>
class List{
  public:
    List(); //constructor
    ~List(); //deconstructor
    void addNode(int addData);
    bool DeleteNode(int delData);
    void printList();
    std::string printList(std::string sentence);
    bool searchNode(int findData);
    int getSize();
    void emptyList();

  private:
    bool check;
    typedef struct node{
      int data;
      node* next;
    }* nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;
};
#endif
