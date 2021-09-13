#include <stdio.h>  
#include <iostream>
#include "Clock.h"
using namespace std;



Clock::Clock(){
  cout << "Created new Clock" << endl;
  setTime(0, 0);
}
Clock::Clock(int hour, int minutes){
  setTime(hour, minutes);
}
void Clock::setTime(int hour, int minutes){
  hr = hour;
  min = minutes;
}
void Clock::increaseTime(int minutes){
  min += minutes;
  while(min >= 60){
    hr ++;
    min -= 60;
  }
}
void Clock::printStandardTime(){
  if (hr == 0 || hr == 24){
    if (min < 10){
      cout << 12 << ":" << '0' << min << endl;
    } else {
      cout << 12 << ":" << min << endl;
    }
    return;
  }
  if (min < 10){
    cout << hr%12 << ":" << '0' << min << endl;
  } else {
    cout << hr%12 << ":" << min << endl;
  }
}
void Clock::printMilitaryTime(){
  if (min < 10){
    cout << hr << ":" << '0' << min << endl;
  } else {
    cout << hr << ":" << min << endl;
  }
}


