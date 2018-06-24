#include<iostream>
using namespace std;

class overload
{
        private:
        int real,dupl;
        public:
        overload()//constructor
	{
	
	}
	overload(int a, int b)
	{
		real=a;
		dupl=b;
 	}
	void display()
	{
		cout << "real value is " << real <<endl;
		cout <<"dupl value is " << dupl << endl;
	}
	overload operator + (overload c1)
	{
		overload t1;
		t1.real = real+ c1.real;
		t1.dupl = dupl+ c1.dupl;	
		return t1;
	}
	
};
int main()
{
	overload obj1(5,7),obj2(7,9), obj3;
	obj3.display();
	obj3=obj1+obj2;
	obj3.display();
	return 0;
}
