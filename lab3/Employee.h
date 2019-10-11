#pragma once
#include "Person.h"

class Employee :
	public Person
{
private:
	Employee* next;
	double _salary;
	std::string _workPlace;

public: 
	Employee(std::string name = "", int age = 0, bool gender = Male, double salary = 0, std::string workPlace = "");

	double GetSalary();
	void SetSalary(double);
	std::string GetWorkPlace();
	void SetWorkPlace(std::string);
	virtual void PrintInfo();
	virtual void CalculateSalary()=0;

	virtual ~Employee();
};

