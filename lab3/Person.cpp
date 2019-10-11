#include "Person.h"
#include<iostream>

int Person::count = 0;
Person* Person::first = NULL;

Person::Person()
{
	if (first == NULL)
	{
		first = this;
	}
	else 
	{
		next = first + count * sizeof(Person);
	}
	_name = "";
	_age = 0;
	_gender = Male;
	count++;
}

Person::Person(std::string name, int age, bool gender)
{
	if (first == NULL)
	{
		first = this;
	}
	else 
	{
		next = first + count * sizeof(Person);
	}
	_name = name;
	_age = age;
	_gender = gender;
	count++;
}

void Person::PrintInfo()
{
	std::cout << "Name: " << _name << "\nAge: " << _age << "\nGender: ";
	if (_gender)
	{
		std::cout << "Female" << std::endl;
		std::cout << "Male" << std::endl;
	}
}

std::string Person::GetName() { return _name; }
int Person::GetAge() { return _age; }
bool Person::GetGender() { return _gender; }
Person* Person::Next() 
{ 
	if (next != NULL) 
	{ 
		return next; 
	} 
	else
	{
		std::cout << "There is no more persons" << std::endl;
		return NULL;
	}
}

Person* Person::First()
{
	if (first != NULL)
	{
		return next;
	}
	else
	{
		std::cout << "There is no persons" << std::endl;
		return NULL;
	}
}

Person* Person::operator[](int n)
{
	if (n < count)
	{
		return first + n * sizeof(Person);
	}
	else
	{
		return NULL;
	}
}

// Почему каждый класс использующий виртуальную функцию должен иметь виртуальный деструктор?
Person::~Person()
{
	count--;
}