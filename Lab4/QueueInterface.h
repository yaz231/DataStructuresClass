#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>
using namespace std;
 
// Define the default capacity of a Queue
#define SIZE 10
 
// A class to represent a Queue
template <class ItemType>
class Queue {
    private:
        unique_ptr<ItemType []> queueArray;
        int queueSize;
        int front;
        int rear;
        int numItems;
    
    public:
        Queue(int size = SIZE);         // constructor
    
        void enqueue(ItemType);
        void dequeue(ItemType &);

        bool isEmpty() const;
        bool isFull() const;
        vector<ItemType> toVector(); 

        // destructor
        void clear();
};
 
// Constructor to initialize the Queue
template <class ItemType>
Queue<ItemType>::Queue(int size) {
    queueArray = make_unique<ItemType []>(size);
    queueSize = size;
    numItems = 0;
    front = -1;
    rear = -1;
}
 
// Function to add an element 'item' to the Queue
template <class ItemType>
void Queue<ItemType>::enqueue(ItemType item) {
    if (isFull())
    {
        cout << "The Queue is Full\n";
        exit(1);
    } else {
        // cout << "Inserting " << item << endl;
        //Calculate the new rear position
        rear = (rear + 1) % queueSize;
        //Insert new item
        queueArray[rear] = item;
        //Update item count
        numItems ++;    
    }
}
 
// Function to dequeue the top element from the Queue
template <class ItemType>
void Queue<ItemType>::dequeue(ItemType &num) {
    // check for Queue underflow
    if (isEmpty()){
        cout << "The Queue is empty.\n";
        exit(1);
    } else {
        // printf("Removing front element from the Queue");
        //Move front
        front = (front + 1) % queueSize;
        //Retrieve the front item
        num = queueArray[front];
        //Update the item count
        numItems --;
    }
 }

//Function to check if the Queue is empty or not
template <class ItemType>
bool Queue<ItemType>::isEmpty() const{
    return numItems == 0;               
}
 
//Function to check if the Queue is full or not
template <class ItemType>
bool Queue<ItemType>::isFull() const{
    return numItems == queueSize;    
}

//Function to reset the Queue
template <class ItemType>
void Queue<ItemType>::clear() {
    front = -1;
    rear = -1;
    numItems = 0;   
}

template <class ItemType>
vector<ItemType> Queue<ItemType>::toVector() {
  vector<ItemType> vector_done;
  if (queueSize == 0){
    return vector_done;
  } else {
    // for (int i = 0; i <= queueSize; i ++){
    //     ItemType item;
    //     dequeue(item);
    //     vector_done.push_back(item);
    //     enqueue(item);
    // }
    int new_front = (front + 1) % queueSize;
    int new_rear = (rear + 1) % queueSize;
    for (int i = 0; i < queueSize; i ++){
        vector_done.push_back(queueArray[new_front + i]);
    }
  }
  return vector_done;
}  // end toVector


// int main()
// {
//     stack<string> pt(2);
 
//     pt.push("A");
//     pt.push("B");
 
//     pt.pop();
//     pt.pop();
 
//     pt.push("C");
 
//     // Prints the top of the stack
//     cout << "The top element is " << pt.peek() << endl;
 
//     // Returns the total number of elements present in the stack
//     cout << "The stack size is " << pt.size() << endl;
 
//     pt.pop();
 
//     // check if the stack is empty or not
//     if (pt.isEmpty()) {
//         cout << "The stack is empty\n";
//     }
//     else {
//         cout << "The stack is not empty\n";
//     }
 
//     return 0;
// }