/** ADT Array: Link-based implementation.
 @file LinkedList.h */ 
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h" 
#include <string>
#include <vector>
using namespace std;
 
class LinkedList{ 
  private:
    Node* headPtr; // Pointer to first node in the chain; 
    int numItems;
  public:
    // Constructors and destructor: 
    LinkedList(); // Default constructor  
    // Array operations: 
    int getLength();
    void addNode(string aString);
    vector<string> toVector() const;
}; // end LinkedList 
#include "LinkedList.cpp" 
#endif
