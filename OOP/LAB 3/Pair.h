#pragma once
#include <iostream>
#include "MyData.h"
#include "myString.h"
class Pair
{
private:
	MyString key;
	MyData data;
	Pair() : key("NULL") {};
	Pair(const char * key, const MyData & data) : key(key), data(data) {};
	~Pair() {};
	Pair(const Pair & other) = default;
	Pair & operator=(const Pair & other) = default;
	Pair(Pair && other) = default;
	Pair & operator=(Pair && other) = default;
	bool operator==(const char * key) const;	
	friend std::ostream & operator<<(std::ostream & os, const Pair & pair);
public:
	friend class Base;
};

