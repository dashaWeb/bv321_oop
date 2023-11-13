#pragma once
#include "Animal.h"
class Walf : public Animal
{
public:
	Walf() = default;
	Walf(const string& name, const int& age, const int& weight)
		:Animal(name,age), weight{weight}
	{
		
	}
	void print() const override
	{
		cout << "WALF" << endl;
		Animal::print();
		cout << "\t Weight :: " << weight << endl;
	}
	void move() const {
		cout << "Walf Move" << endl;
	}
	void eat() const {
		cout << "Walf Eat" << endl;
	}
protected:
	int weight;
};

class Dog : public Walf 
{
public:
	Dog() = default;
	Dog(const string& name, const int& age, const int& weight)
		:Walf(name,age,weight)
	{
	}
	void print() const
	{
		cout << "Dog" << endl;
		Animal::print();
		cout << "\t Weight :: " << weight << endl;
		//Walf::print();
	}
};