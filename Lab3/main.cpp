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
  int i = 0;
  // printf("READING\n");
  while(!file_reader.eof()){//Read through and add all the entries to the linked list until we reach the end of the file
    getline(file_reader, line);
    link.addNode(line.c_str());
    i ++;
  }
  printf("%d number of lines in %s\n", i, fileName.c_str());
  // printf("FINISHED READING\n");

  // Verify contents of LinkedList are ordered
  vector<string> vec = link.toVector();
  for (int i = 0; i < vec.size(); i ++){
    printf("Element at Index %d: %s\n", i, vec[i].c_str());
  }
  printf("%d number of unique, ordered entries!\n", vec.size());
  return 0;
}  // end main
