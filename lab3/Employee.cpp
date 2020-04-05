#include "Employee.h"
#include <string>

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

void Employee::Write(std::fstream& os)
{
	Person::Write(os);
	size_t len = _workPlace.length() + 1;
	os.write((char*)&len, sizeof(len));
	os.write((char*)GetWorkPlace().c_str(), len);
	os.write((char*)&_salary, sizeof(_salary));
}

void Employee::Read(std::fstream& is)
{
	Person::Read(is);
	size_t len;
	is.read((char*)&len, sizeof(len));
	char* buf = new char[len];
	buf = new char[len];
	is.read(buf, len);
	_workPlace = buf;
	is.read((char*)&_salary, sizeof(_salary));
	delete[]buf;
}

Employee::~Employee()
{
}