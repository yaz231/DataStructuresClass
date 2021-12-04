#include "EmployeeNode.h"
#include "EmployeeTree.h"
#include <string>

int main(){
    EmployeeTree tree;

    tree.insertSorted(5, "Hello");
    tree.insertSorted(10, "Bye");
    tree.insertSorted(3, "GAYWAD");
    
    tree.inorder(tree.getRoot());

    
    return 0;
}