//Question 1
template<class ItemType>
ArrayList<ItemType>::ArrayList(List entries){
  int size = entries.getLength();
  for (int i = 0; i <= size; i ++){
    insert(i,entries.getEntry(i));
  }
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(List entries){
  int size = entries.getLength();
  for (int i = 0; i <= size; i ++){
    insert(i,entries.getEntry(i));
  }
}

//Question 2
template<class ItemType>
LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry){
  if (position <= itemCount){
    remove(position);
    insert(position, newEntry);
  } else {
    insert(position, newEntry);
  }
}

//Question 3
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
  int size = aList.getLength();
  for (int i = 0; i <= size; i ++){
    insert(i, aList.getEntry(i));
  }
}

//Question 5
template<class ItemType>
int LinkedList<ItemType>::getPosition(ItemType& Entry){
    int num = this->.getLength();
    int found = -1;
    for (int i = 1; i <= num; i ++){
      if (this->getEntry(i) == Entry){
        found = i;
        break;
      }
    }
    return found;
}

template<class ItemType>
int ArrayList<ItemType>::getPosition(ItemType& Entry){
    int num = this.getLength();
    int found = -1;
    for (int i = 1; i <= num; i ++){
      if (this.getEntry(i) == Entry){
        found = i;
        break;
      }
    }
    return found;
}