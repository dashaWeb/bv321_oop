#include "StudentWorker.h"

StudentWorker::StudentWorker(const string& name, const string& position, const string& specialization)
	:Person(name),
	Student("-----", specialization), Employee("+++++", position)
{
	cout << "\t Ctor Student-Employee :: " << Student::name << " - " << Employee::name << endl;
}

StudentWorker::StudentWorker(const Student& student, const Employee& employee)
	:Person(student),
	Student(student), Employee(employee)
{
	cout << "\t Ctor copy Student-Employee :: " << Student::name << " - " << Employee::name << endl;
}

StudentWorker::~StudentWorker()
{
	cout << "\t Dtor Student-Employee :: " << Student::name << " - " << Employee::name << endl;
}

void StudentWorker::print() const
{
	/*cout << "Student name :: " << Student::name << endl;
	cout << "Employee name :: " << Employee::name << endl;*/
	/*Student::print();
	Employee::print();*/
	cout << "\t--------Worker Student :::: \n";
	cout << "Name     :: " << name << endl;
	cout << "Position :: " << position << endl;
	cout << "Speciali :: " << specialization << endl;
}
