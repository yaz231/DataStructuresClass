//Question 1
template<class ItemType>
ArrayList<ItemType>::ArrayList(List entries){
    if (entries.isEmpty()) return;
    for (int i = 1; i <= entries.getLength(); i++){
        items.insert(i, entries.getEntry(i));
        itemCount ++;
    }
}

//Question 1
templaye<class ItemType>
LinkedList<ItemType>::LinkedList(List entries){
    if (entries.isEmpty()) return;
    for (int i = 1; i <= entries.getLength(); i++){
        headPtr->insert(i, entries.getEntry(i));
        itemCount ++;
    }
}

//Question 2
void setEntry(int position, const ItemType& newEntry){
    // Node<ItemType>* prevPtr = getNodeAt(position -1);
    // Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

    // newNodePtr->setNext(prevPtr->getNext());
    // prevPtr->setNext(newNodePtr);
    remove(position);
    insert(position, newEntry);
}

//Question 3
LinkedList::LinkedList(const LinkedList &list){
    for (int i = 1; i <= list.getLength(); i ++){
        this->setEntry(i, list.getEntry(i));
    }
}

//Question 5
