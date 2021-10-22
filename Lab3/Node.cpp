/** @file Node.cpp */ 
#include "Node.h" 
#include <cstddef> 
#include <string>
using namespace std;

template< class ItemType> 
Node<ItemType>::Node() : next( nullptr), line("")
{ 
} // end default constructor 
template< class ItemType> 
void Node<ItemType>::setItem(string aString) 
{ 
 line = aString; 
} // end setItem 
template< class ItemType> 
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) 
{
 next = nextNodePtr; 
} // end setNext 
template< class ItemType> 
string Node<ItemType>::getItem() const
{ 
 return line; 
} // end getItem 
template< class ItemType> 
Node<ItemType>* Node<ItemType>::getNext() const
{ 
 return next; 
} // end getNext