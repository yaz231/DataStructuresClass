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
	printf("Press 1 to Add to the Queue\n");
	printf("Press 2 to Remove from the Queue\n");
	printf("Press 3 to Display the Queue's current contents\n");
	printf("Press 4 to Clear the Queue\n");
  printf("Press 5 to Exit this Program :)\n");
	printf("Press ENTER after you've made your selection\n");
}

int main() {
  int menuNumber = 0;
	printMenu();
	scanf("%d", &menuNumber); //Variable to keep track of which datatype to use for Queues
	
	Queue<int> intq(10);		//Initialize Queues for ints, floats, and strings
	Queue<float> floatq(10);
	Queue<string> stringq(10);

	int queueMenuNumber;
	printQueueMenu();
	scanf("%d", &queueMenuNumber); 
	while(queueMenuNumber != 5){
		//Switch Statement to Correspond to User Input
		switch(queueMenuNumber){
			case 1: 																	//ENQUEUE
				printf("Enter the item to Add:");
				switch (menuNumber){
					case 1:																//Enqueue for integer queue
						int numberToAdd;
						scanf("%d", &numberToAdd);
						intq.enqueue(numberToAdd);
						break;

        	case 2:																//Enqueue for float queue
						float floatToAdd;
						scanf("%f", &floatToAdd);
						floatq.enqueue(floatToAdd);
						break;

        	case 3:																//Enqueue for string queue
						string stringToAdd;
						cin >> stringToAdd;
						stringq.enqueue(stringToAdd);
						break;
        }
				break;

			case 2: 																	//DEQUEUE
				printf("Removing first Item from the Queue:\n");
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

			case 3:																		//DISPLAY QUEUE
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


			case 4:																		//CLEAR QUEUE
				printf("Clearing the Queue:\n");
				switch (menuNumber){
					case 1:{
						intq.clear();
						printf("\n");
						break;
					}

					case 2:{
						floatq.clear();
						printf("\n");
						break;
					}

					case 3:{
						stringq.clear();
						printf("\n");
						break;
					}
				}
				break;
		}
			printQueueMenu();
			scanf("%d", &queueMenuNumber); 
	}
  return 0;
}  // end main