#include <iostream>
#include <string>
#include <fstream>
#include "permutation.h"

using namespace std;

int input,check=0; //global variables

int main()
{
  /*
    Check if user input is correct range 1-25
  */
  while (check == 0)
  {
    cout << "Enter a number from 1 - 25: ";
    cin >> input;
    if (input <= 25 && input >= 1) { check = 1; }
    else
    {
      cin.clear(); //clear user input
      cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears cin buffer
      cout << "out of bounds, please enter a correct number" << endl;
    }
  }
  int* arr = new int[input];      //create dynamic array
  permutation pM;                 //create class object
  pM.setSize(input);              //insert size into class
  pM.storeArr(pM.getSize(), arr); //store numbers into dynamic array
  pM.permute(arr,0,input-1);      //permutation function
  return 0;
}
