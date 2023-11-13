#pragma once
#include "Person.h"
class Employee
	:virtual public Person
{
public:
	Employee(const string& name, const string& position);
	~Employee(); 
	void print() const;
protected:
	//string name;
	string position;
};

