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
	scanf("%d", &menuNumber); //Scanf is used to accept user input to determine menu option
	if (menuNumber == 1) {
		Queue<int> q(10);
	} else if (menuNumber == 2) {
		Queue<float> q(10);
	} else if (menuNumber == 3) {
		Queue<string> q(10);
	} else 
		return 0;
	while(true){
		int queueMenuNumber;
		printQueueMenu();
		scanf("%d", &queueMenuNumber); //Scanf is used to accept user input to determine menu option
		//Switch Statement to Correspond to User Input
		switch(queueMenuNumber){
			case 1:
				printf("Enter the item to Add:");
                if (menuNumber == 1){
                    int numberToAdd;
				    scanf("%d", &numberToAdd);
				    q.enqueue(numberToAdd);
                } else if (menuNumber == 2) {
                    float floatToAdd;
				    scanf("%f", &floatToAdd);
				    q.enqueue(floatToAdd);
                } else if (menuNumber == 3) {
                    string stringToAdd;
				    cin >> stringToAdd;
				    q.enqueue(stringToAdd);
                }
				break;

			case 2:
				printf("Removing first Item from the Queue:");
                if (menuNumber == 1){
                    int numberRemoved = 0;
				    				q.dequeue(numberRemoved);
                    printf("Item removed: %d", numberRemoved);
                } else if (menuNumber == 2) {
                    float floatRemoved;
				    				q.dequeue(floatRemoved);
                    printf("Item removed: %d", floatRemoved);
                } else if (menuNumber == 3) {
                    string stringRemoved;
				    				q.dequeue(stringRemoved);
                    printf("Item removed: %s", stringRemoved);
                }
				break;

			case 3:
				printf("Displaying the Queue:\n");
				if (menuNumber == 1){
					vector<int> vec = q.toVector();
					for (int i = 0; i < vec.size(); i ++){
						printf("Queue: %d\n", vec[i]);
					}
				} else if (menuNumber == 2){
					vector<float> vec = q.toVector();
					for (int i = 0; i < vec.size(); i ++){
						printf("Queue: %f\n", vec[i]);
					}
				} else if (menuNumber == 3){
					vector<string> vec = q.toVector();
					for (int i = 0; i < vec.size(); i ++){
						printf("Queue: %s\n", vec[i].c_str());
					}
				}
				break;

			case 4:
				return 0;
		}
	}
  return 0;
}  // end main