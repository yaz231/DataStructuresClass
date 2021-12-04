/** @file EmployeeNodeTree.cpp */
#include "EmployeeTree.h" //Header File
#include "EmployeeNode.h"
#include <math.h>
#include <cassert> //For assert
#include <sstream>
#include <iostream>
#include <string>

EmployeeTree::EmployeeTree(){
  headPtr = nullptr;
}

void EmployeeTree::addSorted(int id, string name){
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

// bool EmployeeTree::remove(int id){
//   bool success = false;
//   headPtr = removeValue(headPtr, id, success);
//   return success;
// }

// EmployeeNode* EmployeeTree::removeValue(EmployeeNode* rootPtr, int id, bool& success){ 
//   if (rootPtr == nullptr) {
//     success = false;
//     return nullptr;
//   } else if (rootPtr->getID() == id){ 
//     // Item is in the root of some subtree 
//     rootPtr = removeNode(rootPtr); // Remove the item 
//     success = true;
//     return rootPtr;
//   } else if (rootPtr->getID() > id) { 
//     // Search the left subtree 
//     EmployeeNode* tempPtr = removeValue(rootPtr->getLeftChildPtr(), id, success);
//     rootPtr->setLeftChildPtr(tempPtr);
//     return rootPtr;
//   } else {
//     // Search the right subtree 
//     EmployeeNode* tempPtr = removeValue(rootPtr->getRightChildPtr(), id, success); 
//     rootPtr->setRightChildPtr(tempPtr); 
//     return rootPtr;
//   }
//  }

// EmployeeNode* EmployeeTree::removeLeftMostNode(EmployeeNode* rootPtr, int& inorderSuccesssor){ 
//   if (rootPtr->getLeftChildPtr() == nullptr){
//     inorderSuccesssor = rootPtr->getID(); 
//     return removeNode(rootPtr);
//   } else
//     return removeLeftMostNode(rootPtr->getLeftChildPtr(), inorderSuccesssor);
// }

// EmployeeNode* EmployeeTree::removeNode(EmployeeNode* rootPtr){
//   if (rootPtr->isLeaf()) {
//     delete rootPtr;
//     rootPtr = nullptr;
//     return rootPtr;
//   } else if (hasOneChild(rootPtr)){
//     EmployeeNode* nodeToConnectPtr;
//     if (rootPtr->getLeftChildPtr() != nullptr)
//       nodeToConnectPtr = rootPtr->getLeftChildPtr();
//     else 
//       nodeToConnectPtr = rootPtr->getRightChildPtr(); 
//     delete rootPtr;
//     rootPtr = nullptr;
//     return nodeToConnectPtr;
//   } else {
//       // int newNodeValue = rootPtr->getRightChildPtr()->getID();
//       int newNodeValue;
//       EmployeeNode* tempPtr = removeLeftMostNode(rootPtr->getRightChildPtr(), newNodeValue);
//       rootPtr->setRightChildPtr(tempPtr);
//       rootPtr->setID(newNodeValue);
//       return rootPtr;
//   }
// }

EmployeeNode* EmployeeTree::remove(EmployeeNode* rootPtr, int id){
  if (rootPtr == nullptr) return rootPtr;
  else if(id < rootPtr->getID()) 
    rootPtr->setLeftChildPtr(remove(rootPtr->getLeftChildPtr(), id));
  else if(id > rootPtr->getID())
    rootPtr->setRightChildPtr(remove(rootPtr->getRightChildPtr(), id));
  else {
    //Case 1: No Child
    if (rootPtr->getLeftChildPtr() == nullptr && rootPtr->getRightChildPtr() == nullptr){
      delete rootPtr;
      rootPtr = nullptr;
    } else if (rootPtr->getLeftChildPtr() == nullptr){//One Child
      EmployeeNode* tempPtr = rootPtr;
      rootPtr = rootPtr->getRightChildPtr();
      delete tempPtr;
    } else if (rootPtr->getRightChildPtr() == nullptr){//One Child
      EmployeeNode* tempPtr = rootPtr;
      rootPtr = rootPtr->getLeftChildPtr();
      delete tempPtr;
    } else {//2 Children
      EmployeeNode* tempPtr = findMin(rootPtr->getRightChildPtr());
      rootPtr->setID(tempPtr->getID());
      rootPtr->setName(tempPtr->getName());
      rootPtr->setRightChildPtr(remove(rootPtr->getRightChildPtr(), tempPtr->getID()));
    }
  }
  return rootPtr;
}

EmployeeNode* EmployeeTree::findMin(EmployeeNode* rootPtr){
  EmployeeNode* currPtr = rootPtr;
  while (currPtr->getLeftChildPtr() != nullptr){
    currPtr = currPtr->getLeftChildPtr();
  }
  return currPtr;
}

bool EmployeeTree::hasOneChild(EmployeeNode* rootPtr){
  if ((rootPtr->getRightChildPtr() == nullptr) != (rootPtr->getLeftChildPtr() == nullptr)){
    return true;
  } else
    return false;
}

void EmployeeTree::printInorder(EmployeeNode* rootPtr){
    if (rootPtr == NULL)
        return;
    else {
        printInorder(rootPtr->getLeftChildPtr());
        printf("%d:%s  ", rootPtr->getID(), rootPtr->getName().c_str());
        printInorder(rootPtr->getRightChildPtr());
    }
}

EmployeeNode* EmployeeTree::getRoot(){
  return headPtr;
}

void EmployeeTree::contains(int id){
  if (contains_helper(headPtr, id)){
    printf("ID:%d FOUND\n", id);
  } else {
    printf("ID:%d NOT FOUND\n", id);
  }
}

bool EmployeeTree::contains_helper(EmployeeNode* rootPtr, int id){
  EmployeeNode* currPtr = rootPtr;

  if(currPtr->getID() == id){
    return true;
  } else if (currPtr == nullptr){
    return false;
  } else {
    currPtr = (id < currPtr->getID()) ? (currPtr->getLeftChildPtr()) : (currPtr->getRightChildPtr());
    return contains_helper(currPtr, id);
  }
}

int EmployeeTree::getHeight(EmployeeNode* rootPtr){
  if (rootPtr == nullptr){
    return 0;
  } else {
    int left_Height = getHeight(rootPtr->getLeftChildPtr());
    int right_Height = getHeight(rootPtr->getRightChildPtr());

    if (left_Height >= right_Height){
      return left_Height + 1;
    } else {
      return right_Height + 1;
    }
  }
}

void EmployeeTree::printLevelOrder(EmployeeNode* rootPtr, int depth){
  for(int i = 1; i <= depth; i++) {
    string gap="";
    for(int j = 0; j < pow(2, depth-i) - 1; j++) {
      gap+=" ";
    }
    string levelNodes = printLevel(rootPtr, i, gap);
    printf(levelNodes.c_str());
    printf("\n");
  }
}

string EmployeeTree::printLevel(EmployeeNode* rootPtr, int level, string gap){
  if (level==1) {
    if (rootPtr == 0) {
     return gap + "-" + gap;
    }
    stringstream out;
    out<<rootPtr->getID();
    return gap + out.str() + gap;
  } else if (level > 1) {
    string leftStr = printLevel(rootPtr ? rootPtr->getLeftChildPtr() : 0, level - 1, gap);
    string rightStr = printLevel(rootPtr ? rootPtr->getRightChildPtr() : 0, level - 1, gap);
    return leftStr + " " + rightStr;
  } else return "";
}