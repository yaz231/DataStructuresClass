#include "EmployeeNode.h"
#include "EmployeeTree.h"
#include <iostream>
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>


/******************************************************************************/
/* Function:  printMenu
/* Inputs:    NA
/* Outputs:   NA
/* Purpose:   This function prints out the menu listing to display for the user
/*						to choose from
/******************************************************************************/
void printMenu(){
	printf("Welcome to the Binary Tree Testing Menu!\n");
	printf("\n");
	printf("Please select from the folowing menu as our menu options have changed:\n");
    printf("Press 1 to Read some sample data from a File\n");
	printf("Press 2 to Add to the Employee Binary Tree\n");
    printf("Press 3 to Display the Employee Binary Tree\n");
    printf("Press 4 to Remove an Employee from the Employee Binary Tree\n");
    printf("Press 5 to Exit the Program\n");
	printf("Press ENTER after you've made your selection\n");
    printf("\n");
    printf("NOTE: DISPLAYING WORKS BEST WITH 1 or 2 digit ID's and only displays the ID's of the employee!");
}


int main(){
    EmployeeTree tree; //Initialize Binary Search Tree
    string fileName = "employees.txt";
    string nameToAdd;
    int menuNumber;
    string line;
    int id;
    ifstream file_reader(fileName);
	printMenu();
	scanf("%d", &menuNumber); 
	while(menuNumber != 5){
		//Switch Statement to Correspond to User Input
		switch(menuNumber){
		    case 1: 															
				printf("Reading from Sample 'Employee.txt':\n");
                //If file doesn't exist, exit program
                if (!file_reader.is_open()){
                    printf("Error: File not found!\n");
                    printf("Exiting Program\n");
                    return 1;
                }
                printf("File successfully opened!\n");
                int i;
                string line, name, id;
                printf("READING\n");
                while(getline(file_reader, line)){
                    stringstream ss(line);
                    getline(ss, id, ',');
                    getline(ss, name);
                    int id_int = stoi(id);
                    tree.addSorted(id_int, name);
                }
                printf("%d number of lines in %s\n", i, fileName.c_str());
                printf("FINISHED READING\n");
				break;

			case 2: 																	
				printf("Adding to the Employee Binary Tree:\n");
                int idToAdd;
                printf("Enter in an Employee ID:\n");
                scanf("%d", &idToAdd);
                printf("Enter in an Employee Name:\n");
                scanf("%s", &nameToAdd);
                tree.addSorted(idToAdd, nameToAdd);
				break;

			case 3:																		
				printf("Displaying the Employee Binary Tree:\n");
                tree.printLevelOrder(tree.getRoot(), tree.getHeight(tree.getRoot()));
                printf("\n");
				break;


			case 4:																		
				printf("Removing from the Employee Binary Tree:\n");
                int idToRemove;
                printf("Enter in an Employee ID:\n");
                scanf("%d", &idToRemove);
                tree.remove(tree.getRoot(), idToRemove);
				break;
		}
		printMenu();
	    scanf("%d", &menuNumber); 
	}
  
    //If file doesn't exist, exit program
    if (!file_reader.is_open()){
        printf("Error: File not found!\n");
        printf("Exiting Program\n");
        return 1;
    }
    printf("File successfully opened!\n");
    
    // int i;
    // string line, name, id;
    // printf("READING\n");
    // while(getline(file_reader, line)){
    //     stringstream ss(line);
    //     getline(ss, id, ',');
    //     getline(ss, name);
    //     int id_int = stoi(id);
    //     tree.addSorted(id_int, name);
    // }
    // printf("%d number of lines in %s\n", i, fileName.c_str());
    // printf("FINISHED READING\n");
    // EmployeeTree tree;

    // tree.addSorted(5, "Hello");
    // tree.addSorted(10, "Bye");
    // tree.addSorted(3, "GAYWAD");
    // tree.addSorted(1, "SDFVSD");
    // tree.addSorted(8, "asdfsdf");
    // tree.addSorted(2, "Gsdfasdf");
    // tree.addSorted(11, "DSfgsdf");
    // tree.addSorted(5, "TROUBLE");
    // tree.printInorder(tree.getRoot());
    // printf("\n");
    
    // printf("Height of Tree: %d\n", tree.getHeight(tree.getRoot()));
    // tree.printLevelOrder(tree.getRoot(), tree.getHeight(tree.getRoot()));
    // printf("\n");
    // tree.remove(tree.getRoot(), 5);
    // tree.printLevelOrder(tree.getRoot(), tree.getHeight(tree.getRoot()));
// 
    
    return 0;
}