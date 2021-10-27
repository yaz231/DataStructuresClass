#include <iostream>

using namespace std;

class Node {
  private:
    int item;
    Node* next;

  public:
    Node();
    int getItem();
    Node* getNext();
    void setItem(int);
    void setNext(Node*);
};
Node::Node(){
  item = 0;
  next = nullptr;
}

int Node::getItem(){
  return item;
}

Node* Node::getNext(){
  return next;
}
void Node::setItem(int num){
  item = num;
}

void Node::setNext(Node* n){
  next = n;
}

int get_option(){
  cout << "1. Add a Node\n"
       << "2. Remove a Node\n"
       << "3. Display the List\n"
       << "4. Quit\n";
  int option;
  cout << "Enter Option: ";
  cin >> option;
  return option;
}

void addNode(Node* &startPtr){
  cout << "Please enter in a number: " << endl;
  int num;
  cin >> num;
  Node* newNode = new Node();

  newNode->setItem(num);

  if (!startPtr){
    startPtr = newNode;
  } else {
    newNode->setNext(startPtr);
    startPtr = newNode;
  }
}

void displayList(Node* startPtr){
  Node* currPtr = startPtr;
  cout << "List: " << endl;
  while (currPtr != nullptr){
    cout << currPtr->getItem() << endl;
    currPtr = currPtr->getNext();
  }
}

void removeNode(Node* &startPtr){
  int remove_value;
  Node* nodeToRemovePtr = nullptr;
  Node* currPtr = nullptr;
  Node* prevPtr = nullptr;
  bool valueFound = false;

  cout << "Enter a value to remove from the list: ";
  cin >> remove_value;

  if (startPtr){
    if (remove_value == startPtr->getItem()){
      nodeToRemovePtr = startPtr;
      startPtr = startPtr->getNext();

      //Cleanup
      nodeToRemovePtr->setNext(nullptr);
      delete nodeToRemovePtr;
      nodeToRemovePtr = nullptr;
    } else {
      prevPtr = startPtr;
      currPtr = prevPtr->getNext();
      while (currPtr && !valueFound){
        valueFound = currPtr->getItem() == remove_value;
        if (!valueFound){
          //Ajust the pointers
          prevPtr = currPtr;
          currPtr = currPtr->getNext();
        }
      }
      if (valueFound){
        //Remove Node
        nodeToRemovePtr = currPtr;
        prevPtr->setNext(currPtr->getNext());

        nodeToRemovePtr->setNext(nullptr);
        delete nodeToRemovePtr;
        nodeToRemovePtr = nullptr;
        currPtr = nullptr;
      }
    }
  } 
}

int main(){
  int option;
  Node* headPtr = nullptr;
  option = get_option();
  while (option != 4){
    switch (option){
      case 1:
        // cout << "HeadPtr before: " << headPtr << endl;
        addNode(headPtr);
        // cout << "HeadPtr after " << headPtr << endl;
        break;
      case 2:
        removeNode(headPtr);
        break;
      case 3:
        displayList(headPtr);
        break;
    }
    option = get_option();
  }
  return 0;
}