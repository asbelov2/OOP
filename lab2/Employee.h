#pragma once
// модуль STUDENT.H
class Employee
{
private:
	int _age = 0;
	char* _name = new char[20];
	int _workExperience=0;

public:
	Employee();
	Employee(const char* name, int age, int workExperience);
	Employee(const Employee& o);
	char* GetName();
	~Employee();
};