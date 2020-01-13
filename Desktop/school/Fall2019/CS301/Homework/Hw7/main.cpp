#include "BST.h"

using namespace std;
/*
  Start of main
  reads inputs from input.txt stores them into BST and Queue
  Queue is for printing regular number list
*/
int main()
{
  BST myTree;
  ifstream rFile;
  ofstream oFile;
  /*
    Code block to read file called input.txt
    Calls function readList and passes the rFile object
  */
  rFile.open("input.txt");
  if (rFile.is_open())
  {
    myTree.readList(rFile);
  }
  rFile.close(); //close input.txt
  /*
    Code block to write into file called output.txt
    Calls function printTreeIO and passes oFile object
  */
  oFile.open("output.txt");
  if (oFile.is_open())
  {
    myTree.printTreeIO(oFile);
    oFile << "\n";
  }
  oFile.close(); //close output.txt
}
