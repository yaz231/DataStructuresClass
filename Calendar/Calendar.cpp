#include <stdio.h>  
#include <string>
#include <iostream>
#include "Calendar.h"
using namespace std;


string DATES[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


Calendar::Calendar(int month, int day, int year){
  m_month = month;
  m_year = year;
  m_day = day;
}
void Calendar::incrementDay(){
  m_day += 1;
  if (m_month == 2 && m_day == 29){
    m_month += 1;
    m_day = 1;
  }
  if ((m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11) && m_day == 31){
    m_month += 1;
    m_day = 1;
  }
  if ((m_month == 1 || m_month == 3 || m_month == 5 || m_month == 7 || m_month == 8 || m_month == 10) && m_day == 32){
    m_month += 1;
    m_day = 1;
  }
  if (m_month == 12 && m_day == 32){
    m_month = 1;
    m_day = 1;
    m_year += 1;
  }
}
void Calendar::printDate(){
  int x;
  cout << "Type '0' for displaying the date using words or '1' for displaying the date using numbers" << endl;
  cin >> x;
  if (x){
    printf("%02d/%02d/%d\n", m_month, m_day, m_year);
  } else {
    printf("%s/%02d/%d\n", DATES[m_month - 1].c_str(), m_day, m_year);
  }
}