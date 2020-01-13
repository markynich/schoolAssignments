#include <iostream>
#include <string> //string function
#include <stack> //stack function
#include "Palindrome.h" //header file
#include "Palindrome.cpp" //for defining template class & no need to add during compiler

using namespace std;

int main()
{
  cout << "\033[2J\033[1;1H" << "\nWelcome to Palindrome Checker!\n";
  Palindrome<char> palDrome;
  return 0;
}
