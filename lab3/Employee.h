#pragma once
#include "Person.h"
#include <fstream>

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

	virtual void SaveInTxt(std::string filepath) = 0;
	virtual void OpenFromTxt(std::string filepath) = 0;

	virtual void Write(std::fstream& os) = 0;
	virtual void Read(std::fstream& in) = 0;
	virtual void SaveInBin(std::string filepath) = 0;
	virtual void OpenFromBin(std::string filepath) = 0;
	virtual void PrintInfo() = 0;
	virtual void CalculateSalary() = 0;
	virtual std::string GetType() = 0;

	virtual ~Employee();
};

