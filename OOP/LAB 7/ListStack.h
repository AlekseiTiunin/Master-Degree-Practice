#pragma once
#include <functional>
#include <iostream>
#include <type_traits>
#include <stdexcept>
#include "Stack.h"
template <typename T>
class ListStack : public Stack<T>
{
private:
	class Node
	{
		T data;
		Node * next;
		Node(Node * next, const T & data) :next(next), data(data) {};
		friend class ListStack<T>;
	};
	Node * head = nullptr;
	Node * tail = nullptr;
	void AddToTail(const T& data);
	void ReversePrintRecursive(std::ostream & os, Node * node) const;
	template <typename U>
	void Traverse(U lamda) const;
public:
	ListStack() = default;
	ListStack(const ListStack & other);
	ListStack(ListStack && other);
	ListStack & operator=(const ListStack & other);
	ListStack & operator=(ListStack && other);
	~ListStack() { clear(); }
	void ReversePrintRecursive(std::ostream & os) const { ReversePrintRecursive(os, head); } // возможно переполнение стека
	void ReversePrintIter(std::ostream & os) const; // сложность по памяти O(n), сложность вычисления O(n)
	void ReversePrintDoubleReverse(std::ostream & os); // сложность вычисления O(n), сложность по памяти O(1), не безопасно
	void clear();
	void push(const T & data);
	T pop();	

	template <typename T>
	friend std::ostream & operator<<(std::ostream & os, ListStack<T> & stack);
};

template <typename T>
void ListStack<T>::AddToTail(const T& data)
{
	if (head == nullptr)
		head = tail = new Node(nullptr, data);
	else
	{
		tail->next = new Node(nullptr, data);
		tail = tail->next;
	}
	this->size_++;
}

template <typename T>
ListStack<T>::ListStack(const ListStack & other)
{
	other.Traverse([&](T& data) {this->AddToTail(data); });
}

template <typename T>
ListStack<T>::ListStack(ListStack && other) :  head(other.head), tail(other.tail), Stack<T>::size_(other.size_)
{
	other.head = 0;
	other.tail = 0;
	other.size_ = 0;
}

template <typename T>
ListStack<T> & ListStack<T>::operator=(const ListStack<T> & other)
{
	if (this != &other)
	{
		Node const * src = other.head;
		Node * dst = head;
		while (src && dst)
		{
			dst->data = src->data;
			src = src->next;
			tail = dst;
			dst = dst->next;			
		}
		while (src)
		{
			AddToTail(src->data);
			src = src->next;
		}
		while (dst)
		{
			Node * temp = dst->next;
			delete dst;
			dst = temp;
		}
		this->size_ = other.size_;
		tail->next = nullptr;
	}
	return *this;
}

template <typename T>
ListStack<T> & ListStack<T>::operator=(ListStack<T> && other)
{
	if (this != &other)
	{
		head = other.head;
		tail = other.tail;
		this->size_ = other.size_;
		other.head = 0;
		other.tail = 0;
		other.size_ = 0;
	}
	return *this;
}

template <typename T>
void ListStack<T>::clear()
{
	while (head != nullptr)
		pop();
}

template <typename T>
void ListStack<T>::push(const T & data)
{
	head = new Node(head, data);
	if (tail == nullptr)
		tail = head;
	this->size_++;
}

template <typename T>
T ListStack<T>::pop()
{
	if (this->size_ > 0)
	{
		T retval = head->data;
		Node * temp = head->next;
		delete head;
		head = temp;
		this->size_--;
		if (this->size_ == 0)
			head = tail = nullptr;
		return retval;
	}
	else
	{
		throw std::invalid_argument("Pop of empty list");
	}
	
}

template <typename T>
template <typename U>
void ListStack<T>::Traverse(U lamda) const
{
	Node * cur = head;
	while (cur != nullptr)
	{
		lamda(cur->data);
		cur = cur->next;
	}
}

template <typename T>
std::ostream & operator<<(std::ostream & os, ListStack<T> & stack)
{
	std::ostream os2(os.rdbuf());
	os2 << "Stack of " << typeid(T).name() << ", size = " << stack.size() << std::endl;
	stack.Traverse([&](T& data) { os << data << std::endl; });
	return os;
}

template <typename T>
void ListStack<T>::ReversePrintRecursive(std::ostream & os, Node * traverse) const
{
	if (traverse == nullptr)
		return;
	ReversePrintRecursive(os, traverse->next);
	os << traverse->data << std::endl;
}
template <typename T>
void ListStack<T>::ReversePrintIter(std::ostream & os) const
{
	T ** ptr = new T*[this->size_];
	int count = 0;
	std::function<void(T&)> lamda = [&](T& data) {ptr[count++] = &data; };
	Traverse(lamda);
	for (int i = this->size_ - 1; i >= 0; i--)
	{
		os << *ptr[i] << std::endl;
	}
	delete ptr;
}
template <typename T>
void ListStack<T>::ReversePrintDoubleReverse(std::ostream & os) 
{
	Node* last = nullptr;
	for (Node* next; head != nullptr; head = next)
	{
		next = head->next;
		head->next = last;
		last = head;
	}
	for (Node* next; last != nullptr; last = next)
	{
		next = last->next;
		last->next = head;
		head = last;
		os << last->data << std::endl;
	}
}