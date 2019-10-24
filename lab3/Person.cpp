#include "Person.h"
#include<iostream>

int Person::count = 0;
Person* Person::_first = NULL;
Person* Person::_last = NULL;

Person::Person(std::string name, int age, bool gender)
{
	if (_first == NULL)
	{
		_first = this;
		_last = _first;
	}
	else 
	{
		_last->SetNext(this);
		_last = this;
	}
	_name = name;
	_age = age;
	_gender = gender;
	count++;
}

Person::Person(const Person& o)
{
	_name = o._name;
	_age = o._age;
	_gender = o._gender;
	_next = o._next;
}

void Person::PrintInfo()
{
	std::cout << "Name: " << _name << "\nAge: " << _age << "\nGender: ";
	if (_gender)
	{
		std::cout << "Female\n";
	}
	else
	{
		std::cout << "Male\n";
	}
}

std::string Person::GetName() { return _name; }
int Person::GetAge() { return _age; }
bool Person::GetGender() { return _gender; }

void Person::SetName(std::string name) { _name = name; }
void Person::SetAge(int age) { _age = age; }
void Person::SetGender(bool gender) { _gender = gender; }

Person* Person::Next() 
{ 
	if (_next != NULL) 
	{ 
		return _next; 
	} 
	else
	{
		std::cout << "There is no more persons\n";
		return NULL;
	}
}

Person* Person::First()
{
	if (_first != NULL)
	{
		return _first;
	}
	else
	{
		std::cout << "There is no persons\n";
		return NULL;
	}
}

Person* Person::Last()
{
	if (_last != NULL)
	{
		return _last;
	}
	else
	{
		std::cout << "_last is empty\n";
		return NULL;
	}
}

void Person::SetNext(Person* next)
{
	_next = next;
}

int Person::GetCount()
{
	return count;
}

Person::~Person()
{
	if (_first == this)
	{
		_first = _next;
	}
	else
	{
		Person* tmp = _first;
		if (_last == this)
		{
			for (int j = 0; j < count - 2; j++)
			{
				tmp = tmp->_next;
			}
			_last = tmp;
			_last->_next = NULL;
		}
		else 
		{
			int i = 0;
			while (tmp != this)
			{
				i++;
				tmp = tmp->_next;
			}
			tmp = tmp->_first;
			for (int j = 0; j < i-1; j++)
			{
				tmp = tmp->_next;
			}
			tmp->_next = this->_next;

		}

	}

	count--;
}
Person& Person::operator[](const size_t i)
{
	/*if (i >= count)
	{
		return NULL;
	}
	else*/
	{
		Person* tmp = _first;
		for (int j = 0; j < i;j++)
		{
			tmp = tmp->_next;
		}
		return *tmp;
	}
}