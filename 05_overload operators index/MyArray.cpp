#include "MyArray.h"

void MyArray::print() const
{
	cout << "Print :: ";
	for (size_t i = 0; i < size; i++)
	{
		cout << "\t" << arr[i];
	}cout << endl;
}

int MyArray::operator[](const int& index) const
{
	if (index < 0 || index >= size) {
		cout << "Error index" << endl;
		return arr[0];
	}
	return arr[index];
}

int& MyArray::operator[](const int& index)
{
	if (index < 0 || index >= size) {
		cout << "Error index" << endl;
		return arr[0];
	}
	return arr[index];
}

MyArray MyArray::operator()(const int& start, const int& end) const
{
	if (start < 0 || end < 0 || start >= size || end >= size) {
		return 0;
	}
	int start_, end_;
	start > end ? start_ = end, end_ = start : start_ = start, end_ = end;
	MyArray tmp(end_ - start_);
	for (size_t i = start_; i < end_; i++)
	{
		tmp[i - start_] = this->arr[i];
	}return tmp;
}
