#include "Employee.h"
#include <iostream>

Employee::Employee()
	{

	}

Employee::Employee(const char* name, int age, int workExperience)
	{
	strcpy_s(_name, 20, name);
	_age = age;
	_workExperience = workExperience;
	}

Employee::Employee(const Employee& o)
	{
	strcpy_s(_name, 20, o._name);
	_age = o._age;
	_workExperience = o._workExperience;
	}

char* Employee::GetName()
{
	return _name;
}

Employee::~Employee()
	{
	delete _name;
	}