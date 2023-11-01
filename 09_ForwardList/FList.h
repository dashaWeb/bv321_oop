#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data{ data }, next{ next } {}
};

template <typename T>
class FList
{
public:
	FList() = default;
	void addHead(const T& data);
	void removeHead();
	void print() const;
	bool isEmpty() const;
	size_t getSize() const;

	void clear(); // очищати весь список
	~FList()
	{

	}
	void addTail(const T& data); // додавання елемента до хвоста списку
	void removeTail(); //* видалення елемента з хвоста списку
	// перевантажити оператор += (обєднати два списка)



private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline void FList<T>::addHead(const T& data)
{
	//Node<T>* tmp = new Node<T>(data, head);
	auto tmp = new Node<T>(data, head);
	if (isEmpty()) {
		tail = tmp;
	}
	head = tmp;
	++size;
}

template<typename T>
inline void FList<T>::removeHead()
{
	if (isEmpty()) {
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = head;
	head = head->next;
	delete tmp;
	--size;
}

template<typename T>
inline void FList<T>::print() const
{
	auto tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline bool FList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline size_t FList<T>::getSize() const
{
	return size;
}
