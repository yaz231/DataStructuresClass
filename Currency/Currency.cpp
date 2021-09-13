#include <stdio.h>  
#include <string>
#include <iostream>
#include "Currency.h"
using namespace std;

Currency::Currency(int dollars, int cents){
  m_dollars = dollars;
  m_cents = cents;
}

int Currency::getDollars(){
  return m_dollars;
}

int Currency::getCents(){
  return m_cents;
}

/**
 * Returns the change owed
 * 
 * Assumes that the "price" is the money required and this operation is called on a Currency object noting * * the user's wallet
 * 
 * @param this Currency Object denoting amount of money user has
 * @param price Currency Object denoting amount of money required for purchase
 * @return Currency Object denoting amount due. 'This' is returned if 'this' is less than 'price'
 */
Currency Currency::getChange(Currency price){
  int money_offered = (this->getDollars() * 100) + this->getCents();
  int money_required = (price.getDollars() * 100) + price.getCents();
  int diff = money_offered - money_required;
  if (diff < 0){
    return Currency(this->getDollars(), this->getCents());
  }
  return Currency(diff/100, diff%100);

}