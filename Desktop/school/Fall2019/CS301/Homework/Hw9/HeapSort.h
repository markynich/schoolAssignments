#include "Swap.h"

template<class ItemType>
void ReheapDown(ItemType values[],int root, int bottom)
// Post: Heap property is restored.
{
  int topIndex;
  int lIndex = (root * 2) + 1; //left child tree node
    int rIndex = (root * 2) + 2; //right child tree node
    if (lIndex <= bottom)
    {
      if (lIndex == bottom)
          topIndex = lIndex;
      else
      {
          if (values[lIndex] <= values[rIndex])
            topIndex = rIndex;
          else
            topIndex = lIndex;
      }
      if (values[topIndex] > values[root])
      {
          Swap(values[topIndex],values[root]);
          ReheapDown(values,topIndex,bottom);
      }
    }
}

template<class ItemType>
void HeapSort(ItemType values[], int numValues)
{
	for (int root = (numValues/2) - 1; root >= 0; root--)
		ReheapDown(values,root,(numValues - 1));
	for (int root = (numValues - 1); root >= 1; root--)
	{
		Swap(values[0],values[root]);
		ReheapDown(values,0,(root-1));
	}
}