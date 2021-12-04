#include "EmployeeNode.h"
#include "EmployeeTree.h"
#include <string>

int main(){
    EmployeeTree tree;

    tree.addSorted(5, "Hello");
    tree.addSorted(10, "Bye");
    tree.addSorted(3, "GAYWAD");
    tree.addSorted(1, "SDFVSD");
    tree.addSorted(8, "asdfsdf");
    tree.addSorted(2, "Gsdfasdf");
    
    // printf("Height of Tree: %d\n", tree.getHeight(tree.getRoot()));
    tree.printLevelOrder(tree.getRoot(), tree.getHeight(tree.getRoot()));
    tree.remove(5);
    printf("\n");
    tree.printLevelOrder(tree.getRoot(), tree.getHeight(tree.getRoot()));
    // tree.display();
    // tree.inorder(tree.getRoot());
    // printf("\n");
    // // tree.contains(5);

    // tree.contains(0);

    
    return 0;
}