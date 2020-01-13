#include "Swap.h"
template<class ItemType>
void SelectionSort(ItemType values[], int numValues)
//
//
{
	int minVal,comparison;
	for (int iterator = 0; iterator < numValues; iterator++)
	{
		minVal = iterator;
		for (comparison = iterator + 1; comparison <= numValues; comparison++)
		{
			if (values[comparison] < values[minVal])
				minVal = comparison;
		}
		Swap(values[minVal],values[iterator]);
	}
}