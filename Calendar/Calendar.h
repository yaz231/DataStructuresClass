#ifndef CALENDAR_H  
#define CALENDAR_H 

class Calendar{
  private:
    int m_month, m_year, m_day;

  public:
    Calendar(int month, int day, int year);
    void incrementDay();
    void printDate();
};

#endif // CALENDAR_H