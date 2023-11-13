#pragma once
#include <iostream>
using namespace std;
class Engine
{
public:
	Engine() = default;
	Engine(const string& model, const size_t& power,const double& volume, const double& gasl, const size_t& oil )
		:model{ model }, power{power},volume{volume}, gasoline_con{gasl}, oil{oil}
	{
	}
	void print() const
	{
		cout << "Model :: " << model << "\t power :: " << power << "\t volume :: " << volume << "\t gasoline_con :: " << gasoline_con << "\t oil :: " << oil;
	}
private:
	string model;
	size_t power;
	double volume;
	double gasoline_con;
	size_t oil;
};

