#include "Swap.h"

template<class ItemType>
void merge(ItemType values[], int low, int mid, int high)
{
	int tempArr[high+1];
	int left = low;
	int temp = low;
	int right = mid + 1;
	while (left <= mid && right <= high)
	{
		if (values[left] < values[right])
		{
			tempArr[temp] = values[left];
			left += 1;
			temp += 1; 
		}
		else
		{
			tempArr[temp] = values[right];
			right += 1;
			temp += 1;
		}
	}
	while (left <= mid)
	{
		tempArr[temp] = values[left];
		left += 1;
		temp += 1;
	}
	while (right <= high)
	{
		tempArr[temp] = values[right];
		right += 1;
		temp += 1;
	}
	for (int i = low; i < temp; i++)
	{
		values[i] = tempArr[i];
	}
}

template<class ItemType>
void MergeSort(ItemType values[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(values,low,mid);
		MergeSort(values,(mid+1),high);
		merge(values,low,mid,high);
	}
}
