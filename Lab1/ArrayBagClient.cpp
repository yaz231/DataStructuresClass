#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;


void bagTester(ArrayBag<int>& bag);
void printMenu();
void displayBag(ArrayBag<int>& bag);

int main()
{
	ArrayBag<int> bag;
	//Array of random integeres to fill up the bag
	int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8};
	
	int size = sizeof(items)/sizeof(items[0]);
	//Adding elements to the array
	for (int i = 0; i < size; i++)
	{
		bag.add(items[i]);
	}

	while(true){
		int menuNumber;
		printMenu();
		scanf("%d", &menuNumber); //Scanf is used to accept user input to determine menu option
		int index;
		int numberToFind;
		//Switch Statement to Correspond to User Input
		switch(menuNumber){
			case 1:
				printf("Enter the Number to Add:");
				int numberToAdd;
				scanf("%d", &numberToAdd);
				bag.add(numberToAdd);
				break;

			case 2:
				printf("Enter the Number to Delete:");
				int numberToDelete;
				scanf("%d", &numberToDelete);
				bag.remove(numberToDelete);
				break;

			case 3:
				printf("Displaying the Bag:\n");
				displayBag(bag);
				break;

			case 4:
				printf("Sorting the Bag");
				bag.bubbleSort();
				break;

			case 5:
				printf("Enter the Number to Search for using Recursive Binary Search:\n");
				scanf("%d", &numberToFind);
				index = bag.binarySearchRecursive(numberToFind);
				if (index == -1){										
					printf("Couldn't find number in ArrayBag :(\n");
				} else {
					printf("%d found at index: %d\n", numberToFind, index);
				}
				break;

			case 6:
				printf("Enter the Number to Search for using Iterative Binary Search:\n");
				scanf("%d", &numberToFind);
				index = bag.binarySearchIterative(numberToFind);
				if (index == -1){
					printf("Couldn't find number in ArrayBag :(\n");
				} else {
					printf("%d found at index: %d\n", numberToFind, index);
				}
				break;
				
			case 7:
				return 0;
		}
	}
  return 0;
}  // end main


/******************************************************************************/
/* Function:  printMenu
/* Inputs:    NA
/* Outputs:   NA
/* Purpose:   This function prints out the menu listing to display for the user
/*						to choose from
/******************************************************************************/
void printMenu(){
	printf("Welcome to the ArrayBag Testing Menu!\n");
	printf("\n");
	printf("Please select from the folowing menu as our menu options have changed:\n");
	printf("Press 1 to add a number to the ArrayBag\n");
	printf("Press 2 to remove a number from the ArrayBag\n");
	printf("Press 3 to display the ArrayBag's Contents\n");
	printf("Press 4 to sort the contents of the ArrayBag using BubbleSort\n");
	printf("Press 5 to search for an element in the ArrayBag using Recursive Binary Search\n");
	printf("Press 6 to search for an element in the ArrayBag using Iterative Binary Search\n");
	printf("Press 7 to Exit this Program :)\n");
	printf("NOTE: Array should be sorted before searching for an item!!!\n");
	printf("Press ENTER after you've made your selection\n");
}


/******************************************************************************/
/* Function:   displayBag
/* Inputs:     bag, the address to the ArrayBag object
/* Outputs:    NA
/* Purpose:    This function prints out the contents of the ArrayBag
/******************************************************************************/
void displayBag(ArrayBag<int>& bag){
	vector<int> bagItems = bag.toVector();

	//Printing Array Digits
	int numberOfEntries = (int) bagItems.size();
	for (int i = 0; i < numberOfEntries; i ++){
		printf("%d ", bagItems[i]);
	}
	printf("\n");
}

