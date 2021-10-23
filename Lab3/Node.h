/** @file Node.h */ 
#ifndef NODE_H 
#define NODE_H
#include <string>
using namespace std;

class Node 
{ 
private: 
 string line; // A line of text
 Node* next; // Pointer to next node
public: 
  Node(); 
  void setItem(string aString); 
  void setNext(Node* nextNodePtr); 
  string getItem() const ; 
  Node* getNext() const ; 
}; // end Node 
#include "Node.cpp" 
#endif