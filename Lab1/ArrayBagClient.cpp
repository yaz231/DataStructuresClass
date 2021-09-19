#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;


void bagTester(ArrayBag<int>& bag);

int main()
{
	// This is one way you can get values in the bag. 
	// You could also read the values from a file.
	// You pick - but you should load up the bag with values.
	ArrayBag<int> bag;
	int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
		
	cout << "Adding positive integers to the bag: " << endl;
	for (int i = 0; i < 20; i++)
	{
		bag.add(items[i]);
	}  // end for

	vector<int> bagItems = bag.toVector();
	printf("Array before it's sorted:\n");

	//Printing Array Digits
	int numberOfEntries = (int) bagItems.size();
	for (int i = 0; i < numberOfEntries; i ++){
		printf("%d ", bagItems[i]);
	}
	bag.bubbleSort();

	bagItems = bag.toVector();

	//Printing digits
	// int numberOfEntries = (int) bagItems.size();
	printf("Array after it's Sorted: \n");
	for (int i = 0; i < numberOfEntries; i ++){
		printf("%d ", bagItems[i]);
	}
	printf("\n");
	int numberToFind;
	printf("Enter a number to search: \n");
	scanf("%d", &numberToFind);
	printf("\n");
	int index = bag.binarySearchRecursive(numberToFind);
	if (index == -1){
		printf("Couldn't find number in ArrayBag :(");
	} else {
		printf("%d found at index: %d", numberToFind, index);
	}
  return 0;
}  // end main


void bagTester(ArrayBag<int>& bag)
{
	// This is just some sample code processing the bag.
	// You should remove this function from your program completely.
	cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

	cout << "About to clear the bag, ";
	bag.clear();
   
	cout << "isEmpty: returns " << bag.isEmpty() << endl;
}  // end bagTester


