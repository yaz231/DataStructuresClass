#ifndef CLOCK_H  
#define CLOCK_H 

class Clock{
  private:
    int hr, min;

  public:
    Clock();
    Clock(int hour, int minutes);
    void setTime(int hour, int minutes);
    void increaseTime(int minutes);
    void printStandardTime();
    void printMilitaryTime();
};

#endif // CLOCK_H