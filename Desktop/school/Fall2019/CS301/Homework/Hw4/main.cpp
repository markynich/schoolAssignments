#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
//#include "schoolSystem.h"
#include "schoolCommands.h"
using namespace std;

int main()
{
  schoolCommands rW;
  cout << "Welcome to Assignment 4\n";
  rW.readCommand();
  return 0;
}
