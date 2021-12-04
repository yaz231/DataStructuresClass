#ifndef _EMPLOYEE_NODE 
#define _EMPLOYEE_NODE 
#include <string>
using namespace std;

class EmployeeNode { 
  private: 
    string myEmployeeName; // Data portion
    int myEmployeeID; 
    EmployeeNode* leftChildPtr; // Pointer to left child 
    EmployeeNode* rightChildPtr; // Pointer to right child 
  public: 
    EmployeeNode(); 
    EmployeeNode(const int employeeID, const string employeeName); 
    EmployeeNode(const int employeeID, const string employeeName, EmployeeNode* leftPtr, EmployeeNode* rightPtr); 
    void setName(const string employeeName); 
    void setID(const int employeeID); 
    int getID() const; 
    string getName() const; 
    bool isLeaf() const; 
    EmployeeNode* getLeftChildPtr() const; 
    EmployeeNode* getRightChildPtr() const; 
    void setLeftChildPtr(EmployeeNode* leftPtr); 
    void setRightChildPtr(EmployeeNode* rightPtr); 
}; // end EmployeeNode 
#include "EmployeeNode.cpp" 
#endif 
