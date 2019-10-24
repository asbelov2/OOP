#include "Engineer.h"
double Engineer::_coef = 0;

Engineer::Engineer(std::string name, int age, bool gender, double salary, std::string workPlace, int points, double coef) : Employee(name, age, gender, salary, workPlace)
{
	type = "Engineer";
	_points = points;
	_coef = coef;
}

int Engineer::GetPoints()
{
	return _points;
}

std::string Engineer::GetType()
{
	return type;
}


void Engineer::SetPoints(int points)
{
	_points = points;
}

void Engineer::AddPoints(int points)
{
	_points += points;
}

void Engineer::SetCoef(double coef)
{
	_coef = coef;
}

double Engineer::GetCoef()
{
	return _coef;
}

void Engineer::PrintInfo()
{
	Employee::PrintInfo();
	std::cout << "Points: " << _points << std::endl;
}

void Engineer::CalculateSalary()
{
	SetSalary(_points * _coef);
}

Engineer::~Engineer()
{

}