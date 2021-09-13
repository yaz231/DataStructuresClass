#include "iostream"
#include "Currency.h"
#include "stdio.h"
using namespace std;

int main()
{
  Currency wallet(6,60);
  Currency price(5,50);
  Currency change = wallet.getChange(price);
  printf("Change owed: $%d.%02d", change.getDollars(), change.getCents());
  return 0;
}