#pragma once
#include "Shape.h"
#include <type_traits>
template <typename T>
class Node
{
	template <typename T> friend class List;
	Node * prev;
	Node * next;
	T * data;

	Node() : prev(nullptr), next(nullptr), data(nullptr) {};
	Node(Node * next, const T & data)
	{
		this->prev = next->prev;
		this->next = next;
		this->prev->next = this;
		this->next->prev = this;
		this->data = data.Clone(); 
	}
	~Node()
	{
		if (this->prev)
			this->prev->next = this->next;
		if (this->next)
			this->next->prev = this->prev;
		delete data;
	}
};
