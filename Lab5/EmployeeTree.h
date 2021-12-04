/** ADT Employee tree: Link-based implementation. 
 @file EmployeeTree.h */ 
#ifndef _EMPLOYEE_TREE 
#define _EMPLOYEE_TREE 
#include "EmployeeNode.h" 
#include <string>

class EmployeeTree { 
  private:
    EmployeeNode* headPtr;

  public:
    EmployeeTree();
    void insertSorted(int id, string name);
    void inorder(EmployeeNode* rootPtr);
    EmployeeNode* getRoot();



}; // end EmployeeNodeTree 
#include "EmployeeTree.cpp" 
#endif 
