#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "ItemType.h"
#include "list.h"

using namespace std;
string userTest, line, line2, uList;
int convI, compare1;
bool sysI, sysO = false;
int main()
{
  ItemType iT;
  ofstream oFile;
  ifstream tFile;
  iT.Initialize();
  cout << "Please Enter an input file for test inputs: ";
  while (sysI == false)
  {
      cin >> userTest;
      tFile.open(userTest);
      if (tFile.is_open())
      {
        cout << "input file is open\n";
        sysI = true;
      }
      else
        cout << "Error!\n" << "Input file does not exist, please enter correct file: ";
  }
  cout << "Please enter a desired output file name: ";
  while (sysO == false)
  {
    cin >> userTest;
    oFile.open(userTest, std::ios::app);
    if (oFile.is_open())
    {
      cout << "output file is open\n";
      sysO = true;
    }
    else
      cout << "Error!\n" << "output file does not exist or cannot be created "
      << "please enter correct file: ";
  }
  cout << "Please enter name for test: ";
  cin >> userTest;
  cout << userTest << endl;
  oFile << userTest << endl;
  int counter = 1;
  while ( getline(tFile,line) )
  {
      if (line.find(' ') != string::npos)
      {
        line2 = line.substr(0, line.find(' '));
        //for user input number
        line = line.substr(line.find(' ')+1);
        stringstream conv(line);
        conv >> convI;
      }
      else
        line2 = line;
        if (iT.FunctionList(line2) == 1)
        {
          cout << "command " << to_string(counter) << " has been executed\n";
          iT.getLength(oFile);
        }
        else if (iT.FunctionList(line2) == 2)
        {
          cout << "command " << to_string(counter) << " has been executed\n";
          iT.PutItem(convI,oFile);
        }
        else if (iT.FunctionList(line2) == 3)
        {
          cout << "command " << to_string(counter) << " has been executed\n";
          uList = "";
          iT.Print(oFile,iT.printList(uList));
        }
        else if (iT.FunctionList(line2) == 4)
        {
          cout << "command " << to_string(counter) << " has been executed\n";
          iT.getItem(convI,oFile);
        }
        else if (iT.FunctionList(line2) == 5)
        {
          cout << "command " << to_string(counter) << " has been executed\n";
          iT.isFull(oFile);
        }
        else if (iT.FunctionList(line2) == 6)
        {
          cout << "command " << to_string(counter) << " has been executed\n";
          iT.DeleteItem(convI,oFile);
        }
        else if (iT.FunctionList(line2) == 7)
        {
          cout << "command " << to_string(counter) << " has been executed\n";
          iT.MakeEmpty(oFile);
        }
        else if (iT.FunctionList(line2) == 8)
        {
          cout << "Exiting Program, goodbye" << endl;
          oFile.close();
          tFile.close();
          return 0;
        }
        else if (iT.FunctionList(line2) == 9)
        {
          cout << "Error, command " + to_string(counter) + " does not exist\n";
        }
        counter++;
  } //while read line
  cout << "No more lines to read\nExiting Program, goodbye" << endl;
  oFile.close();
  tFile.close();
  return 0;
}
