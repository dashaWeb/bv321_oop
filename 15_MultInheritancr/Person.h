#pragma once
#include <iostream>
using namespace std;
class Person
{
public:
	Person(const string& name)
		:name{name}
	{
		cout << "\t Ctor Person :: " << name << endl;
	}
	~Person()
	{
		cout << "\t Dtor Person :: " << name << endl;
	}

protected:
	string name;
};

