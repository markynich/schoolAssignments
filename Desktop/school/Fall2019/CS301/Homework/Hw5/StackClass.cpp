#include <iostream>
#include <fstream>
#include <string> //to use string
#include <stack> //to use stacks
#include "StackClass.h"

using namespace std;

//constructor
template <class T>
StackClass<T>::StackClass(){}

//deconstructor
template <class T>
StackClass<T>::~StackClass(){}

/*
prints the stack into the passing output file
until it is empty
*/
template <class T>
void StackClass<T>::printStack(ofstream& out){
  while (StackClass<T>::isEmpty() == false)
  {
    out << StackClass<T>::topStack();
    StackClass<T>::popStack();
  }
  out << '\n';
}
/*
Pushes the passing variable into the stack
*/
template <class T>
void StackClass<T>::push(T data){
  myStack.push(data);
}

/*
Pops the top of stack
*/
template <class T>
void StackClass<T>::popStack(){
  myStack.pop();
}
/*
returns the data from top of stack
*/
template <class T>
T StackClass<T>::topStack(){
  return myStack.top();
}
/*
check is the stack is empty
false == not empty | true == empty
*/
template <class T>
bool StackClass<T>::isEmpty(){
  return (myStack.empty());
}
