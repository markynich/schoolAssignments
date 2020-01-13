#ifndef PALINDROME_H
#define PALINDROME_H
#include <iostream>
#include <string> //strings
#include <stack> //to use stacks

template <class T> //template class

class Palindrome
{
  public:
    Palindrome(); //constructor
    ~Palindrome(); //deconstructor
    void isPalindrome(std::string str1);
    void push(T data);
    void popStack();
    T topStack();
    bool isEmpty();
  private:
    std::stack <T> myStack;
    std::string regular, reversed;
};
#endif
