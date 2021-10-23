/** @file Node.cpp */ 
#include "Node.h" 
#include <cstddef> 
#include <string>
using namespace std;
 
Node::Node()
{ 
  next = nullptr;
  line = "";
} // end default constructor 

void Node::setItem(string aString) 
{ 
 line = aString; 
} // end setItem 
 
void Node::setNext(Node* nextNodePtr) 
{
 next = nextNodePtr; 
} // end setNext 

string Node::getItem() const
{ 
 return line; 
} // end getItem 

Node* Node::getNext() const
{ 
 return next; 
} // end getNext