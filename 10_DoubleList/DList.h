#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* prev, * next;
	Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
		:data{ data }, prev{ prev }, next{ next }
	{

	}
};

template<typename T>
class DList
{
public:
	DList() = default;
	DList(const DList<T>& other)
	{
		clone(this, other);
		this->size = other.size;
	}
	void operator =(const DList<T>& other) {
		clone(this, other);
		this->size = other.size;
	}
	void addHead(const T& data);
	void addTail(const T& data);
	void removeHead();
	void removeTail();
	void print() const;
	void printR() const;
	bool isEmpty() const;
	void removeData(const T& data);
	void clear();
	~DList()
	{
		clear();
	}
private:
	Node<T>* findData(const T& data) const;
	void clone(DList<T>* dest, const DList<T>& source);
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline void DList<T>::addHead(const T& data)
{
	auto tmp = new Node<T>(data, nullptr, head);
	if (isEmpty()) {
		tail = tmp;
	}
	else {
		head->prev = tmp;
	}
	head = tmp;
	++size;
}

template<typename T>
inline void DList<T>::addTail(const T& data)
{
	auto tmp = new Node<T>(data, tail, nullptr);
	if (isEmpty()) {
		head = tmp;
	}
	else {
		tail->next = tmp;
	}
	tail = tmp;
	++size;
}

template<typename T>
inline void DList<T>::removeHead()
{
	if (isEmpty()) {
		return;
	}
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
		return;
	}
	head = head->next;
	delete head->prev;
	head->prev = nullptr;
	size--;
}

template<typename T>
inline void DList<T>::removeTail()
{
}

template<typename T>
inline void DList<T>::print() const
{
	//Node<T>* tmp = head;
	auto tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void DList<T>::printR() const
{
	auto tmp = tail;
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->prev;
	}
	cout << endl;
}

template<typename T>
inline bool DList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline void DList<T>::removeData(const T& data)
{
	auto find = findData(data);
	if (find == nullptr) {
		return;
	}

	if (find == head) {
		removeHead();
		return;
	}
	if (find == tail) {
		removeTail();
		return;
	}
	find->prev->next = find->next;
	find->next->prev = find->prev;
	delete find;
	size--;
}

template<typename T>
inline void DList<T>::clear()
{
	auto size_ = size;
	for (size_t i = 0; i < size_; i++)
	{
		removeHead();
	}
}

template<typename T>
inline Node<T>* DList<T>::findData(const T& data) const
{
	auto tmp = head;
	while (tmp != nullptr && tmp->data != data)
	{
		tmp = tmp->next;
	}
	return tmp;
}

template<typename T>
inline void DList<T>::clone(DList<T>* dest, const DList<T>& source)
{
	if (!dest->isEmpty()) {
		dest->clear();
	}
	auto tmp = source.head;
	while (tmp != nullptr)
	{
		dest->addTail(tmp->data);
		tmp = tmp->next;
	}
}
