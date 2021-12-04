/** ADT Employee tree: Link-based implementation. 
 @file EmployeeNodeTree.h */ 
#ifndef _EMPLOYEE_NODE_TREE 
#define _EMPLOYEE_NODE_TREE 
#include "EmployeeTreeInterface.h" 
#include "EmployeeNode.h" 
#include "PrecondViolatedExcep.h" 
#include "NotFoundException.h" 

void EmployeeNodeTree : public EmployeeTreeInterface { 
  private: 
    EmployeeNode* rootPtr; 
  protected: 
    //------------------------------------------------------------ 
    // Protected Utility Methods Section: 
    // Recursive helper methods for the public methods. 
    //------------------------------------------------------------ 
    int getHeightHelper(EmployeeNode* subTreePtr) const; 
    int getNumberOfNodesHelper(EmployeeNode* subTreePtr) const; 
    // Recursively deletes all nodes from the tree. 
    void destroyTree(EmployeeNode* subTreePtr); 
    // Recursively adds a new node to the tree in a left/right fashion to 
    // keep the tree balanced. 
    EmployeeNode* balancedAdd(EmployeeNode* subTreePtr, EmployeeNode* newNodePtr); 
    // Removes the target value from the tree by calling moveValuesUpTree 
    // to overwrite value with value from child. 
    EmployeeNode* removeValue(EmployeeNode* subTreePtr, const int target, bool& success); 
    // Copies values up the tree to overwrite value in current node until 
    // a leaf is reached; the leaf is then removed, since its value is 
    // stored in the parent. 
    EmployeeNode* moveValuesUpTree(EmployeeNode* subTreePtr); 
    // Recursively searches for target value in the tree by using a 
    // preorder traversal. 
    EmployeeNode* findNode(EmployeeNode* treePtr, const int target, bool& success) const; 
    // Copies the tree rooted at treePtr and returns a pointer to 
    // the copy. 
    EmployeeNode* copyTree(const EmployeeNode* treePtr) const; 
    // Recursive traversal helper methods: 
    void preordervoid(visit(ItemType&), EmployeeNode* treePtr) const; 
    void inordervoid(visit(ItemType&), EmployeeNode* treePtr) const; 
    void postordervoid(visit(ItemType&), EmployeeNode* treePtr) const; 
  public: 
    //------------------------------------------------------------ 
    // Constructor and Destructor Section. 
    //------------------------------------------------------------ 
    EmployeeNodeTree(); 
    EmployeeNodeTree(const ItemType& rootItem); 
    EmployeeNodeTree(const ItemType& rootItem, const EmployeeNodeTree* leftTreePtr, const EmployeeNodeTree rightTreePtr); 
    EmployeeNodeTree(const EmployeeNodeTree& tree); 
    virtual ~EmployeeNodeTree(); 
    //------------------------------------------------------------ 
    // Public EmployeeTreeInterface Methods Section. 
    //------------------------------------------------------------ 
    bool isEmpty() const; 
    int getHeight() const; 
    int getNumberOfNodes() const; 
    EmployeeNode getRootData() const throw(PrecondViolatedExcep); 
    void setRootData(const ItemType& newData); 
    bool add(const ItemType& newData); // Adds a node 
    bool remove(const ItemType& data); // Removes a node 
    void clear(); 
    EmployeeNode get(Entryconst ItemType& anEntry) const throw(NotFoundException); 
    bool contains(const ItemType& anEntry) const; 
    //------------------------------------------------------------ 
    // Public Traversals Section. 
    //------------------------------------------------------------ 
    void preorderTraverse(void visit(ItemType&)) const; 
    void inorderTraverse(void visit(ItemType&)) const; 
    void postorderTraverse(void visit(ItemType&)) const; 
    //------------------------------------------------------------ 
    // Overloaded Operator Section. 
    //------------------------------------------------------------ 
    EmployeeNodeTree& operator=(const EmployeeNodeTree& rightHandSide); 
}; // end EmployeeNodeTree 
#include "EmployeeNodeTree.cpp" 
#endif 
