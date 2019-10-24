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
protected:
	std::string type;
public:
	static int count;

	Person(std::string name = "",int age = 0,bool gender = Male);
	Person(const Person& o);

	std::string GetName();
	virtual std::string GetType()=0;
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

	virtual void PrintInfo()=0;
	Person& operator[](const size_t i);

	virtual ~Person();
	enum Gender
	{
		Male,
		Female
	};
};

