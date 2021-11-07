#include <iostream>
using namespace std;

class Node {
  private:
    int item;
    Node* next;
  
  public:
    Node();
    int getItem();
    Node* getNext();
    void setItem(int);
    void setNext(Node*);
};

Node::Node(){
  item = 0;
  next = nullptr;
}

int Node::getItem(){
  return item;
}

Node* Node::getNext(){
  return next;
}

void Node::setItem(int num){
  item = num;
}

void Node::setNext(Node* nextPtr){
  next = nextPtr;
}

class SortedLinkedList{
  private:
    Node* headPtr;
    int itemCount;
    Node* getPrevPtr(int value);

  public:
    SortedLinkedList();
    void addItem(int numToAdd);
    void displayList();
    bool isEmpty();
};

SortedLinkedList::SortedLinkedList(){
  headPtr = nullptr;
  itemCount = 0;
}

void SortedLinkedList::addItem(int numToAdd){
  Node* newNode = new Node();
  newNode->setItem(numToAdd);
  newNode->setNext(nullptr);
  Node* prevPtr;

  if (!headPtr){
    headPtr = newNode;
  } else if (headPtr->getItem() >= numToAdd){
    newNode->setNext(headPtr);
    headPtr = newNode;
  } else {
    prevPtr = getPrevPtr(numToAdd);
    newNode->setNext(prevPtr->getNext());
    prevPtr->setNext(newNode);
  }
  itemCount ++;
}

Node* SortedLinkedList::getPrevPtr(int value){
  Node* prevPtr = headPtr;
  while (prevPtr->getNext() && (prevPtr->getNext()->getItem() <= value)){
    prevPtr = prevPtr->getNext();
  }
  return prevPtr;
}

void SortedLinkedList::displayList(){
  Node* currPtr = headPtr;
  while (currPtr){
    cout << currPtr->getItem() << endl;
    currPtr = currPtr->getNext();
  }
}

bool SortedLinkedList::isEmpty(){
  return itemCount == 0;
}

int main(){
  SortedLinkedList LL;
  LL.addItem(4);
  LL.displayList();
  cout << endl;
  LL.addItem(2);
  LL.addItem(9);
  LL.addItem(1);
  LL.addItem(5);
  LL.displayList();
  cout << endl;

  return 0;
}