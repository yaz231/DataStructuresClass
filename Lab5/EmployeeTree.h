/** ADT Employee tree: Link-based implementation. 
 @file EmployeeTree.h */ 
#ifndef _EMPLOYEE_TREE 
#define _EMPLOYEE_TREE 
#include "EmployeeNode.h" 
#include <string>

class EmployeeTree { 
  private:
    EmployeeNode* headPtr;
    EmployeeNode* removeValue(EmployeeNode* rootPtr, int id, bool& success);
    EmployeeNode* removeNode(EmployeeNode* rootPtr);
    EmployeeNode* removeLeftMostNode(EmployeeNode* rootPtr, int& inorderSuccesssor);
    bool contains_helper(EmployeeNode* rootPtr, int id);

  public:
    EmployeeTree();
    void addSorted(int id, string name);
    bool remove(int id);
    bool hasOneChild(EmployeeNode* rootPtr);
    void printInorder(EmployeeNode* rootPtr);
    EmployeeNode* getRoot();
    void contains(int id);
    int getHeight(EmployeeNode* rootPtr);
    void printLevelOrder(EmployeeNode* rootPtr, int depth);
    string printLevel(EmployeeNode* rootPtr, int level, string gap);

}; // end EmployeeNodeTree 
#include "EmployeeTree.cpp" 
#endif 
