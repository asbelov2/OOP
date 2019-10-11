#include "Employee.h"

Employee::Employee(std::string name, int age, bool gender, double salary, std::string workPlace) : Person(name, age, gender)
{
	_salary = salary;
	_workPlace = workPlace;
}

double Employee::GetSalary() { return _salary; }
void Employee::SetSalary(double salary) { _salary = salary; }
std::string Employee::GetWorkPlace() { return _workPlace; }
void Employee::SetWorkPlace(std::string workPlace) { _workPlace = workPlace; }

void Employee::PrintInfo()
{
	Person::PrintInfo();
	std::cout << "Salary: " << _salary << " $\nWorkplace: " << _workPlace << std::endl;

}


Employee::~Employee()
{
	count--;
}