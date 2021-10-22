/** ADT Array: Link-based implementation.
 @file LinkedList.h */ 
#ifndef _LINKED_LIST 
#define _LINKED_LIST 
#include "Node.h" 
#include <string>
#include <vector>
using namespace std;
template< class ItemType> 
class LinkedList
{ 
private:
Node<ItemType>* headPtr; // Pointer to first node in the chain; 
int numItems;
public:
// Constructors and destructor: 
  LinkedList(); // Default constructor  
  // Array operations: 
  int getLength() const;
  void addNode(string aString);
  vector<string> toVector() const;
}; // end LinkedList 
#include "LinkedList.cpp" 
#endif 
