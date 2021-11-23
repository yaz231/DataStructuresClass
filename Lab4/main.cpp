#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include "QueueInterface.h"

using namespace std;

/******************************************************************************/
/* Function:  printMenu
/* Inputs:    NA
/* Outputs:   NA
/* Purpose:   This function prints out the menu listing to display for the user
/*						to choose from
/******************************************************************************/
void printMenu(){
	printf("Welcome to the Queue Testing Menu!\n");
	printf("\n");
	printf("Please select from the folowing menu as our menu options have changed:\n");
	printf("Press 1 to create an INTEGER Queue\n");
	printf("Press 2 to create a FLOAT Queue\n");
	printf("Press 3 to create a STRING Queue\n");
	printf("Press anything else to Exit this Program :)\n");
	printf("Press ENTER after you've made your selection\n");
}

/******************************************************************************/
/* Function:  printQueueMenu
/* Inputs:    NA
/* Outputs:   NA
/* Purpose:   This function prints out the menu listing to display for the user
/*						to choose from after they decide which datatype to use for the Queue
/******************************************************************************/
void printQueueMenu(){
	printf("Welcome to the Queue Testing Menu!\n");
	printf("\n");
	printf("Please select from the folowing menu as our menu options have changed:\n");
	printf("Press 1 to add to the Queue\n");
	printf("Press 2 to remove from the Queue\n");
	printf("Press 3 to display the Queue's current contents\n");
	printf("Press 4 to Clear the Queue\n");
  printf("Press 5 to Exit this Program :)\n");
	printf("Press ENTER after you've made your selection\n");
}

int main() {
  int menuNumber = 0;
	printMenu();
	scanf("%d", &menuNumber); //Scanf is used to accept user input to determine menu 
	// if (menuNumber == 1) {
	// 	// Queue<int> q(10);
	// 	Queue<int> intq(10);
	// } else if (menuNumber == 2) {
	// 	// Queue<float> q(10);
	// 	Queue<float> floatq(10);
	// } else if (menuNumber == 3) {
	// 	// Queue<string> q(10);
	// 	Queue<string> stringq(10);
	// } else 
	// 	return 0;
	Queue<int> intq(10);
	Queue<float> floatq(10);
	Queue<string> stringq(10);

	int queueMenuNumber;
	printQueueMenu();
	scanf("%d", &queueMenuNumber); 
	while(queueMenuNumber != 5){
		//Switch Statement to Correspond to User Input
		switch(queueMenuNumber){
			case 1: 																											//INTEGER QUEUE
				printf("Enter the item to Add:");
				switch (menuNumber){
					case 1:
						int numberToAdd;
						scanf("%d", &numberToAdd);
						intq.enqueue(numberToAdd);
						break;

        	case 2:
						float floatToAdd;
						scanf("%f", &floatToAdd);
						floatq.enqueue(floatToAdd);
						break;

        	case 3:
						string stringToAdd;
						cin >> stringToAdd;
						stringq.enqueue(stringToAdd);
						break;
        }
				break;

			case 2: 																											//FLOAT QUEUE
				printf("Removing first Item from the Queue:");
				switch (menuNumber){
					case 1:{
						int numberRemoved = 0;
						intq.dequeue(numberRemoved);
						printf("Item removed: %d", numberRemoved);
						break;
					}

        	case 2:{
						float floatRemoved = 0.0;
						floatq.dequeue(floatRemoved);
						printf("Item removed: %d", floatRemoved);
						break;
					}

        	case 3:{
						string stringRemoved = "";
						stringq.dequeue(stringRemoved);
						printf("Item removed: %s", stringRemoved);
						break;
					}

        }
				break;

			case 3:																													//STRING QUEUE
				printf("Displaying the Queue:\n");
				switch (menuNumber){
					case 1:{
						vector<int> vec = intq.toVector();
						printf("Queue: ");
						for (int i = 0; i < vec.size(); i ++){
							printf("%d ", vec[i]);
						}
						printf("\n");
						break;
					}

					case 2:{
						vector<float> vec = floatq.toVector();
						printf("Queue: ");
						for (int i = 0; i < vec.size(); i ++){
							printf("%f ", vec[i]);
						}
						printf("\n");
						break;
					}

					case 3:{
						vector<string> vec = stringq.toVector();
						printf("Queue: ");
						for (int i = 0; i < vec.size(); i ++){
							printf("%s ", vec[i].c_str());
						}
						printf("\n");
						break;
					}

				}
				break;


			case 4:
				return 0;
		}
			printQueueMenu();
			scanf("%d", &queueMenuNumber); //Scanf is used to accept 
	}
  return 0;
}  // end main