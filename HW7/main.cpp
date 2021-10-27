#include "stdio.h"

//Question 3
void display(){
  int ch;
  while (!aStack.isEmpty()){
    ch = aStack.peek();
    printf("%d ", ch);
    aStack.pop();
  }
}

void display(){
  int ch;
  int top;
  while (top >= 0){
    ch = aStack[top];
    printf("%d ", ch);
    top --;
  }
}

void display(){
  int ch;
  Node<ItemType>* currPtr = headPtr;
  while (currPtr->getNext() != nullptr){
    ch = currPtr->getItem();
    printf("%d ", ch);
    currPtr = currPtr->getNext();
  }
}

//Question 6
void remove(int n){
  if (n < top){
    return;
  }
  top -= n;
}

//Question 7
LinkedList::~LinkedList(){
  Node<ItemType> *currPtr = headPtr;
  while (currPtr->getNext != nullptr){
    Node<ItemType> *nextPtr = currPtr->getNext();
    delete currPtr;
    current = nextPtr;
  }
}