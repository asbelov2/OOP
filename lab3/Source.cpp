#include <iostream>
using namespace std;

class Base
{
	virtual void func1() { cout << 1 << " "; }
	void func2() { cout << 11 << " "; }
public:
	void getFunc() { func1(); func2(); }
};

class Derived : public Base
{
	void func1() { cout << 2 << " "; }
	void func2() { cout << 22 << " "; }
};

int main()
{
	Base* obj = new Derived;
	obj->getFunc();
	return 0;
}