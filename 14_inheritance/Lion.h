#pragma once
#include "Animal.h"
class Lion : public Animal
{
public:
	Lion() = default;
	Lion(const string& name, const int& age, const int& weight)
		:Animal(name, age), weight{ weight }
	{

	}
	void print() const override
	{
		cout << "LION" << endl;
		Animal::print();
		cout << "\t Weight :: " << weight << endl;
	}
	void move() const {
		cout << "Lion Move" << endl;
	}
	void eat() const {
		cout << "Lion Eat" << endl;
	}
protected:
	int weight;
};

