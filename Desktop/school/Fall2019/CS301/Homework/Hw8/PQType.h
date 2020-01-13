// Definition of class PQType, which represents the Priority Queue ADT
class FullPQ{};
class EmptyPQ{};
#include "Heap.h"
template<class ItemType>
class PQType
{
public:
  PQType(int);          // parameterized class constructor
  ~PQType();            // class destructor

  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.

  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)

  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)

  void Enqueue(ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.

  void Dequeue(ItemType& item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.
private:
  int length;
  HeapType<ItemType> items;
  int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
  maxItems = max;
  items.elements = new ItemType[max];
  length = 0;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
  delete [] items.elements;
}
template<class ItemType>
bool PQType<ItemType>::IsEmpty()const
{
  if (length == 0)
    return true;
  return false;
}
template<class ItemType>
bool PQType<ItemType>::IsFull()const
{
  if (length == maxItems)
    return true;
  return false;
}
template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
{
  if (PQType<ItemType>::IsFull())
    throw FullPQ();
  else
  {
    items.elements[length] = newItem;
    length += 1;
    items.ReheapUp(0, (length - 1));
  }
}
template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
{
  if (PQType<ItemType>::IsEmpty())
    throw EmptyPQ();
  else
  {
    item = items.elements[0];
    items.elements[0] = items.elements[length - 1];
    length -= 1;
    items.ReheapDown(0, (length - 1));
  }
}
