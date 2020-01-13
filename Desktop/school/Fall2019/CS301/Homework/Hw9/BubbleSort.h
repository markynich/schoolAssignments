#include "Swap.h"

template<class ItemType>
void BubbleSort(ItemType values[], int numValues)
// Post: The elements in the array values are sorted by key.
//       The process stops after
{
  bool unSorted = true;
  int outerLoop = 0;
  while (unSorted == true && outerLoop < numValues)
  {
    unSorted = false;
    for (int index = numValues; index > outerLoop; index--)
    {
      if (values[index] < values[index-1])
      {
        Swap(values[index], values[index-1]);
        unSorted = true;
      }
    }
    outerLoop++;
  }
}