#pragma once
#include "Employee.h"
#include "Engineer.h"

class Worker :
	public Employee
{
private:
	int _hours;
	static double _coef;

public:
	Worker(std::string name = "", int age = 0, bool gender = Male, double salary = 0, std::string workPlace = "", int hours = 0, double coef=1);
	int GetHours();
	std::string GetType();
	void SetHours(int);
	void AddHours(int);
	static void SetCoef(double coef);
	static double GetCoef();

	void SaveInTxt(std::string filepath);
	void OpenFromTxt(std::string filepath);

	void Write(std::fstream& os);
	void Read(std::fstream& in);
	void SaveInBin(std::string filepath);
	void OpenFromBin(std::string filepath);
	void PrintInfo();
	void CalculateSalary();
	virtual ~Worker();
};

