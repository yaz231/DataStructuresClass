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
  Node* newNode;
  Node* currNode;
  Node* prevNode;

  //Creating new Node for aString
  newNode = new Node;
  newNode->setItem(aString);
  newNode->setNext(nullptr);

  if (!headPtr) {//if LinkedList is empty, assign headPtr to the new Node
    headPtr = newNode;
  } else {
    currNode = headPtr;
    if (aString < headPtr->getItem()){//If our aString comes before the beginning of the LinkedList, add it to the front
      numItems ++;
      newNode->setNext(headPtr);
      headPtr = newNode;
    } else if (aString == headPtr->getItem()){//Ignoring duplicates
      return;
    } else {
      prevNode = currNode;
      while (currNode && currNode->getItem() < aString){//Looping through LinkedList until we reach the end or we reach the Node where we should insert newNode
        prevNode = currNode;
        currNode = currNode->getNext();
      }
      if (!currNode){//If we've reached the end
        prevNode->setNext(newNode);
      } else if (currNode->getItem() == aString){//Ignore duplicates
        return;
      } else {//Add Node
        newNode->setNext(currNode);
        prevNode->setNext(newNode);
      }
      numItems ++;
    }
  }
}

vector<string> LinkedList::toVector() 
{
  // printf("TO VECTOR\n");
  Node* currPtr = headPtr;
  string s;
  vector<string> vectorStrings;
  while (currPtr != nullptr){//Unless we reach the end, loop through linked list and add all the node values to vector
    vectorStrings.push_back(currPtr->getItem());
    // printf("%s\n", currPtr->getItem().c_str());
    currPtr = currPtr->getNext();
  }
  return vectorStrings;
}  // end toVector
// end of implementation file 