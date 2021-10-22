#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(){
  bool firstItem = true;
  // Node<string>* headPtr;
  string stringName;
  printf("Please enter a file name: ");
  string fileName;
  cin >> fileName;
  // cout << "Filename: " << fileName << endl;
	
  LinkedList<string> link; //Initialize Stack
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
      stringName = line;
      continue;
    }
    string bid;

    stringstream(line) >> bid;
    // printf("%d\n", bid);
    link.addNode(bid);
  }
  printf("DONE\n");
  // Verify contents of stack after traversing through file.
  vector<string> vec = link.toVector();
  for (int i = 0; i <= link.getLength(); i++){
    printf("%s", vec[i]);
  }

  return 0;
}  // end main