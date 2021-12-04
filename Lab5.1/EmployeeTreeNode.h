#include <string>
using namespace std;

class EmployeeTreeNode {
  private:
    int myEmployeeID;
    string myEmployeeName;
    EmployeeTreeNode* myLeftPtr;
    EmployeeTreeNode* myRightPtr;

  public:
    EmployeeTreeNode();
    EmployeeTreeNode(int employeeID, string employeeName);
    EmployeeTreeNode(int employeeID, string employeeName, EmployeeTreeNode* left, EmployeeTreeNode* right);
    int getID();
    string getName();
    EmployeeTreeNode* getLeft();
    EmployeeTreeNode* getRight();
    void setLeft(EmployeeTreeNode*);
    void setRight(EmployeeTreeNode*);

};