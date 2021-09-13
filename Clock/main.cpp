#include "iostream"
#include "Clock.h"
#include "stdio.h"
using namespace std;

int main()
{
  // Clock c;
  // cout << "Hello World" << endl;
  // Clock test;
  Clock test(12, 25);
  test.printStandardTime();
  test.printMilitaryTime();
  test.increaseTime(45);
  test.printStandardTime();
  test.printMilitaryTime();
  return 0;
}