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
  // cout << "Filename: " << fileName << endl;
	
  LinkedStack<int> link; //Initialize Stack
  fstream fin(fileName);
  
  //If file doesn't exist, exit program
  fin.open(fileName);
  if (fin.fail()){
    printf("Error: File not found!\n");
    printf("Exiting Program\n");
    exit;
  }
  
  string line;
  while(getline(fin, line)){
    if (firstItem){//Skip the first item in the file, because that's the name of the auctioned item
      firstItem = false;
      // cout << line << '\n'; 
      itemName = line;
      continue;
    }
    int bid;

    stringstream(line) >> bid;
    // printf("%d\n", bid);
    if (link.isEmpty()){ //Beginning of the text file always pushed to stack
      link.push(bid); 
    } else {
      if (bid > link.peek()) link.push(bid); //If top of stack is less than new line entry, push to stack
    }
  }
  // printf("DONE\n");
  //Verify contents of stack after traversing through file.
  // while(!link.isEmpty()){
  //   printf("%d\n", link.peek());
  //   link.pop();
  // }

  cout << "Final Bid: " << link.peek() << " for " << itemName << endl;//Find the final bid by peeking at top of stack
  return 0;
}  // end main
