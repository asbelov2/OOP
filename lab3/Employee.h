#pragma once
#include "Person.h"
class Employee :
	public Person
{
public: 
	Employee();
	virtual void PrintInfo();
	virtual ~Employee();
};

