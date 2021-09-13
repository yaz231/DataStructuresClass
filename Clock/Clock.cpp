#include <stdio.h>  
// #include <iostream>
#include "Clock.h"
using namespace std;



Clock::Clock(){
  printf("Created Default Clock\n");
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
  hr += min/60;
  min = min%60; 
}
void Clock::printStandardTime(){
  if (hr%24 == 0){
    printf("12:%02d\n",min);
  } else {
    printf("%02d:%02d\n", hr%12, min);
  }
}
void Clock::printMilitaryTime(){
  printf("%02d:%02d\n", hr, min);
}


