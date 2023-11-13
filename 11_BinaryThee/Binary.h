#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* parent, * left, * right;
	Node(const T& data = T(), Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr)
		:data{ data }, parent{ parent }, left{ left }, right{ right }
	{

	}
};
template <typename T>
class Binary
{
public:
	Binary() = default;
	void add(const T& data);
	size_t getSize() const;
	void print() const;
	bool isEmpty() const;
	void deleteData(const T& data);
	Node<T>* findData(const T& data);
private:
	Node<T>* root = nullptr;
	void helperPrint(Node<T>* node) const;
	size_t size = 0;
};

template<typename T>
inline void Binary<T>::add(const T& data)
{
	Node<T>* new_node = new Node<T>(data);
	size++;
	if (isEmpty()) {
		root = new_node;
		return;
	}
	Node<T>* tmp = root;
	while (true)
	{
		if (data < tmp->data) {
			if (tmp->left == nullptr) {
				new_node->parent = tmp;
				tmp->left = new_node;
				break;
			}
			tmp = tmp->left;
		}
		else {
			if (tmp->right == nullptr) {
				new_node->parent = tmp;
				tmp->right = new_node;
				break;
			}
			tmp = tmp->right;
		}

	}

}

template<typename T>
inline size_t Binary<T>::getSize() const
{
	return size_t();
}

template<typename T>
inline void Binary<T>::print() const
{
	cout << "Print :: ";
	helperPrint(root);
	cout << endl;
}

template<typename T>
inline bool Binary<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline void Binary<T>::deleteData(const T& data)
{
	if (isEmpty()) return;
	Node<T>* node = findData(data);
	size--;
	if (size == 0) {
		delete node;
		root = nullptr;
		return;
	}
	if (node->left == nullptr && node->right == nullptr) {
		node->parent->left == node ? node->parent->left = nullptr : node->parent->right = nullptr;
		
	}
	else if (node == root) {
		if (node->left == nullptr) {
			root = node->right;
		}
		else {
			auto tmp = node->left;
			while (tmp->right != nullptr)
			{
				tmp = tmp->right;
			}
			tmp->right = root->right;
			root = node->left;
		}
	}
	else {
		if (node->left != nullptr) {
			auto tmp = node->right;
			while (tmp->left != nullptr)
			{
				tmp = tmp->left;
			}
			tmp->left = node->left;
		}
		node->parent->left = node->right;
		
	}
	if (node != nullptr) {
		delete node;
	}
}

template<typename T>
inline Node<T>* Binary<T>::findData(const T& data)
{
	auto tmp = root;
	while (tmp!=nullptr)
	{
		if (data == tmp->data) {
			return tmp;
		}
		if (data < tmp->data) {
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp->right;
		}
	}
	return nullptr;
}

template<typename T>
inline void Binary<T>::helperPrint(Node<T>* node) const
{
	if (node != nullptr)
	{
		helperPrint(node->left);
		cout << node->data << "\t";
		helperPrint(node->right);
	}
}
