#pragma once
#include <iostream>

template <typename T>
class RingBuffer
{
private:
	size_t size_ = 0;
	size_t capacity_ = 0;
	size_t first_ = 0;
	size_t last_ = 0;
	T * array_ = nullptr;
	void increment_capacity();
public:
	RingBuffer(const T * array, size_t size);
	RingBuffer(size_t cap = 0);
	RingBuffer(const RingBuffer & other) { RingBuffer temp(other.array_, other.size_); swap(temp); }
	RingBuffer(const RingBuffer && other) { swap(other); }
	RingBuffer & operator=(const RingBuffer & other);

	RingBuffer & operator=(RingBuffer &&other) { swap(other); return *this;}
	~RingBuffer() { delete[] array_; }
	void push(const T& data);
	T pop();
	size_t size() { return size; }
	bool empty() { return size == 0; }	
	void swap(RingBuffer & other);
	friend std::ostream & operator<<(std::ostream & os, RingBuffer<T> & buf)
	{
		os << "size = " << buf.size_ << ", capacity = " << buf.capacity_ << std::endl;
		for (size_t i = 0; i < buf.size_; i++)
			os << buf.array_[(buf.first_ + i) % buf.capacity_] << " ";
		return os;
	}
};

template <typename T>
RingBuffer<T>::RingBuffer(const T * array, size_t size): capacity_(size), size_(size)
{
	array_ = new T[size];
	for (size_t i = 0; i < size; i++)
		array_[i] = array[i];
}

template <typename T>
void RingBuffer<T>::swap(RingBuffer & other)
{
	std::swap(array_, other.array_);
	std::swap(size_, other.size_);
	std::swap(first_, other.first_);
	std::swap(last_, other.last_);
	std::swap(capacity_, other.capacity_);
}


template <typename T>
RingBuffer<T>::RingBuffer(size_t cap) : capacity_(cap)
{
	array_ = new T[capacity_];
}

template <typename T>
void RingBuffer<T>::push(const T& data)
{	
	if (size_ == capacity_)
		increment_capacity();
	size_++;
	array_[last_] = data;
	last_ = (first_ + size_) % capacity_;
}

template <typename T> 
T RingBuffer<T>::pop()
{
	size_--;
	size_t temp = first_;
	first_ = (first_ + 1) % capacity_;
	return array_[temp - 1];
}

template <typename T>
void RingBuffer<T>::increment_capacity()
{
	T * temp = new T[size_ + 1];
	for (size_t i = 0; i < size_; i++)
		temp[i] = array_[(first_ + i) % capacity_];
	capacity_++;
	delete[] array_;
	array_ = temp;
	first_ = 0;
	last_ = size_;
}
template <typename T>
RingBuffer<T> & RingBuffer<T>::operator=(const RingBuffer & other)
{
	if (capacity_ < other.size_)
	{
		RingBuffer temp(other.array_, other.size_);
		swap(temp);
	}
	else
	{
		for (size_t i = 0; i < other.size_; i++)
			array_[i] = other.array_[(other.first_ + i) % other.capacity_];
		size_ = other.size_;
		first_ = 0;
		last_ = size_;
	}
	return *this;
}