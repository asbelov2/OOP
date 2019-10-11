#pragma once
#include<iostream>

class Person
{

private:
	std::string _name = "";
	int _age = 0;
	bool _gender = Male;
	static Person* _first;
	Person* _next;
	static Person* _last;
public:
	static int count;

	Person(std::string name = "",int age = 0,bool gender = Male);
	Person(const Person& o);

	std::string GetName();
	int GetAge();
	bool GetGender();
	void SetName(std::string);
	void SetAge(int);
	void SetGender(bool);

	Person* Next();
	static Person* First();
	static Person* Last();
	void SetNext(Person*);
	static int GetCount();

	virtual void PrintInfo();

	virtual ~Person();
	enum Gender
	{
		Male,
		Female
	};
};

