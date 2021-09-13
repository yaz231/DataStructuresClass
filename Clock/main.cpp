#include "iostream"
#include "Clock.h"
#include "stdio.h"
using namespace std;

int main()
{
  // Clock c;
  // cout << "Hello World" << endl;
  // Clock test;
  Clock test(1, 2);
  // cout << test.getHour() << endl;
  // cout << test2.getHour() << endl;
  test.printStandardTime();
  test.printMilitaryTime();
  // test2.printStandardTime();
  // test2.printMilitaryTime();
  return 0;
}