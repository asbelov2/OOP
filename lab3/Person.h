#pragma once
#include<iostream>

class Person
{

private:
	std::string _name = "";
	int _age = 0;
	bool _gender = Male;
	static int count;
	static Person* first;
	Person* next;
public:
	Person();
	Person(std::string,int,bool);

	std::string GetName();
	int GetAge();
	bool GetGender();
	Person* Next();
	Person* First();
	
	Person* operator[](int n);

	virtual void PrintInfo();

	virtual ~Person();
	enum Gender
	{
		Male,
		Female
	};
};

