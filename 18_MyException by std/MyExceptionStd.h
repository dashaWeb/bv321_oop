#pragma once
#include <iostream>
using namespace std;

class DivisionByZeroException : public exception
{
public:
	DivisionByZeroException(const string& message = "Division by zero")
		:exception(message.data())
	{}
};

class TooBigValuExceprion : public overflow_error
{
	static const int LIMIT_UP = 1'000'000;
	double value;
public:
	TooBigValuExceprion(const string& message, const double& value = LIMIT_UP)
		:overflow_error(message), value(value)
	{}
	double getValue() const {
		return value;
	}
};

class TooSmallValuExceprion : public underflow_error
{
	static const int LIMIT_DOWN = -1'000'000;
	double value;

public:
	TooSmallValuExceprion(const string& message, const double& value = LIMIT_DOWN)
		:underflow_error(message), value(value)
	{}
	double getValue() const {
		return value;
	}
};

