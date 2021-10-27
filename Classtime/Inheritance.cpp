void MagicBox<ItemType>::setItem(const ItemType& theItem){
  if (!firstItemStored){
    PlainBox<ItemType>::item = theItem;
    firstItemStored = true;
  }
}

MagicBox<string> myMagicBox("Volleyball");
string magicBoxItem = myMagicBox.getItem();

PlainBox<string>* cardBoxPtr = new PlainBox<string>("Queen of Hearts");
cardBoxPtr->setItem("Jack of Spades");

PlainBox<string>* cardBoxPts = new MagicBox<string>("Queen of Hearts");
cardBoxPtr->setItem("Jack of Spades");

void displayBoxItem(PlainBox<string> thing){
  cout << "The item stored in the box is " << thing.getItem() << endl;
}

PlainBox<string> myPlainBox("Basketball");
MagicBox<string> myMagicBox("VolleyBall");

displayBoxItem(myPlainBox);
displayBoxItem(myMagicBox);

class PlainBox : public BoxInterface(ItemType)

class JewelryBox : public BoxInterface(ItemType)

BoxInterface<string>* someBoxPtr = new PlainBox<string>("Ace");
BoxInterface<string>* anotherBoxPtr = new JewelryBox<string>("Emerald");
BoxInterface<string>* funBoxPtr = new MagicBox<string>("Stone");

cout << someBoxPtr->getItem() << endl;
cout << anotherBoxPtr->getItem() << endl;
cout <<  funBoxPtr->getItem() << endl;