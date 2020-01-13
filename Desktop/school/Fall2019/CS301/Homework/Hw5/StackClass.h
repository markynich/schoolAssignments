#ifndef STACKCLASS_H
#define STACKCLASS_H
#include <iostream>
#include <fstream> //print onto ofstream
#include <string> //strings
#include <stack> //to use stacks

template <class T> //template class

class StackClass
{
  public:
    StackClass(); //constructor
    ~StackClass(); //deconstructor
    void printStack(std::ofstream&);
    void push(T data);
    void popStack();
    T topStack();
    bool isEmpty();
  private:
    std::stack <T> myStack;
};
#endif
