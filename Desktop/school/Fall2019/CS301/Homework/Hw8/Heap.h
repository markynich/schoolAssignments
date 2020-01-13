template <class ItemType>
void swap(ItemType& one, ItemType& two);

template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
  void ReheapDown(int root, int bottom);
  void ReheapUp(int root, int bottom);
  ItemType* elements;   // Array to be allocated dynamically
  int numElements;
};

template <class ItemType>
void Swap(ItemType& one, ItemType& two)
{
  ItemType temp;
  temp = one;
  one = two;
  two = temp;
}
template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  if (bottom > root)
  {
    int pIndex = (bottom - 1) / 2;
    if (elements[pIndex] < elements[bottom])
    {
      Swap(elements[pIndex],elements[bottom]);
      ReheapUp(root, pIndex);
    }
  }
}
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
  int lIndex = (root * 2) + 1; //left child tree node
  int rIndex = (root * 2) + 2; //right child tree node
  if (lIndex <= bottom)
  {
    if (lIndex == bottom)
      numElements = lIndex;
    else
    {
      if (elements[lIndex] <= elements[rIndex])
        numElements = rIndex;
      else
        numElements = lIndex;
    }
    if (elements[numElements] > elements[root])
    {
      Swap(elements[numElements],elements[root]);
      ReheapDown(numElements,bottom);
    }
  }
    /*
       Your code goes here
    */
}
