#include <iostream>
#include <cstdlib>
using namespace std;
 
// Define the default capacity of a Queue
#define SIZE 10
 
// A class to represent a Queue
template <class X>
class Queue {
    private:
        X *queueArray;
        int queueSize;
        int front;
        int rear;
        int numItems;
    
    public:
        Queue(int size = SIZE);         // constructor
    
        void enqueue(X);
        void dequeue(X &);

        bool isEmpty() const;
        bool isFull() const;

        // destructor
        void clear();
};
 
// Constructor to initialize the Queue
template <class X>
Queue<X>::Queue(int size)
{
    queueArray = new X[size];
    queueSize = size;
    front = -1;
    rear = -1;
}
 
// Function to add an element `x` to the Queue
template <class X>
void Queue<X>::enqueue(X x) {
    if (isFull())
    {
        cout << "The Queue is Full\n";
        exit(1);
    } else {
        cout << "Inserting " << x << endl;
        //Calculate the new rear position
        rear = (rear + 1) % queueSize;
        //Insert new item
        queueArray[rear] = num;
        //Update item count
        numItems ++;    
    }
}
 
// Function to dequeue the top element from the Queue
template <class X>
void Queue<X>::dequeue(X &num)
{
    // check for Queue underflow
    if (isEmpty())
    {
        cout << "The Queue is empty.\n";
        exit(1);
    } else {
        cout << "Removing front element from the Queue" << peek() << endl;
        //Move front
        front = (front + 1) % queueSize;
        //Retrieve the front item
        num = queueArray[front];
        //Update the item count
        numItems --;
    }
 }

//Function to check if the Queue is empty or not
template <class X>
bool Queue<X>::isEmpty() const{
    return numItems == 0;               
}
 
//Function to check if the Queue is full or not
template <class X>
bool Queue<X>::isFull() const{
    return numItems == queSize;    
}

//Function to reset the Queue
template <class X>
void Queue<X>::clear() {
    front = -1;
    rear = -1;
    numItems = 0;   
}

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