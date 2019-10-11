#pragma once
#include "Employee.h"
class Engineer :
	public Employee
{
public:
	Engineer();
	virtual void PrintInfo();
	virtual ~Engineer();
};

