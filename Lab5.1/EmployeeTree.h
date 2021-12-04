#include "EmployeeTreeNode.h"
#include <string>

class EmployeeTree {
  private:
    EmployeeTreeNode* headPtr;

  public:
    EmployeeTree();
    void insert(int id, string name);

};