#pragma once
#include <stdexcept>
#include "Stack.h"
template <typename TYPE, size_t CAPACITY>
class ArrayStack: public Stack<TYPE>
{
private:
	TYPE dataArray[CAPACITY];
public:
	void push(const TYPE & data);
	TYPE pop();
	TYPE& operator[](int count);
	void clear() {};
};

template <typename TYPE, size_t CAPACITY>
void ArrayStack<TYPE, CAPACITY>::push(const TYPE & data)
{
	if (this->size_ + 1 > CAPACITY)
		throw std::invalid_argument("Stack size overflow!");
	this->size_++;
	dataArray[this->size_ - 1] = data;
}

template <typename TYPE, size_t CAPACITY>
TYPE ArrayStack<TYPE, CAPACITY>::pop()
{
	if (this->size_ - 1 < 0)
		throw std::invalid_argument("Stack size underflow!");
	this->size_--;
	return dataArray[this->size_];
}

template <typename TYPE, size_t CAPACITY>
TYPE& ArrayStack<TYPE, CAPACITY>::operator[](int count)
{
	if (count < 0 || count > this->size_ - 1)
		throw std::invalid_argument("Index out of reach!");
	else
		return dataArray[count];
}