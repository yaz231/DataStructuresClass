/** @file Node.h */ 
#ifndef _NODE 
#define _NODE 
#include <string>
using namespace std;

template< class ItemType> 
class Node 
{ 
private: 
 string line; // A line of text
 Node<ItemType>* next; // Pointer to next node
public: 
  Node(); 
  void setItem(string aString); 
  void setNext(Node<ItemType>* nextNodePtr); 
  string getItem() const ; 
  Node<ItemType>* getNext() const ; 
}; // end Node 
#include "Node.cpp" 
#endif