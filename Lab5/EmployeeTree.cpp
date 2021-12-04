/** @file EmployeeNodeTree.cpp */
#include "EmployeeTree.h" //Header File
#include "EmployeeNode.h"
#include <cassert> //For assert
#include <string>

EmployeeTree::EmployeeTree(){
  headPtr = nullptr;
}

void EmployeeTree::insertSorted(int id, string name){
  if (headPtr == nullptr){
    headPtr = new EmployeeNode(id, name);
  } else {
    EmployeeNode* currPtr = headPtr;
    while(currPtr != nullptr){
      if (id < currPtr->getID()){
        if (currPtr->getLeftChildPtr() == nullptr){
          currPtr->setLeftChildPtr(new EmployeeNode(id, name));
          break;
        } else {
          currPtr = currPtr->getLeftChildPtr();
        }
      } else if (id > currPtr->getID()){
        if (currPtr->getRightChildPtr() == nullptr){
          currPtr->setRightChildPtr(new EmployeeNode(id, name));
          break;
        } else {
          currPtr = currPtr->getRightChildPtr();
        }
      } else {
        break;
      }
    }
  }
}

void EmployeeTree::inorder(EmployeeNode* rootPtr){
    if (rootPtr == NULL)
        return;
    else {
        inorder(rootPtr->getLeftChildPtr());
        printf("%d : %s  ", rootPtr->getID(), rootPtr->getName().c_str());
        inorder(rootPtr->getRightChildPtr());
    }
}

EmployeeNode* EmployeeTree::getRoot(){
  return headPtr;
}