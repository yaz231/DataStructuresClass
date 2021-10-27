/** @file LinkedList.cpp */ 
#include <cassert> // For assert
#include "LinkedList.h" // Header file
#include <string> 
#include <vector>
// using namespace std;

LinkedList::LinkedList(){
  numItems = 0;
  headPtr = nullptr;
} // end default constructor


int LinkedList::getLength() {
  return numItems;
} // end of getLength


void LinkedList:: addNode(string aString){
  printf("Adding NODE\n");
  // printf("String to add: %s\n", aString.c_str());
  Node* newPtr = new Node();
  newPtr->setItem(aString);
  newPtr->setNext(nullptr);
  Node* prevPtr = headPtr;
  if (headPtr == nullptr){
    headPtr = newPtr;
    numItems ++;
    return;
  }
  Node* nextPtr = prevPtr->getNext();
  while(prevPtr != nullptr && (prevPtr->getItem() <= aString)){
    if (prevPtr->getItem() == aString){//No duplicates
      printf("Duplicates Found!\n");
      return;
    }
    if (nextPtr == nullptr) {
      printf("NEXT POINTER IS NULL\n");
      break;
    }
    prevPtr = nextPtr;
    nextPtr = nextPtr->getNext();
    printf("PREV POINTER: %s\n", prevPtr->getItem().c_str());
    printf("NEXT POINTER: %s\n", nextPtr);
    printf("\n");
  }
  prevPtr->setNext(newPtr);
  if (nextPtr != nullptr){
    newPtr->setNext(nextPtr);
  }
  numItems ++;
}// end of AddNode


vector<string> LinkedList::toVector() 
{
  printf("TO VECTOR\n");
  Node* currPtr = headPtr;
  string s;
  vector<string> vectorStrings;
  while (currPtr != nullptr){
    vectorStrings.push_back(currPtr->getItem());
    printf("%s", currPtr->getItem().c_str());
    // cout << currPtr->getItem() << endl;
    currPtr = currPtr->getNext();
  }
  return vectorStrings;
}  // end toVector
// end of implementation file 