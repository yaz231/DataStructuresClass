#include <iostream>
#include <fstream>
#include <string>
#include "LinkedStack.h"

using namespace std;

int main()
{
  printf("Please enter a file name: \n");
  string fileName;
  scanf("%s", &fileName);
	LinkedStack<int> link;
  ifstream myfile(fileName);
  int bid;
  string myString;
  if (myfile.is_open()){
    char myChar;
    while (myfile){
      myChar = myfile.get();
      cout << myChar;
    }
  }

  return 0;
}  // end main
