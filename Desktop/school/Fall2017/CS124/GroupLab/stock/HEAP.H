// HEAP.H

// Heap template class
// Author: Q. Prior

#ifndef _HEAP_H_
#define _HEAP_H_
#include <cctype>
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
/**
    \brief This is an enumeration that adds a status for OK and FAILED instead of true and false boolean
*/
enum STATUS {OK,FAILED};
//const int MAXHEAPSIZE = 100;
/**
    \brief This is a class HEAP which includes all function and storage needed to make the program and tree.
*/
template <class SOMETYPE>
class HEAP {
  public:
    enum heapType {MAX,MIN};
    SOMETYPE *buf;  // Pointer to the heap array 
    int size;       // Maximum size
    int nNodes;     // Current number of nodes  
    std::vector<int> minHV;
    std::vector<int> maxHV;
    std::vector<int> indexMinHV;
    std::vector<int> indexMaxHV; 
    int tempMaxV;
    int tempMinV;
  private:

    //int size;       // Maximum size
    //int nNodes;     // Current number of nodes
    //SOMETYPE *buf;  // Pointer to the heap array
    heapType t;
  public:
    HEAP (int a_size, heapType);
    ~HEAP();
    bool IsEmpty() {return (nNodes == 0);}
    bool IsFull() {return (nNodes == size);}
    STATUS Insert(SOMETYPE x);
    STATUS Remove(SOMETYPE &x);
    void printHeap();
    void addMaxHV(int value);
    void pushMaxHeapData();
    void displayVector();
    void tempMaxHeap();
    void tempMinHeap();

};

//****************************************************************
/**
    \brief This is a function that prints out the heap tree
*/
template <class SOMETYPE>
void HEAP<SOMETYPE>::printHeap()
{
    for(int i = 1; i < nNodes; i++)
        std::cout << buf[i] << std::endl;
}
/**
    \brief This is a function that adds the information from minHeap into a temp vector
*/
template <class SOMETYPE>
void HEAP<SOMETYPE>::tempMinHeap()
{
    for(int i = 1; i < nNodes; i++)
        tempMinV = buf[i];
}

/**
    \brief This is a funcction that adds the information from maxHeap into a temp vector
*/
template <class SOMETYPE>
void HEAP<SOMETYPE>::tempMaxHeap()
{
    for(int i = 1; i < nNodes; i++)
        tempMaxV = buf[i];
}

/**
    \brief This adds the value into the maxHeap vector
    \param a value of int to be added into maxHeap
*/
template <class SOMETYPE>
void HEAP<SOMETYPE>::void addMaxHV(int value)
{
    maxHV.push_back(value);
}

/**
    \brief This is a push function that pushes information from maxHeap into a vector
*/
template <class SOMETYPE>
void HEAP<SOMETYPE>::pushMaxHeapData()
{
    for(int i = 1; i < nNodes; i++)
        maxHV.push_back(buf[i]);
}
/**
    \brief This is a constructor which build a heap tree of size a_size
    \param a_size declares the size of the heap tree and which type of heap tree it will become
    
*/
template <class SOMETYPE>
HEAP<SOMETYPE>::HEAP(int a_size, heapType ht)

// Constructor: builds a heap of size "a_size".

{
    t = ht;
    nNodes = 0;
    buf = new SOMETYPE[a_size+1]; // +1 because buf[0] is not used
    if (buf) size = a_size;
    else size = 0;
}

//****************************************************************
/**
    \brief This is a destructor to destroy the heap trees
*/
template <class SOMETYPE>
HEAP<SOMETYPE>::~HEAP()

// Destructor.

{
    delete [] buf;
}

//****************************************************************
/**
    \brief This is a insert function to add data into the heap trees
    \param sometype which is basically an int of x
    \return returns OK
*/
template <class SOMETYPE>
STATUS HEAP<SOMETYPE>::Insert(SOMETYPE x)

// Inserts x into the heap.
// Returns OK if successful, FAILED if the heap is full.

{
    if (IsFull()) return FAILED;

    nNodes++;  // The last node of the heap is now vacant.

    // Starting from the (vacant) last node, go from node i to
    //   its parent iParent and, 
    
    // if it is a max heap then as long as the parent is smaller 
    //  than x, move the parent down:
    // if it is a min heap then as long as the parent is 
    //  larger than x, move the x up:

    int i = nNodes;
    int iParent;
    while (i > 1) {
        iParent = i/2;
        
        if(t == MAX)
        {
            if (x <= buf[iParent]) break;
        }
        else // must be MIN
        {
            if( x >= buf[iParent]) break;
        }
        buf[i] = buf[iParent];
        i = iParent;
    }

    // Insert x into the created vacancy:
    buf[i] = x;

    return OK;
}

//****************************************************************
/**
    \brief This is a remove function to remove data from the heap trees
    \param sometype which is basically an int reference of x
    \return returns OK
*/

template <class SOMETYPE>
STATUS HEAP<SOMETYPE>::Remove(SOMETYPE &x)

// Removes the largest element (from the root of the heap).
// Returns OK if successful, FAILED if the heap is empty.

{
    if (IsEmpty()) return FAILED;

    // Retrieve the top element:

    x = buf[1];             

    // Starting from the vacant root, go from node iParent to its
    //   larger child i and, as long as that child
    //   is greater than the last element of the heap,
    //   move that child up:

    int iParent = 1;       // root
    int i = 2;             // its left child
    while (i <= nNodes) {
        // Set i to the right child, i+1, if it
        //   exists and is larger:
        if (i < nNodes && buf[i] < buf[i+1]) i++;
        if (t == MIN)
            if(i < nNodes && buf[i] > buf[i+1]) i++;
        if (t == MAX)
            if(i < nNodes && buf[i] < buf[i+1]) i++;
        // Compare with the last node:
        if (t == MAX && buf[i] <= buf[nNodes]) break;
        if (t == MIN && buf[i] >= buf[nNodes]) break;
        buf[iParent] = buf[i];   // Move the child up; 
        iParent = i;             // buf[iParent] is now vacant.
        i *= 2;                  // i is set to its left child
    }

    // Move the last element into the created vacancy:
    if (nNodes > 1) buf[iParent] = buf[nNodes];
    nNodes--;
 
    return OK;
}

#endif // _HEAP_H_

