#include "Worker.h"

double Worker::_coef = 0;

Worker::Worker(std::string name, int age, bool gender, double salary, std::string workPlace, int hours, double coef) : Employee(name, age, gender, salary, workPlace)
{
	_hours = hours;
	_coef = coef;
}

int Worker::GetHours()
{
	return _hours;
}
void Worker::SetHours(int hours)
{
	_hours = hours;
}
void Worker::AddHours(int hours)
{
	_hours += hours;
}
void Worker::SetCoef(double coef)
{
	_coef = coef;
}
double Worker::GetCoef()
{
	return _coef;
}

void Worker::PrintInfo()
{
	Employee::PrintInfo();
	std::cout << "Hours: " << _hours << std::endl;
}

void Worker::CalculateSalary()
{
	SetSalary(_hours * _coef);
}

Worker::~Worker()
{

}