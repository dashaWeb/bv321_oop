#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Shape abstract
{
public:
	virtual void show() const = 0;
	virtual void save() const = 0;
	virtual void load() = 0;
};


class Square : public Shape
{
	double x, y, side;
public:
	Square() = default;
	Square(const double& x, const double& y, const double& size = 100)
		:x(x), y(y), side(size)
	{}
	void show() const override {
		cout << "LeftUP :: (" << x << "," << y << "); \t side :: " << side << endl;
	}
	void save() const override {
		ofstream file("data.txt", ios_base::app);
		if (!file.is_open()) {
			return;
		}
		file << x << "\n" << y << "\n" << side << endl;
	}
	void load() override
	{
		ifstream file("data.txt");
		if (!file.is_open()) {
			return;
		}

		file >> this->x >> this->y >> this->side;
	}
};

class Rectangle : public Shape
{
	double x, y, width, heigth;
public:
	Rectangle() = default;
	Rectangle(const double& x, const double& y, const double& width = 100, const double& heigth = 100)
		:x(x), y(y), width(width), heigth(heigth)
	{}
	void show() const override {
		cout << "LeftUP :: (" << x << "," << y << "); \t Size :: " << width << "x" << heigth << endl;
	}
	void save() const override {
		ofstream file("data.txt", ios_base::app);
		if (!file.is_open()) {
			return;
		}
		file << x << "\n" << y << "\n" << width << "\n" << heigth << endl;
	}
	void load() override
	{
		ifstream file("data.txt");
		if (!file.is_open()) {
			return;
		}

		file >> this->x >> this->y >> this->width >> this->heigth;
	}
};
