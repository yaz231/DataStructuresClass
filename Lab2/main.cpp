#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedStack.h"

using namespace std;

int main(){
  bool firstItem = true;
  string itemName;
  printf("Please enter a file name: ");
  string fileName;
  cin >> fileName;
  cout << "Filename: " << fileName << endl;
	
  LinkedStack<int> link; //Initialize Stack
  fstream fin(fileName);
  string line;
  while(getline(fin, line)){
    if (firstItem){
      firstItem = false;
      cout << line << '\n';
      itemName = line;
      // printf("%s",itemName);
      continue;
    }
    int bid;

    stringstream(line) >> bid;
    printf("%d\n", bid);
    if (link.isEmpty()){ //Beginning of the text file always pushed to stack
      link.push(bid); 
    } else {
      if (bid > link.peek()) link.push(bid); //If top of stack is less than new line entry, push to stack
      // printf("%d\n", bid);
    }
  }
  // printf("DONE\n");
  //Verify contents of stack after traversing through file.
  // while(!link.isEmpty()){
  //   printf("%d\n", link.peek());
  //   link.pop();
  // }

  // printf("Final Bid: %d for %s\n", link.peek(), itemName);//Final Bid is the last entry pushed to stack
  cout << "Final Bid: " << link.peek() << " for " << itemName << endl;
  return 0;
}  // end main
