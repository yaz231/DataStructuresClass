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
    printf("Press 1 to Read some sample Employee data from a File\n");
	printf("Press 2 to Add to the Employee Binary Tree\n");
    printf("Press 3 to Display the Employee Binary Tree\n");
    printf("Press 4 to Remove an Employee from the Employee Binary Tree\n");
    printf("Press 5 to Search if an Employee exists in the Employee Binary Tree\n");
    printf("Press 6 to Exit the Program\n");
    printf("\n");
    printf("NOTE: Displaying Works BEST With 1 or 2 digit ID's and only displays the ID's of the employee!\n");
    printf("\n");
	printf("Press ENTER after you've made your selection:");
    printf("\n");

}


int main(){
    EmployeeTree tree; //Initialize Binary Search Tree
    string fileName = "employees.txt";
    string nameToAdd;
    bool isFound;
    int menuNumber;
    string line, name, id;
    ifstream file_reader(fileName);
	printMenu();
	scanf("%d", &menuNumber); 
	while(menuNumber != 6){
		//Switch Statement to Correspond to User Input
		switch(menuNumber){
		    case 1: //Read from Sample File														
				printf("Reading from Sample 'Employee.txt' File:\n");
                //If file doesn't exist, exit program
                if (!file_reader.is_open()){
                    printf("Error: File not found!\n");
                    printf("Exiting Program\n");
                    return 1;
                }
                printf("File successfully opened!\n");
                printf("READING\n");
                while(getline(file_reader, line)){
                    stringstream ss(line);
                    getline(ss, id, ',');
                    getline(ss, name);
                    int id_int = stoi(id);
                    tree.addSorted(id_int, name);
                }
                printf("FINISHED READING\n");
				break;

			case 2: //Add to Binary Tree																	
				printf("Adding to the Employee Binary Tree:\n");
                int idToAdd;
                printf("Enter in an Employee ID:\n");
                scanf("%d", &idToAdd);
                printf("Enter in an Employee Name:\n");
                scanf("%s", &nameToAdd);
                tree.addSorted(idToAdd, nameToAdd);
				break;

			case 3:	//Display Binary Tree																	
				printf("Displaying the Employee Binary Tree:\n");
                tree.printLevelOrder(tree.getRoot(), tree.getHeight(tree.getRoot()));
                printf("\n");
				break;


			case 4: //Remove from Binary Tree																		
				printf("Removing from the Employee Binary Tree:\n");
                int idToRemove;
                printf("Enter in an Employee ID:\n");
                scanf("%d", &idToRemove);
                tree.remove(tree.getRoot(), idToRemove);
				break;
            
            case 5: //Search if Employee is Found in Binary Tree
                printf("Checking if Employee exists in Employee Binary Tree:\n");
                int idToSearch;
                printf("Enter in an Employee ID:\n");
                scanf("%d", &idToSearch);
                isFound = tree.contains(tree.getRoot(), idToSearch);
                if (isFound){
                    printf("ID:%d FOUND\n", idToSearch);
                } else {
                    printf("ID:%d NOT FOUND\n", idToSearch);
                }
				break;
                
		}
		printMenu();
	    scanf("%d", &menuNumber); 
	}
  
    return 0;
}