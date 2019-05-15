#include "Base.h"

Base::~Base()
{
	delete [] pBase;
}

Base::Base(const Base & other) :pBase(new Pair[other.count]), count(other.count), capacity(other.count)
{
	for (size_t i = 0; i < other.count; i++)
		pBase[i] = other.pBase[i];
}

Base & Base::operator=(const Base & other)
{
	if(this != &other)
	{
		count = other.count;
		if (this->capacity < other.count)
		{
			delete[] pBase;
			pBase = new Pair[other.count];			
			capacity = count;
		}
		for (size_t i = 0; i < other.count; i++)
			pBase[i] = other.pBase[i];
		
	}
	return *this;
}

Base::Base(Base && other) : pBase(other.pBase), count(other.count), capacity(other.capacity)
{

		other.capacity = 0;
		other.count = 0;
		other.pBase = nullptr;
	
}

Base & Base::operator=(Base && other)
{
	if (this != &other)
	{
		delete[] pBase;
		pBase = other.pBase;
		count = other.count;
		capacity = other.capacity;
		other.capacity = 0;
		other.count = 0;
		other.pBase = nullptr;
	}
	return *this;
}

int Base::KeyNumInBase(const char * key) const
{
	for (size_t i = 0; i < count; i++)
		if (pBase[i].key == key)
			return i;
	return -1;
}

MyData & Base::operator[](const char * key)
{
	size_t keyNum = KeyNumInBase(key);
	if (keyNum == -1)
	{
		if (count == capacity)
		{		
			capacity += buffersize;
			Pair * temp = new Pair[capacity];
			for (size_t i = 0; i < count; i++)
				temp[i] = std::move(pBase[i]);			
			delete[] pBase;
			pBase = temp;					
		}
		count++;
		pBase[count - 1].key = key;
		return pBase[count - 1].data;
	}
	else
		return pBase[keyNum].data;
}
int Base::deletePair(const char * key)
{
	int num = KeyNumInBase(key);
	if (num != -1)
	{
		pBase[num] = std::move(pBase[count - 1]);
		count--;
		return 1;
	}
	else
		return -1;
}
std::ostream & operator<<(std::ostream & os, const Base & base)
{
	os << "Число сотрудников: " << base.count << ", Вместимость базы: " << base.capacity << std::endl;
	for (size_t i = 0; i < base.count; i++)
		os << base.pBase[i] << std::endl;
	return os;
}

void Base::CompressUnused()
{
	if (count < capacity)
	{
		Pair * temp = new Pair[count];
		for (size_t i = 0; i < count; i++)
			temp[i] = std::move(pBase[i]);
		capacity = count;
		delete[] pBase;
		pBase = temp;
	}
}