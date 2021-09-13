#ifndef CURRENCY_H  
#define CURRENCY_H 

class Currency{
  private:
    int m_dollars, m_cents;

  public:
    Currency(int dollars, int cents);
    Currency getChange(Currency c);
    int getDollars();
    int getCents();
};

#endif // CURRENCY_H