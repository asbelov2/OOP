#include<iostream>
#include"Employee.h"

using namespace std;

int main()
{
	/*
	 *	��������
	 *	��� � char*
	 *	������� � int
	 *	������� ���� � int
	 */
	Employee *Me = new Employee("Aleksandr", 23, 1);
	cout << Me->GetName();
	return 0;
}