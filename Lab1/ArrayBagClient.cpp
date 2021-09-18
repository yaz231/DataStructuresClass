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
	printf("It's done\n");
	// You will remove this sample funciton from your program
	// bagTester(bag);
	bag.bubbleSort();

	vector<int> bagItems = bag.toVector();
	int numberOfEntries = (int) bagItems.size();
	for (int i = 0; i < numberOfEntries; i ++){
		printf("%d ", bagItems[i]);
	}
	printf("\n");
	printf("It's actually done");
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


