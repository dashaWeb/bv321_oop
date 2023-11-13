#include "Student.h"

Student::Student(const string& name, const string& specialization)
	:Person(name)/*name{name}*/,specialization{specialization}
{
	cout << "\t Ctor Student :: " << name << endl;
}

Student::~Student()
{
	cout << "\t Dtor Student :: " << name << endl;
}

void Student::print() const
{
	cout << "Name Student :: " << name << endl;
	cout << "Spec Student :: " << specialization << endl;
}
