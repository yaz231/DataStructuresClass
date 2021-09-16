#include "iostream"
#include "Bag.h"
#include "stdio.h"
using namespace std;

//Question 1
int ArrayBag<ItemType>::sumBag(){
  vector<int> nums = this->toVector();
  int sum = 0;
  for (int i = 0; i < nums.length() - 1; i ++){
    sum += nums[i];
  }
  return sum;
}

//Question 2
bool ArrayBag<ItemType>::replace(ItemType& newEntry, ItemType& oldEntry){
  if (this->contains(oldEntry)){
    this->remove(oldEntry);
    this->add(newEntry);
  } else { return False;}
}

//Question 4
vector<ItemType> ArrayBag<ItemType>::toVector(){
  vector<ItemType> bagContents;
  return recursVector(bagContents,0);
}

vector<ItemType> ArrayBag<ItemType>::recursVector(vector<ItemType> bag, int searchIndex){
  if (searchIndex < itemCount){
    return recursVector(bag.push_back(items[i], searchIndex + 1));
  } else {return bag};
}

//Question 5
ArrayBag<ItemType> ArrayBag<ItemType>::mergeBag(ArrayBag<ItemType>& bag1, ArrayBag<ItemType>& bag2){
  ArrayBag<ItemType> bag3;
  vector<ItemType> arr1 = bag1.toVector();
  vector<ITemType> arr2 = bag2.toVector();
  for (int i = 0; i < arr1.size() - 1; i ++){
    bag3.add(arr1[i]);
  }
  for (int j = 0; j < arr2.size() - 1; j ++){
    bag3.add(arr2[j]);
  }
  return bag3;
}

//Question 6
bool ArrayBag<ItemType>::removeRandom(){
  max = this->getCurrentSize();
  srand(time(0));
  this->remove(items[rand()%max]);
}

//Question7
ArrayBag<ItemType>::ArrayBag(int &entries[]){
  for (i = 0; i <entries.size() - 1; i ++){
    this->add(entries[i]);
  }
  maxItems = DEFAULT_CAPACITY;
  itemCount = entries.size();
}

int main()
{
  Bag aBag;
  abag.add(5);
  abag.add(3);
}