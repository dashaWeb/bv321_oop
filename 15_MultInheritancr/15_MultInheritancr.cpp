#include <iostream>
//#include "Employee.h"
//#include "Student.h"
#include "StudentWorker.h"
using namespace std;


int main()
{
    Employee employee("Denis", "Manager");
    employee.print();
    cout << "\n\n";

    Student stud("DENIS", "CS");
    stud.print();
    cout << "\n\n";

    StudentWorker studWork1("Ivan", "Programming", "Programming");
    studWork1.print();
    cout << "\n\n";

    StudentWorker studEmployee(stud, employee);
    studEmployee.print();
    cout << "\n\n";
}
