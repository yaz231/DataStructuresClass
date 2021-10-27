#include "stdio.h"
//Question 1
Stack aStack;
aStack.push("Jill");
aStack.push("Jane");
aStack.push("Jamie");

//Question 3
void printBackward(const Stack<ItemType>& aStack){
  Stack auxStack;

  while(!aStack.isEmpty()){
    auxStack.push(aStack.peek());
    aStack.pop();
  }

  while(!auxStack.isEmpty()){
    item = auxStack.peek();
    cout << item << endl;
    auxStack.pop();
  }
}

//b
int lengthStack(const Stack<ItemType>& aStack){
  Stack auxStack;
  int count = 0;
  while(!aStack.isEmpty()){
    auxStack.push(aStack.peek());
    aStack.pop();
    count ++;
  }

  while(!auxStack.isEmpty()){
    aStack.push(auxStack.peek());
    auxStack.pop();
  }
  return count;
}

//c
void removeCopies(const Stack<int>& aStack, int num){
  Stack auxStack;
  while(!aStack.isEmpty()){
    if (aStack.peek() == num){
      aStack.pop();
    } else {
      auxStack.push(aStack.peek());
      aStack.pop();
    }
  }
   while(!auxStack.isEmpty()){
    aStack.push(auxStack.peek());
    auxStack.pop();
  }
}

//Question 6
[];
['a'];
['a','b'];
['a','b','c'];
['a','b'];
['a','b','d'];
['a','b','d','e'];
['a','b','d'];
['a','b'];
['a','b','f'];
['a','b','f','g'];
['a','b','f'];
['a','b','f','h'];

String printCorrectOrder(){
  Stack auxStack;
  String ch = "";
  while(!aStack.isEmpty()){
    auxStack.push(aStack.peek());
    aStack.pop();
  }
  while(!auxStack.isEmpty()){
    ch += auxStack.peek();
    auxStack.pop();
  }
  return ch;
}


//Question 8
[];
['x'];
['x','y'];
False;

[];
['y'];
[];
False;

[];
['x'];
['x','y'];
['x'];
False;

[];
['x'];
['x','y'];
False;

[];
['x'];
['x','x'];
['x'];
[];
True;