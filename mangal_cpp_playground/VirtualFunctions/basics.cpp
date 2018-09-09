//#define NO_VIRTUAL_FUNC 1  
#define VIRTUAL_FUNC    1   

#include<iostream>
using namespace std;


#ifdef NO_VIRTUAL_FUNC
class one //base class
{
    public:
    void display ()
    {
       std::cout << "In base class" << std::endl;
    }
};
#elif VIRTUAL_FUNC
class one //base class
{
    public:
    virtual void display ()
    {
       std::cout << "In base class" << std::endl;
    }
};
#endif


class oneofone : public one //derived class
{
    public:
    void display ()
    {
       cout << "In oneofone class" << endl;
    }
};

class twoofone : public one //derived class
{
    public:
    void display ()
    {
       cout << "In twoofone class" << endl;
    }
};

int main()
{
  one *ptr;
  oneofone p1;
  twoofone p2;
  ptr=&p1;
  ptr->display();
  ptr=&p2;
  ptr->display();
  return 0;
}
