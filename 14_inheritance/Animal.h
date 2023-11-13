#pragma once
#include <iostream>
using namespace std;
class Animal abstract
{
public:
	Animal() = default;
	Animal(const string& name, const int& age)
	{
		setName(name);
		setAge(age);
		id = ++last_id;
	}
	virtual void print() const
	{
		cout << id << ". Name :: " << name << "\t age :: " << age << endl;
	}
	void setName(const string& name) {
		if (name.size() == 0 || name[0] == ' ') {
			this->name = "None";
		}
		else {
			this->name = name;
		}
	}
	void setAge(const int& age) {
		if (age < 0) {
			this->age = 0;
		}
		else {
			this->age = age;
		}
	}
	virtual void move() const = 0;
	virtual void eat() const = 0;
private:
	static size_t last_id;
	int age;
protected:
	size_t id;
	string name;
};


