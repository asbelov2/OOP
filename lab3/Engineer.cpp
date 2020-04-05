#include "Engineer.h"
#include <sstream>

double Engineer::_coef = 0;

Engineer::Engineer(std::string name, int age, bool gender, double salary, std::string workPlace, int points, double coef) : Employee(name, age, gender, salary, workPlace)
{
	type = "Engineer";
	_points = points;
	_coef = coef;
}

int Engineer::GetPoints()
{
	return _points;
}

std::string Engineer::GetType()
{
	return type;
}


void Engineer::SetPoints(int points)
{
	_points = points;
}

void Engineer::AddPoints(int points)
{
	_points += points;
}

void Engineer::SetCoef(double coef)
{
	_coef = coef;
}

double Engineer::GetCoef()
{
	return _coef;
}

void Engineer::SaveInTxt(std::string filepath)
{
	Person* tmp = Person::First();
	std::fstream fout(filepath);
	fout.open(filepath, std::ios::out);
	for (int i = 0; i < Person::GetCount(); i++)
	{
		fout << (&(*tmp)[i])->GetType() << std::endl;
		fout << (&(*tmp)[i])->GetName() << std::endl << (&(*tmp)[i])->GetAge() << std::endl << (&(*tmp)[i])->GetGenderStr() << std::endl;
		if ((&(*tmp)[i])->GetType() == "Worker")
		{
			fout << static_cast<Worker*>(&(*tmp)[i])->GetCoef() << std::endl << static_cast<Worker*>(&(*tmp)[i])->GetHours() << std::endl << static_cast<Worker*>(&(*tmp)[i])->GetWorkPlace();
			//
		}
		if ((&(*tmp)[i])->GetType() == "Engineer")
		{
			fout << static_cast<Engineer*>(&(*tmp)[i])->GetCoef() << std::endl << static_cast<Engineer*>(&(*tmp)[i])->GetPoints() << std::endl << static_cast<Engineer*>(&(*tmp)[i])->GetWorkPlace();
			//
		}
		fout << std::endl;
	}
	fout.close();
}
void Engineer::OpenFromTxt(std::string filepath)
{
	std::fstream fin(filepath);
	if (!fin.is_open())
	{
		std::cout << "File cannot be opened" << std::endl;
		return;
	}
	DeleteAllPersons();
	std::string line;
	std::string name;
	int age = 0;
	bool gender = false;
	double coef = 0.0;
	int points = 0;
	std::string workplace;

	while (!fin.eof())
	{
		fin >> line;
		if (line == "Worker")
		{
			fin >> name >> age;
			fin >> line;
			if (line == "Male")
				gender = true;
			if (line == "Female")
				gender = false;
			fin >> coef >> points >> workplace;
			new Worker(name, age, gender, coef * points, workplace, points, coef);

		}
		if (line == "Engineer")
		{
			fin >> name >> age;
			fin >> line;
			if (line == "Male")
				gender = true;
			if (line == "Female")
				gender = false;
			fin >> coef >> points >> workplace;
			new Engineer(name, age, gender, coef * points, workplace, points, coef);
		}

	}
	fin.close();
}

void Engineer::Write(std::fstream& os)
{
	Employee::Write(os);
	os.write((char*)&_coef, sizeof(_coef));
	os.write((char*)&_points, sizeof(_points));
}

void Engineer::Read(std::fstream& is)
{
	Employee::Read(is);
	is.read((char*)&_coef, sizeof(_coef));
	is.read((char*)&_points, sizeof(_points));
}

void Engineer::SaveInBin(std::string filepath)
{
	std::string buffer = "";
	std::stringstream ss;
	Person* tmp = Person::First();
	std::fstream fout;
	fout.open(filepath, std::ios::out | std::ios::binary);

	if (!fout.is_open())
	{
		std::cout << "File cannot be opened" << std::endl;
		return;
	}

	for (int i = 0; i < Person::GetCount(); i++)
	{

		(&(*tmp)[i])->Write(fout);
	}

	fout.close();
}
void Engineer::OpenFromBin(std::string filepath)
{
	std::string buffer = "";
	std::stringstream ss(buffer);
	std::fstream fin;
	fin.open(filepath, std::ios::in | std::ios::binary);
	if (!fin.is_open())
	{
		std::cout << "File cannot be opened" << std::endl;
		return;
	}
	DeleteAllPersons();
	size_t len0;
	while (!fin.eof())
	{
		fin.read((char*)&len0, sizeof(len0));
		if (fin.eof()) break;
		char* buf0 = new char[len0];
		fin.read(buf0, len0);
		if (fin.eof()) break;
		if (strcmp(buf0, "Worker") == 0)
		{
			Worker *tmp = new Worker();
			tmp->Read(fin);
		}
		else
		{
			Engineer* tmp = new Engineer();
			tmp->Read(fin);
		}
	}
	fin.close();
}

void Engineer::PrintInfo()
{
	Employee::PrintInfo();
	std::cout << "Points: " << _points << std::endl;
}

void Engineer::CalculateSalary()
{
	SetSalary(_points * _coef);
}

Engineer::~Engineer()
{

}