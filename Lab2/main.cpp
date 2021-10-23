#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include "LinkedStack.h"

using namespace std;

int main()
{
  // string test = "auctions.txt";
  // printf("Length: %d\n", test.size());
  printf("Please enter a file name: ");
  string fileName;
  scanf("%20s", fileName);
  cout << fileName << endl;
  printf("Filename: %s", fileName);
	LinkedStack<int> link;
  fstream fin(fileName);
  string line;
  while(getline(fin, line)){
    // if (line[0] == 'V') continue;
      int bid;
      // printf("HERE");
      stringstream(line) >> bid;
      printf("%d\n", bid);
      if (link.isEmpty()){
        link.push(bid);
      } else {
        if (bid > link.peek()) link.push(bid);
        // printf("%d\n", bid);
      }
  }
  // printf("DONE\n");
  // while(!link.isEmpty()){
  //   printf("%d\n", link.peek());
  //   link.pop();
  // }
  printf("Final Bid: %d\n", link.peek());

  return 0;
}  // end main
