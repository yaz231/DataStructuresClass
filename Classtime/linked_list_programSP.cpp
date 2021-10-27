#include <iostream>
#include <memory>
using namespace std;

class Node
{
	private:
		int item;
		shared_ptr<Node> next;	
		
	public:
		Node();
		void setItem(int);
		void setNext(shared_ptr<Node>);
		int getItem();
		//shared_ptr<Node> getNext();
		auto getNext();
};

Node::Node()
{
 	item = 0;
	next = nullptr;
}
void Node::setItem(int i)
{ item = i; }
void Node::setNext(shared_ptr<Node> n)
{ next = n; }
int Node::getItem()
{ return item; }
auto Node::getNext()
{ return next; }

int get_option();
void addNode(shared_ptr<Node> &);
void removeNode(shared_ptr<Node> &);
void displayList(shared_ptr<Node>);

int main()
{
	int option;
	shared_ptr<Node> headPtr = nullptr;
	
	option = get_option();
	while (option != 4)
	{
		switch (option)
		{
			case 1:
				addNode(headPtr);
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

int get_option()
{
	int option;
	
	cout << "1. Add a node\n"
	     << "2. Remove a node\n"
	     << "3. Display list\n"
	     << "4. Quit\n";
	 
	cout << "Enter option: ";     
	cin >> option;
	
	return option;
}

void addNode(shared_ptr<Node> &startPtr)
{
	int num;
	shared_ptr<Node> newNode =  make_shared<Node>();
	
	cout << "Enter an integer: ";
	cin >> num;
	
	newNode->setItem(num);
	
	if (!startPtr)
		startPtr = newNode;
	else
	{
		newNode->setNext(startPtr);
		startPtr = newNode;
	}

}

void removeNode(shared_ptr<Node> &startPtr)
{
	int removeValue;
	shared_ptr<Node> nodeToDeletePtr;
	shared_ptr<Node> curPtr;
	shared_ptr<Node> prevPtr;
	bool valueFound = false;
	
	cout << "Enter value to remove: ";
	cin >> removeValue;
	
	if (startPtr)
	{
		if (removeValue == startPtr->getItem())
		{
			nodeToDeletePtr = startPtr;
			startPtr = startPtr->getNext();	
		}
		else
		{
			prevPtr = startPtr;
			curPtr = prevPtr->getNext();
			
			while (curPtr && !valueFound)
			{
				valueFound = curPtr->getItem() == removeValue;
				if (!valueFound)
				{
					// Adjust the pointers
					prevPtr = curPtr;
					curPtr = prevPtr->getNext();
				}
				
			}
			if (valueFound)
			{
				// Remove node
				nodeToDeletePtr = curPtr;
				prevPtr->setNext(curPtr->getNext());
				
			}
		}
	}
	
}

void displayList(shared_ptr<Node> startPtr)
{
	shared_ptr<Node> curPtr = startPtr;
	
	cout << "List:\n";
	
	while (curPtr != nullptr)
	{
		cout << curPtr->getItem() << endl;
		curPtr = curPtr->getNext();
		//cin.get();
	}
}