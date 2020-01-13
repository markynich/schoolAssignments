#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class permutation
{
  public:
    permutation(); //constructor
    ~permutation(); //destructor

  /*
      Setters & Getters for size of array
  */
    int getSize() { return size; }
    void setSize(int s) { size = s; }
/*
  storeArr takes in 2 param = size of arr & array
  inserts all the numbers into arr
*/
    void storeArr(int size, int arr[])
    {
      for (int x = 0; x < size; x++)
      {
        int temp = x+1;
        arr[x] = temp;
      }
    }
/*
  writeIntoFile takes in 1 param = permutation line
  opens/creates the "output.txt" file and writes the permutation
  into the file & closes it.
*/
    void writeIntoFile(int size, int arr[])
    {
      ofstream outF;
      //std::ios::app is used for appending to file
      outF.open("output.txt", std::ios::app);
      for (int i = 0; i < size; i++)
        outF << arr[i] << " ";
      outF << "\n";
      outF.close();
    }
/*
  permute function takes in 3 params: array, beginning of array, end of array
  Goes through the array, swapping numbers and recalling itself. Once beginning
  array equals end of array, it will print out the permutation line
*/
    void permute(int arr[], int x, int y)
    {
      // printing each permutation into file
      if (x == y)
        writeIntoFile(size,arr);
      else
      {
     // Permutations made
        for (int i = x; i <= y; i++)
        {
          // Swapping done
          int temp = arr[x];
          arr[x] = arr[i];
          arr[i] = temp;
          // Recursion of function
          permute(arr, x+1, y);
          //backtrack swapping
          temp = arr[x];
          arr[x] = arr[i];
          arr[i] = temp;
        }
      }
    }

    //debugging function to print out onto console
    void printArr(int size, int arr[])
    {
      for (int x = 0; x < size; x++)
        cout << arr[x] << " ";
      cout << "\n";
    }

  private:
    int size;

};
permutation::permutation(){};
permutation::~permutation(){};
