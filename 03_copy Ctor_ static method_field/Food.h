#pragma once
#include <iostream>
using namespace std;
class Food
{
public:
	Food() = default;
	Food(const char* name, const size_t& kkal, const size_t& weight) :kkal{ kkal }, weight{ weight }
	{
		setName(name);
	}
	Food(const char* name, const size_t & kkal):Food(name,kkal,0){}
	Food(const char* name):Food(name,0){}
	Food(const Food& other) { // a = b; a = this, b = other
		setName(other.name);
		setKkal(other.kkal);
		setWeight(other.weight);
	}
	void print() const;
	const char* getName() const;
	const size_t& getKkal() const;
	const size_t& getWeight() const;
	void setName(const char* name);
	void setKkal(const size_t& kkal);
	void setWeight(const size_t& weight);
	void operator =(const Food& other)// a = b; a = this, b = other
	{
		setName(other.name);
		setKkal(other.kkal);
		setWeight(other.weight);
	}
	static const size_t& getCounter()
	{
		return counter;
	}
	~Food()
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
		}
	}
private:
	// знаходиться на глобальному рівні і створюється одне поле на всі обєкти
	size_t id = ++counter;
 	static const size_t MAX_WEIGHT = 1000; // 4
	char* name = nullptr; // 8 ?
	size_t kkal; // 4
	size_t weight; // 4
	void strCopy(char*& dest, const char* source);
	static size_t counter;
};


inline const char* Food::getName() const
{
	return this->name;
}

inline const size_t& Food::getKkal() const
{
	return this->kkal;
}

inline const size_t& Food::getWeight() const
{
	return this->weight;
}

inline void Food::setName(const char* name)
{
	strCopy(this->name, name);
}

inline void Food::setKkal(const size_t& kkal)
{
	this->kkal = kkal;
}

inline void Food::setWeight(const size_t& weight)
{
	if (weight > MAX_WEIGHT) return;
	this->weight = weight;
}

