#include <iostream>
#include "Worker.h"
#include "Engineer.h"
using namespace std;

int main()
{
	Person* A = new Person("Alex",20,Person::Male);
	A->PrintInfo(); cout << endl;
	Worker* B = new Worker("Jonny",35,Person::Male,0,"Office",40,25);
	B->PrintInfo(); cout << endl;
	B->CalculateSalary();
	B->PrintInfo(); cout << endl;
	Engineer* C = new Engineer("Edward",21,Person::Male,0,"Factory",32,78.5);
	C->PrintInfo(); cout << endl;
	C->CalculateSalary();
	C->PrintInfo(); cout << endl;
	Person* D = new Worker("Elizabeth",45,Person::Female);
	D->PrintInfo(); cout << endl;

	cout << "\n\n\n";

	A->Next()->PrintInfo(); cout << endl;
	A->Last()->PrintInfo(); cout << endl;
	A->First()->PrintInfo(); cout << endl;
	return 0;
}