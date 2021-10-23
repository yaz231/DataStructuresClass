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
  Node* newNode = new Node();
  newNode->setItem(aString);
  newNode->setNext(nullptr);

  if (headPtr == NULL || headPtr->getItem() >= aString){
    newNode->setNext(headPtr);
    headPtr = newNode;
    return;
  } else if(headPtr->getNext() != NULL && headPtr->getNext()->getItem() >= aString){
    Node* nextNode = headPtr->getNext();
    newNode->setNext(nextNode);
    headPtr->setNext(newNode);
    return;
  } else {
    Node* left;
    Node* right;
    while(right != NULL && right->getNext()->getItem() <= aString){
      left = right;
      right = right->getNext();
    }
    left->setNext(newNode);
    newNode->setNext(right);
  }
  // Node<string>* currPtr = headPtr;
  // while (currPtr->getNext() != nullptr && ){
  //   currPtr = currPtr->getNext();
  // }
  // Node<string>* newPtr;
  // newPtr->setItem(aString);
  // newPtr->setNext(nullptr);
  // currPtr->setNext(newPtr);
}// end of AddNode


vector<string> LinkedList::toVector() const
{
  Node* currPtr = headPtr;
  vector<string> vectorStrings;
	for (int i = 0; i < numItems; i++)
	  vectorStrings.push_back(currPtr->getItem());
    currPtr = currPtr->getNext();
   return vectorStrings;
}  // end toVector
// end of implementation file 