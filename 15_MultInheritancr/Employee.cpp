#include "Employee.h"

Employee::Employee(const string& name, const string& position)
	:/*name{name}*/Person(name), position{position}
{
	cout << "\t Ctor Employee :: " << name << endl;
}

Employee::~Employee()
{
	cout << "\t Dtor Employee :: " << name << endl;
}

void Employee::print() const
{
	cout << "Name employee     :: " << name << endl;
	cout << "Position employee :: " << position << endl;
}
