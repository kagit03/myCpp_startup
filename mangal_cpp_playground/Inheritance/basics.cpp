#include<iostream>
using namespace std;

class base //base class
{
  protected:
    int a;
  public:
    base ()
    {
      a = 5;
    }
    void operator++ ()
    {
	a++;
    }
    void display ()
    {
       cout << "The count value=" << a << endl;
    }
    
};

class decrement : public base //derived class
{
  public:
    void operator--()
    {
       a--;
    }
};

int main ()
{
  decrement b2;
  ++b2;
  ++b2;
  b2.display();
  --b2;
  b2.display();
  return 0;
}
