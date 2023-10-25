#pragma once
#include <string>
using std::string;
using std::to_string;
class Fraction
{
private:
	int num, denum;
public:
	Fraction() = default;
	Fraction(const int& num, const int& denum) :num{ num }, denum{denum}
	{

	}
	const int& getNum() const;
	const int& getDenum() const;
	void setNum(const int& num);
	void setDenum(const int& denum);
	string getFraction() const; // 2/5
	Fraction operator +(const Fraction& other) const; // this(left){one}; other(right){two}
	Fraction operator -(const Fraction& other) const; // this(left){one}; other(right){two}
	Fraction operator /(const Fraction& other) const; // this(left){one}; other(right){two}
	Fraction operator *(const Fraction& other) const; // this(left){one}; other(right){two}
	void operator-();
};

