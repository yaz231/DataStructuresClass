#include "ArrayBag.h"
#include <iostream>
#include <cstddef>
// using namespace std;

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

// Example of adding a new method
template<class ItemType>
void ArrayBag<ItemType>::bubbleSort(){
	printf("Bubble Sorting\n");
   for (int i = 0; i < itemCount ; i ++){
      for (int j = 0; j < itemCount - 1; j ++){
         if (items[j] < items[j + 1]){
            continue;
         } else {
            int temp = items[j];
            items[j] = items[j + 1];
            items[j + 1] = temp;
         }
      }
   }
}  // end isEmpty

template<class ItemType>
int ArrayBag<ItemType>::binarySearchRecursive(int findNum){
   printf("Entered into Recursive BS\n");
   return helperBSRecursive(items, 0, itemCount, findNum);
}

template<class ItemType>
int ArrayBag<ItemType>::helperBSRecursive(int *arr, int start, int end, int numToFind){
   int mid = (start + end)/2;
   printf("Start: %d, Mid: %d, End: %d", start, mid, end);
   printf("\n");
   if (arr[mid] == numToFind){
      return mid;
   } else if (arr[mid] > numToFind){
      return helperBSRecursive(arr, start, mid - 1, numToFind);
   } else if (numToFind > arr[end] or numToFind < arr[start]) {
      return -1;
   } else {
      return helperBSRecursive(arr, mid, end, numToFind);
   }
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

