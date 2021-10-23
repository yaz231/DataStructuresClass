void sort(Bag storeBag){
	fragileBag = new Bag();
	groceryBag = new Bag();
	freq_eggs = storeBag.getFrequencyOf("eggs");
	freq_bread = storeBag.getFrequencyOf("bread");
	while (freq_eggs > 0) || (freq_bread > 0) {
		if storeBag.remove("eggs"){
			freq_eggs --;
			fragileBag.add("eggs");
		}
		
		if storeBag.remove("bread"){
			freq_bread --;
			fragileBag.add("bread");
		}
	}
	list = storeBag.toVector();
	length = storeBag.getCurrentSize();
	for (int i = 0; i < length - 1; i ++){
		groceryBag.add(vector[i]);
	}
}

/**
 * Counts the number of occurences of item in myBag.
 * @param myBag a Bag object of grocery items contained in the bag represented as strings 
 * @param item	a string of the grocery item to count all occurenced of in myBag
 * @return the number of times item is present in myBag
 */
int countItems(Bag myBag, string item){
	int count = 0;
	while myBag.remove(item){
		count ++;
	}
	return count;
}

/**
 * Join the contents of two bags objects into a new bag objects.
 * @param myBag a bag object of grocery items contained in the bag represented as strings 
 * @param this a bag object of the grocery items contained in the bag represented as strings
 * @return a new Bag object containing the contents of this and myBag
 */
 Bag unionBag(Bag myBag){
	 Bag newBag= new Bag();
	 int length1 = this.getCurrentSize();
	 int length2 = myBag.getCurrentSize();
	 arr1 = this.toVector();
	 arr2 = myBag.toVector();
	 for (int i = 0; i < length1 - 1; i ++){
		newBag.add(arr1[i]);
	 }
	 for (int j = 0; j < length2 - 1; j ++){
		newBag.add(arr2[j]);
	 }
	 return newBag;
 }
 
 /**
 * Create a new bag object filled only with items present in both bags
 * @param myBag a bag object of sorted grocery items contained in the bag represented as strings 
 * @param this a bag object of sorted grocery items contained in the bag represented as strings
 * @return a new Bag object containing the contents present in both this and myBag
 */
 Bag intersectionBag(Bag myBag){
	 Bag newBag= new Bag();
	 int length1 = this.getCurrentSize();
	 int length2 = myBag.getCurrentSize();
	 arr1 = this.toVector();
	 arr2 = myBag.toVector();
	 for (int i = 0; i < length1 - 1; i ++){
		 for (int j = i; j < length2 - 1; j ++){
			 if (arr1[i] == arr2[j]){
				 newBag.add(arr1[i]);
			 }
		 }
	 }
	 return newBag;
 }
 
  /**
 * Create a new bag object filled only with items exclusively present in the first bag
 * @param myBag a bag object of sorted grocery items contained in the bag represented as strings 
 * @param this a bag object of sorted grocery items contained in the bag represented as strings
 * @return a new Bag object containing the contents present exclusively in This Bag
 */
 Bag differenceBag(Bag myBag){
	 Bag newBag= new Bag();
	 int length1 = this.getCurrentSize();
	 int length2 = myBag.getCurrentSize();
	 arr1 = this.toVector();
	 arr2 = myBag.toVector();
	 for (int i = 0; i < length1 - 1; i ++){
		 for (int j = i; j < length2 - 1; j ++){
			 if (arr1[i] == arr2[j]){
				 continue;
			 }
			 newBag.add(arr1[i]);
		 }
	 }
	 return newBag;
 }
 
 Polynomial sum(Polynomial a, Polynomial b){
	 Polynomial c = new Polynomial();
	 degree_a = a.degree();
	 degree_b = b.degree();
	 int count = 0;
	 while (count <= degree_a || count <= degree_b){
		 c.changeCoefficient(a.coefficient(count) + b.coefficient(count), count);
	 }
	 return c;
 }