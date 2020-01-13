template<class ItemType>
void InsertionSort(ItemType values[], int numValues)
// Post: The elements in the array values are sorted by key.
//       The process stops as soon as values is sorted.
{
	ItemType key;
	int comparison;
	for (int iterator = 1; iterator <= numValues;iterator++)
	{
		key = values[iterator];
		comparison = iterator - 1;
		while (comparison >= 0 && values[comparison] > key)
		{
			values[comparison + 1] = values[comparison];
			comparison = comparison - 1;
		}
		values[comparison + 1] = key;
	}
}