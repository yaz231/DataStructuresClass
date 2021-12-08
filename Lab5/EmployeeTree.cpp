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

//Function to add New Employee to the Binary Tree
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

//Function to Remove Nodes from the SubTree
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
    } else {                                           //2 Children
      EmployeeNode* tempPtr = findMin(rootPtr->getRightChildPtr());
      rootPtr->setID(tempPtr->getID());
      rootPtr->setName(tempPtr->getName());
      rootPtr->setRightChildPtr(remove(rootPtr->getRightChildPtr(), tempPtr->getID()));
    }
  }
  return rootPtr;
}

//Auxilary Function to Find the minimum element in a subtree.
EmployeeNode* EmployeeTree::findMin(EmployeeNode* rootPtr){
  EmployeeNode* currPtr = rootPtr;
  while (currPtr->getLeftChildPtr() != nullptr){
    currPtr = currPtr->getLeftChildPtr();
  }
  return currPtr;
}

//Function to Check if Node has Only 1 child.
bool EmployeeTree::hasOneChild(EmployeeNode* rootPtr){
  if ((rootPtr->getRightChildPtr() == nullptr) != (rootPtr->getLeftChildPtr() == nullptr)){
    return true;
  } else
    return false;
}

//Function to print ID's in Binary Tree in order
void EmployeeTree::printInorder(EmployeeNode* rootPtr){
    if (rootPtr == NULL)
        return;
    else {
        printInorder(rootPtr->getLeftChildPtr());
        printf("%d:%s  ", rootPtr->getID(), rootPtr->getName().c_str());
        printInorder(rootPtr->getRightChildPtr());
    }
}

//Function to return the Root of the Tree
EmployeeNode* EmployeeTree::getRoot(){
  return headPtr;
}

//Function to return whether or not id was found in the Binary Tree
bool EmployeeTree::contains(EmployeeNode* rootPtr, int id){
  EmployeeNode* currPtr = rootPtr;

  if(currPtr->getID() == id){
    return true;
  } else if (currPtr->getLeftChildPtr() == nullptr & currPtr->getRightChildPtr() == nullptr){
    return false;
  } else {
    //if the ID of the node is less than the current node, recursively search the left subtree, otherwise recursively search the right subtree
    currPtr = (id < currPtr->getID()) ? (currPtr->getLeftChildPtr()) : (currPtr->getRightChildPtr());
    return contains(currPtr, id);
    // return contains(currPtr->getLeftChildPtr(), id) || contains(currPtr->getRightChildPtr(), id);
  }
}

//Auxilary Function used for Displaying the Binary Tree
//Finds the Height of the Binary Tree
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

//Function that prints every Line of the Binary Tree
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

//Function that recursively searches and generates strings for print function above
string EmployeeTree::printLevel(EmployeeNode* rootPtr, int level, string gap){
  if (level == 1) {
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