#pragma once
#include "Employee.h"
class Worker :
	public Employee
{
public:
	Worker();
	virtual void PrintInfo();
	virtual ~Worker();
};

