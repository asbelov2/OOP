#pragma once
#include "Employee.h"
class Worker :
	public Employee
{
private:
	int _hours;
	static double _coef;

public:
	Worker(std::string name = "", int age = 0, bool gender = Male, double salary = 0, std::string workPlace = "", int hours = 0, double coef=1);
	int GetHours();
	void SetHours(int);
	void AddHours(int);
	static void SetCoef(double coef);
	static double GetCoef();

	virtual void PrintInfo();
	virtual void CalculateSalary();
	virtual ~Worker();
};

