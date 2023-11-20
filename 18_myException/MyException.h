#pragma once
#include <iostream>
using namespace std;
class MyException
{
	string message;
	double value;
public:
	MyException(const string& message = "Error",const double& value = 0)
		:message(message),value(value)
	{}
	const string& what() const
	{
		return message;
	}
	const double& getValue() const {
		return value;
	}
};

class DivisionByZeroException : public MyException
{
public:
	DivisionByZeroException(const string& message)
		:MyException(message)
	{}
};

class TooBigValuExceprion : public MyException
{
	static const int LIMIT_UP = 1'000'000;
public:
	TooBigValuExceprion(const string& message, const double& value = LIMIT_UP)
		:MyException(message,value)
	{}
};

class TooSmallValuExceprion : public MyException
{
	static const int LIMIT_DOWN = -1'000'000;
public:
	TooSmallValuExceprion(const string& message, const double& value = LIMIT_DOWN)
		:MyException(message, value)
	{}
};