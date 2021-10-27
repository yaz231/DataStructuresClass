auto curPtr = headPtr;                  //1 assignment
while (curPtr != nullptr){              //n+1 comparisons
  cout << curPtr->getItem() << endl;    //n writes
  curPtr = curPtr->getNext();           //n assignments
}

(n + 1) * (a + c) + n * w