#include <string>
#include "EmployeeNode.h" //Header File
using namespace std;

EmployeeNode::EmployeeNode(){
    myEmployeeID = 0;
    myEmployeeName = "";
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

EmployeeNode::EmployeeNode(const string employeeName, const int employeeID){
    myEmployeeID = employeeID;
    myEmployeeName = employeeName;
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

EmployeeNode::EmployeeNode(const string employeeName, const int employeeID, EmployeeNode* leftPtr, EmployeeNode* rightPtr){
    myEmployeeID = employeeID;
    myEmployeeName = employeeName;
    leftChildPtr = leftPtr;
    rightChildPtr = rightPtr;
}

void EmployeeNode::setName(const string employeeName){
    myEmployeeName = employeeName;
}

void EmployeeNode::setID(const int employeeID){
    myEmployeeID = employeeID;
}

string EmployeeNode::getName() const{
    return myEmployeeName;
} 

int EmployeeNode::getID() const{
    return myEmployeeID;
} 

bool EmployeeNode::isLeaf() const{
    if ((leftChildPtr == nullptr) && (rightChildPtr == nullptr)){
        return true;   
    }
    return false;
} 

EmployeeNode* EmployeeNode::getLeftChildPtr() const{
    return leftChildPtr;
} 

EmployeeNode* EmployeeNode::getRightChildPtr() const{
    return rightChildPtr;
}

void EmployeeNode::setLeftChildPtr(EmployeeNode* leftPtr){
    leftChildPtr = leftPtr;
} 

void EmployeeNode::setRightChildPtr(EmployeeNode* rightPtr){
    rightChildPtr = rightPtr;
}