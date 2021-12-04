#include "EmployeeTreeNode.h"
#include <string>

EmployeeTreeNode::EmployeeTreeNode(){
  myEmployeeName = "";
  myEmployeeID = 0;
  myLeftPtr = nullptr;
  myRightPtr = nullptr;
}

EmployeeTreeNode::EmployeeTreeNode(int employeeID, string employeeName){
  myEmployeeName = employeeName;
  myEmployeeID = employeeID;
  myLeftPtr = nullptr;
  myRightPtr = nullptr;
}

EmployeeTreeNode::EmployeeTreeNode(int employeeID, string employeeName, EmployeeTreeNode* left, EmployeeTreeNode* right){
  myEmployeeName = employeeName;
  myEmployeeID = employeeID;
  myLeftPtr = left;
  myRightPtr = right;
}

int EmployeeTreeNode::getID(){
  return myEmployeeID;
}

string EmployeeTreeNode::getName(){
  return myEmployeeName;
}

EmployeeTreeNode* EmployeeTreeNode::getLeft(){
  return myLeftPtr;
}

EmployeeTreeNode* EmployeeTreeNode::getRight(){
  return myRightPtr;
}

void EmployeeTreeNode::setLeft(EmployeeTreeNode* left){
  myLeftPtr = left;
}

void EmployeeTreeNode::setRight(EmployeeTreeNode* right){
  myRightPtr = right;
}