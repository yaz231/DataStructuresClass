#include "iostream"
#include "Calendar.h"
#include "stdio.h"
using namespace std;

int main()
{
  Calendar c(03, 20, 1997);
  c.printDate();
  c.printDate();
  c.incrementDay();
  c.printDate();
  c.printDate();
  return 0;
}