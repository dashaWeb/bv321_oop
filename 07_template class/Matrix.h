#pragma once
#include <iostream>
using namespace std;
template <typename T = int, size_t rows = 3, size_t cols = 4>
class Matrix
{
public:
	Matrix() = default;
	Matrix(const T& value)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				arr[i][j] = value;
			}
		}
	}
	template <typename T, size_t rows, size_t cols>
	friend ostream& operator <<(ostream& out, Matrix<T,rows,cols>& data);

	Matrix<T, rows, cols> operator+(const T& value) const;
	T& operator() (int r, int c);
	T operator() (int r, int c)const;
private:
	
	T arr[rows][cols]{};
};

template<typename T, size_t rows, size_t cols>
inline ostream& operator<<(ostream& out, Matrix<T, rows, cols>& data)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			out << data.arr[i][j] << "\t";
		}
		out << "\n";
	}
	return out;
}

template<typename T, size_t rows, size_t cols>
inline Matrix<T, rows, cols> Matrix<T, rows, cols>::operator+(const T& value) const
{
	Matrix<T, rows, cols> tmp(*this);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			tmp.arr[i][j] += value;
		}
	}
	return tmp;
}

template<typename T, size_t rows, size_t cols>
inline T& Matrix<T, rows, cols>::operator()(int r, int c)
{
	return arr[r][c];
}

template<typename T, size_t rows, size_t cols>
inline T Matrix<T, rows, cols>::operator()(int r, int c) const
{
	return arr[r][c];
}
