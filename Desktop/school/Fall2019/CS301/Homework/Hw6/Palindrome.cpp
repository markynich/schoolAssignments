#include <iostream>
#include <string> //to use string
#include <stack> //to use stacks
#include "Palindrome.h"

using namespace std;

//constructor
template <class T>
Palindrome<T>::Palindrome(){
  regular = "";
  reversed = "";
  Palindrome<T>::isPalindrome(regular);
}

//deconstructor
template <class T>
Palindrome<T>::~Palindrome(){}
/*
Recursive function that reads the string and reverses it.
Compares the strings and checks if they are similar. It will tell the user
it is a palindrome or not. Asks user input to quit or continue
*/
template <class T>
void Palindrome<T>::isPalindrome(string str1){
  if (str1 == "")
  {
    cout << "Please enter a string to check if Palindrome exists: ";
    getline(cin,str1);
    for (int i = 0; i < str1.length(); i++)
      Palindrome<T>::push(str1[i]);
    Palindrome<T>::isPalindrome(str1);
  }
  else if (Palindrome<T>::isEmpty() != true)
  {
    reversed = reversed + Palindrome<T>::topStack();
    Palindrome<T>::popStack();
    Palindrome<T>::isPalindrome(str1);
  }
  else
  {
    cout << "Before : " << str1 << "\n";
    cout << "After  : " << reversed << "\n\n";
    if (str1 == reversed)
      cout << "String is a palindrome\n";
    else
      cout << "String is not a palindrome\n";
    cout << "Type any key & press enter to continue or [Q/q] & enter to quit: ";
    getline(cin,str1);
    if (str1 == "q" || str1 == "Q")
    {
      cout << "Exiting\nGoodbye\n";
      exit (0);
    }
    else
    {
      str1 = "";
      reversed = "";
      cout << "\033[2J\033[1;1H";
      Palindrome<T>::isPalindrome(str1);
    }
  }
}

/*
Pushes the passing variable into the stack
*/
template <class T>
void Palindrome<T>::push(T data){
  myStack.push(data);
}

/*
Pops the top of stack
*/
template <class T>
void Palindrome<T>::popStack(){
  myStack.pop();
}
/*
returns the data from top of stack
*/
template <class T>
T Palindrome<T>::topStack(){
  return myStack.top();
}
/*
check is the stack is empty
false == not empty | true == empty
*/
template <class T>
bool Palindrome<T>::isEmpty(){
  return (myStack.empty());
}
