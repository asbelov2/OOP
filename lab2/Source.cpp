#include<iostream>
#include"Employee.h"

using namespace std;

int main()
{
	/*
	 *	ֻׁ׃ְֶÙָֹ
	 *	טלÿ – char*
	 *	גמחנאסע – int
	 *	נאבמקטי סעאז – int
	 */
	Employee *Me = new Employee("Aleksandr", 23, 1);
	cout << Me->GetName();
	return 0;
}