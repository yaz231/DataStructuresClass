//Question 1
int sum(){
  if (aList.isEmpty()) return 0;
  int num = aList.getLength();
  int sum = 0;
  for (int i = 1; i <= num; i ++){
    sum += aList.getEntry(i);
  }
  return sum;
}

//Question 3
void reverseOrder(){
  int num = aList.getLength();
  int flips = num/2;
  for (int i = 1; i <= flips; i ++){
    swap(aList, i, num - (i - 1));
  }
}

//Question 6
int getPosition(int numToFind){
  int num = aList.getLength();
  int found = -1;
  for (int i = 1; i <= num; i ++){
    if (aList.getEntry(i) == numToFind){
      found = i;
      break;
    }
    return found;
  }
}