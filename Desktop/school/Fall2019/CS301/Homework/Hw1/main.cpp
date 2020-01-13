#include "number_bucket.h"
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;
//global integer variable
int number;

int main()
{
    number_bucket numBucket; //create class object
    numBucket.isEmpty();     //first check to see if the stack is empty
    //inserting 10 random numbers from 0-10
    cout << "Adding 10 random numbers" << endl;
    for (int x = 0; x < 10; x++)
    {
      number = (rand() % 10) + 1;
      numBucket.push(number);
    }
    numBucket.isEmpty();     //check stack to show it's not empty
    numBucket.getBucket();   //print out the stack
    //remove top 3 numbers from the stack with pop
    cout << "removing 3 numbers" << endl;
    for (int x = 0; x < 3; x++)
    {
          numBucket.pop();
    }
    numBucket.isEmpty();    //check stack to show it's not empty
    numBucket.getBucket();  //print out the stack
    //clears out the stack
    cout << "clearing bucket" << endl;
    number = numBucket.get_size();
    for (int x = 0; x < number; x++)
    {
      numBucket.pop();
    }
    numBucket.isEmpty();    //checks stack to show it's empty
    cout << "\nend of program \n\n";
    return 0;
}
