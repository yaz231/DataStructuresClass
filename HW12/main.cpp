int * sortArray(int data[]){
  int num = data.getLength();
  int temp;
  for (int i = 0; i < num; i ++){
    for (int j = 0; j < num - 1; j ++){
      if (data.getEntry(j) > data.getEntry(j + 1)){
        temp = data.getEntry(j);
        data.setEntry(j, data.getEntry(j+1));
        data.setEntry(j+1, temp);
      }
    }
  }
  return data;
}

int* sortTwoArrays(int arr1[], int arr2[]){
  int arr1_size = arr1.getLength();
  int arr2_size = arr2.getLength();
  int arr3[arr1_size + arr2_size];
  int i, j, k = 0;
  while ((i < (arr1_size + arr2_size)) & (j < arr1_size) & (k < arr2_size)){
    if (j == arr1_size){
      arr3.setEntry(i, arr2.getEntry(k));
    } else if (k == arr2_size) {
      arr3.setEntry(i, arr2.getEntry(j));
    } else if (arr1.getEntry(j) < arr2.getEntry(k)){
      arr3.setEntry(i, arr1.getEntry(j));
      i ++;
      j ++;
    } else {
      arr3.setEntry(i, arr2.getentry(k));
      i ++;
      k ++;
    }
  }
  return arr3;
}
