#pragma once
#include <iostream>
using namespace std;


template <typename T = int>
class Stack
{
public:
	Stack() = default;
	Stack(const size_t & capacity, const size_t step)
		:capacity{ capacity }, step{ step }, top_{-1}
	{
		stack = new T[capacity];
	}
	void push(const T& data);
	void pop();
	void empty();
	T top() const;
	size_t size() const;
	size_t getCapacity() const;
	void print() const;
	~Stack()
	{
		delete[]stack;
	}
private:
	pair<int,T>* stack = nullptr;
	size_t capacity; 
	int top_;
	size_t step;
	bool full() const;
	bool isEmpty() const;
	void resize();
};

template<typename T>
inline bool Stack<T>::full() const
{
	return top_ == capacity;
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return top_ == -1;
}

template<typename T>
inline void Stack<T>::resize()
{
	capacity += step;// 4+ на скільки збільшити стек
	step *= 2; 
	T* tmp = new T[capacity];
	for (size_t i = 0; i < top_; i++)
	{
		tmp[i] = stack[i];
	}
	delete[] stack;
	stack = tmp;
}

template<typename T>
inline void Stack<T>::push(const T& data)
{
	top_++;
	if (full())
	{
		resize();
	}
	stack[top_] = data;

}

template<typename T>
inline void Stack<T>::pop()
{
	if(!isEmpty())
		top_--;
}

template<typename T>
inline void Stack<T>::empty()
{
	top_ = -1;
}

template<typename T>
inline T Stack<T>::top() const
{
	if (!isEmpty())
		return stack[top_];
	return T();
}

template<typename T>
inline size_t Stack<T>::size() const
{
	return top_ + 1;
}

template<typename T>
inline size_t Stack<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
inline void Stack<T>::print() const
{
	if (isEmpty()) return;
	for (size_t i = 0; i <= top_; i++)
	{
		cout << i << "\t";
	}cout << endl;
	for (size_t i = 0; i <= top_; i++)
	{
		cout << "-" << "\t";
	}cout << endl;
	for (size_t i = 0; i <= top_; i++)
	{
		cout << stack[i] << "\t";
	}
	cout << endl;
}
