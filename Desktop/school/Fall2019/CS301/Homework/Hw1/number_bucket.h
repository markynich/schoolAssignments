#include <iostream>
#include <string>
#include <stack>
using namespace std;

class number_bucket
{
  public:
    //constructor & create stack
    number_bucket();
    //deconstructor
    ~number_bucket();
    int getNumber()
    {
      int num = numStack.top();
      return num;
    }
    //prints all numbers within stack
    void getBucket()
    {
      cout << "printing all numbers top to bottom:" << endl;
      for (stack<int> bucket = numStack; !bucket.empty(); bucket.pop())
        cout << bucket.top() << endl;
    }
    //push & pop functions for the stack
    void push(int num) { numStack.push(num); }
    void pop() { numStack.pop(); }
    //checks if stack is empty, if not, it will print out the size
    void isEmpty()
    {
      if ( !numStack.empty() )
        cout << "number bucket is not empty" << endl
        << "bucket has size of " << numStack.size() << endl;
      else
        cout << "number bucket is empty" << endl;
    }
    //gets size of stack
    int get_size()
    {
      int size = numStack.size();
      return size;
    }
  private:
    stack<int> numStack;
};
// Constructors and Destructors are scoped and prints out that they are called
number_bucket::number_bucket(){ cout << "Constructor has been called" << endl; };
number_bucket::~number_bucket(){ cout << "Destructor has been called" << endl; };
