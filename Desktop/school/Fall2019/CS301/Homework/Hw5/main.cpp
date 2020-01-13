#include <iostream>
#include <fstream> //ifstream and ofstream
#include <string> //string function
#include <stack> //stack function
#include "StackClass.h" //header file
#include "StackClass.cpp" //for defining template class

using namespace std;

int main()
{
  string line; //variable to read file
  ofstream oFile; //output
  ifstream iFile; //input
  StackClass<char> stackC; //declare stack to be char
  oFile.open("output.txt"); //open output.txt
  /*
  Exit if unable to open output.txt
  */
  if (!oFile.is_open())
  {
    cout << "unable to open \"output.txt\"\nExiting now\n";
    exit (1);
  }
  /*
  run program if read.txt is open
  */
  iFile.open("read.txt");
  if (iFile.is_open())
  {
    /*
    Keep reading file until there are no more lines
    */
    while (getline(iFile,line))
    {
      size_t length = line.length(); //get size of line
      //insert all chars into the stack
      for (unsigned int i = 0; i < length; i++)
        stackC.push(line[i]);
      //print stack into output.txt
      stackC.printStack(oFile);
    }
  }
  else
  {
    cout << "unable to open \"read.txt\"\n";
  }
  iFile.close();
  oFile.close();
  cout << "Program over\nGoodbye\n";
  return 0;
}
