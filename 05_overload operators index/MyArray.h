#pragma once
#include <iostream>
using std::cout;
using std::endl;
class MyArray
{
public:
	MyArray(const size_t& size):MyArray(size,0){}
	MyArray(const size_t& size, const int& value) :size{size}
	{
		arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = value;
		}
	}
	void print() const;
	int operator[](const int& index) const; // get - отримати елемент масиву за індексом
	int& operator[](const int& index); // set - повертаємо посилання на елемент масиву за індексом
	MyArray operator()(const int& start, const int& end) const;

private:
	int* arr = nullptr;
	size_t size = 0;
};

