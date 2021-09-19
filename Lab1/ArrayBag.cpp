#include "ArrayBag.h"
#include <iostream>
#include <cstddef>
// using namespace std;

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

/******************************************************************************/
/* Function:  bubbleSort
/* Inputs:    NA
/* Outputs:   NA
/* Purpose:   This function sorts the ArrayBag entries using Bubble Sort
/******************************************************************************/
template<class ItemType>
void ArrayBag<ItemType>::bubbleSort(){
	// printf("Bubble Sorting\n");
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
}

/******************************************************************************/
/* Function:  binarySearchRecursive
/* Inputs:    findNum, the number to search in the ArrayBag entries.
/* Outputs:   NA
/* Purpose:   This function ultimately returns the output from the helperfunction.
/******************************************************************************/
template<class ItemType>
int ArrayBag<ItemType>::binarySearchRecursive(int findNum){
   // printf("Entered into Recursive BS\n");
   return helperBSRecursive(items, 0, itemCount, findNum);
}

/******************************************************************************/
/* Function:  helperBSRecursive
/* Inputs:    *arr, the array of entries from the ArrayBag
/*            start, the beginning index of the array
/*            end, the last index of the array
/*            numToFind, the number to search for within the array
/* Outputs:   the index of numToFind if it's contained in the array
              or -1 if numToFind doesn't exist within ArrayBag's entries
/* Purpose:   This function recursively searches through the area to look for numToFind
              and returns the index of numToFind if it is found within the ArrayBag entries
/******************************************************************************/
template<class ItemType>
int ArrayBag<ItemType>::helperBSRecursive(int *arr, int start, int end, int numToFind){
   if (start <= end){
      int mid = (start + end)/2;
      // printf("Start: %d, Mid: %d, End: %d", start, mid, end);
      // printf("\n");
      if (arr[mid] == numToFind){
         return mid;
      } else if (arr[mid] > numToFind){//Search first half of sorted area
         return helperBSRecursive(arr, start, mid - 1, numToFind);
      } else if (arr[mid] < numToFind){//Search second half of sorted area
         return helperBSRecursive(arr, mid, end, numToFind);
      }
   }
   return -1;
}

/******************************************************************************/
/* Function:  binarySearchIterative
/* Inputs:    numToFind, the number to search for within the array
/* Outputs:   the index of numToFind if it's contained in the array
              or -1 if numToFind doesn't exist within ArrayBag's entries
/* Purpose:   This function iteratively searches through the area to look for numToFind
              and returns the index of numToFind if it is found within the ArrayBag entries
/******************************************************************************/
template<class ItemType>
int ArrayBag<ItemType>::binarySearchIterative(int numToFind){
   // printf("Entered Iterative BS\n");
   int start = 0;
   int end = itemCount;
   int mid;
   while (start < end){
      mid = (start + end)/2;
      // printf("Start: %d, Mid: %d, End: %d", start, mid, end);
      // printf("\n");
      if (items[mid] < numToFind){//Search second half of sorted array
         start = mid + 1;
      } else {//Search first half of sorted array
         end = mid;
      }
   }

   if (items[start] == numToFind){
      return start;
   }

   return -1;
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

