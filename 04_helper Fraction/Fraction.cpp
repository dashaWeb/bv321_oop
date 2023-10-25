#include "Fraction.h"

const int& Fraction::getNum() const
{
	return num;
}

const int& Fraction::getDenum() const
{
	return denum;
}

void Fraction::setNum(const int& num)
{
	if (num != 0) {
		this->num = num;
	}
}

void Fraction::setDenum(const int& denum)
{
	if (denum == 0) {
		return;
	}
	this->denum = denum;
}

string Fraction::getFraction() const
{
	// 1{num} / 5{denum}
	return to_string(num) + "/" + to_string(denum);
}

Fraction Fraction::operator+(const Fraction& other) const
{
	if (this->denum == other.denum) {
		//int num = this->num + other.num;
		return Fraction(this->num + other.num, this->denum);
	}
	/*int denum = this->denum * other.denum;
	int num = this->num * other.denum + other.num * this->denum;
	return Fraction(num, denum);*/
	return Fraction(this->num * other.denum + other.num * this->denum, this->denum * other.denum);
}

Fraction Fraction::operator-(const Fraction& other) const
{
	return Fraction();
}

Fraction Fraction::operator/(const Fraction& other) const
{
	return Fraction();
}

Fraction Fraction::operator*(const Fraction& other) const
{
	return Fraction();
}

void Fraction::operator-()
{
	int start = (this->num < this->denum ? this->num : this->denum);
	for (size_t i = start; i > 1; i--)
	{
		if (this->num % i == 0 && this->denum % i == 0) {
			this->num /= i;
			this->denum /= i;
			i = start / i;
		}
	}
}

// 15/45  / 15
// 1 / 3