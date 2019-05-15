#pragma once

template <class T>
class Stack
{
protected:
	int size_ = 0;
public:
	virtual void clear() = 0;
	virtual void push(const T & data) = 0;
	virtual T pop() = 0;
	int size() { return size_; }
};