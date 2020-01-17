#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>
struct AQIData
{
    std::string county;
    std::string AQI;
};
//start of QuickSort
template <class SOMETYPE>
class QUICKSORT {
 private:
 inline void Swap(SOMETYPE &a, SOMETYPE &b);
 // Returns the new location of the pivot element:
 int Split(SOMETYPE a[], int n);
 public:
 // Recursive sort function:
 void Sort(SOMETYPE a[], int n);
}; //end of Quicksort

template <class SOMETYPE>
class MERGESORT {
 private:
 SOMETYPE *work;
 inline void Swap(SOMETYPE &a, SOMETYPE &b);
 void Merge(SOMETYPE a1[], int n1, SOMETYPE a2[], int n2);
 public:
 // Constructor: allocates a work array
 MERGESORT(int n) { work = new SOMETYPE[n]; }
 // Destructor: frees the work array
 ~MERGESORT() { delete [] work; }
 // Recursive sort function:
 void Sort(SOMETYPE a[], int n);
};




/** \page countRows
    Read the first string in file f return it.
*/

int countRows(std::string f);

/** \page readData
    \brief Read the first string in file f return it.
    \param f filename
    \param aqi[] is an array to put data in
    /param n number amount of elements in the array
    \return void
*/

void readData(std::string f,AQIData aqi[],int n);
bool operator>(AQIData& lhs, AQIData& rhs);
bool operator<(AQIData& lhs, AQIData& rhs);
bool operator<=(AQIData& lhs, AQIData& rhs);
bool operator>=(AQIData& lhs, AQIData& rhs);
