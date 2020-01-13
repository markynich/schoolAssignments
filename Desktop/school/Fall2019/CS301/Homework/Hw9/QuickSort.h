#include "Swap.h"

template<class ItemType>
int pivotPosition(ItemType values[], int first, int last)
{
	ItemType pivotValue = values[last];
	int iterator = (first - 1);
	for (int comparison = first; comparison <= last-1; comparison++)
	{
		if (values[comparison] <= pivotValue)
		{
			iterator += 1;
			Swap(values[comparison],values[iterator]);
		}
	}
	Swap(values[iterator + 1],values[last]);
	return (iterator + 1);
}

template<class ItemType>
void QuickSort(ItemType values[], int first, int last)
{
	if (first <= last)
	{
		int pivot = pivotPosition(values,first,last);

		QuickSort(values,first,(pivot - 1));
		QuickSort(values,(pivot + 1), last);
	}
}
