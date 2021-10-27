#include <iostream>
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(){
  printf("Please enter a file name: ");
  string fileName;
  cin >> fileName;
	
  LinkedList link; //Initialize Linked List
  ifstream file_reader(fileName);
  
  //If file doesn't exist, exit program
  if (!file_reader){
    printf("Error: File not found!\n");
    printf("Exiting Program\n");
    return 1;
  } else {
    printf("File successfully opened!\n");
  }
  
  string line;
  int i = 1;
  printf("READING\n");
  while(!file_reader.eof()){
    getline(file_reader, line);
    link.addNode(line.c_str());
  }
  printf("FINISHED READING\n");
  // Verify contents of stack after traversing through file.
  vector<string> vec = link.toVector();
  return 0;
}  // end main
