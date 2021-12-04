#include "EmployeeTree.h"
#include <string>

EmployeeTree::EmployeeTree(){
  headPtr = nullptr;
}

void EmployeeTree::insert(int id, string name){
  if (headPtr == nullptr){
    headPtr = new EmployeeTreeNode(id, name);
  } else {
    EmployeeTreeNode* currPtr = headPtr;
    while(currPtr != nullptr){
      if (id < currPtr->getID()){
        if (currPtr->getLeft() == nullptr){
          currPtr->setLeft(new EmployeeTreeNode(id, name));
          break;
        } else {
          currPtr = currPtr->getLeft();
        }
      } else if (id > currPtr->getID()){
        if (currPtr->getRight() == nullptr){
          currPtr->setRight(new EmployeeTreeNode(id, name));
          break;
        } else {
          currPtr = currPtr->getRight();
        }
      } else {
        break;
      }
    }
  }
}