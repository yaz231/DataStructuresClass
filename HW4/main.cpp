//Question 1
void LinkedBag<ItemType>::removeSecondNode(){
  Node<ItemType>* prev = headPtr;
  Node<ItemType>* current = headPtr->getNext();
  prev = current;
  current = current->getNext();
  prev->setNext(current->getNext());
}

//Question 2
bool LinkedBag<ItemType>::add(const ItemType& newEntry){
  Node<ItemType>* newNodePtr = new Node<ItemType>();
  newNodePtr->setItem(newEntry);
  previous = headPtr;
  while (previous != NULL){
    previous->getNext();
  }
  previous->setNext(newNodePtr);
  newNodePtr.setNext(NULL);
  return true;
}

//Question 3
int LinkedBag<ItemType>::getCurrentSize(){
  int length = 0;
  Node<ItemType>* current = headPtr;
  while(current != NULL){
    length += 1;
    current = current->getNext();
  }
  return length;
}


//Question 4
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry){
  return recurseFrequency(headptr, anEntry, 0);
}

int LinkedBag<ItemType>::recurseFrequency(Node<ItemType> *head, ItemType& anEntry, int count){
  if (head->getNext() == NULL){
    return count;
  } if (head->getItem() == anEntry){
    count ++;
  }
  count = recurseFrequency(head->getNext(), anEntry, count);

  return count;
}

//Question 5
LinkedBag<ItemType>::LinkedBag(ItemType[] entries){
  itemCount = entries.size();
  Node<ItemType>* headPtr = NULL;
  for (int i = 0; i < itemCount - 1; i ++){
    headPtr->add(items[i]);
  }
}