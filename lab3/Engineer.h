#pragma once
#include "Employee.h"
#include "Worker.h"

class Engineer :
	public Employee
{
private:
	int _points;
	static double _coef;

public:
	Engineer(std::string name = "", int age = 0, bool gender = Male, double salary = 0, std::string workPlace = "", int points = 0, double coef = 1);

	int GetPoints();
	std::string GetType();
	void SetPoints(int);
	void AddPoints(int);
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

	virtual ~Engineer();
};

