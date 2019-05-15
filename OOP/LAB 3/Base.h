#pragma once
#include "Pair.h"
class Base
{
private:
	Pair * pBase;
	size_t count;
	size_t capacity;
	int KeyNumInBase(const char * key) const; // возвращает номер вхождения ключа, -1 если ключа нет
	static const size_t buffersize = 5;
public:
	Base() : pBase(nullptr), count(0), capacity(0) {};
	~Base();
	Base(const Base & other);
	Base & operator=(const Base & other);
	Base(Base && other);
	Base & operator=(Base && base);
	MyData & operator[](const char * key);
	int deletePair(const char * key);
	void CompressUnused();
	friend std::ostream & operator<<(std::ostream & os, const Base & base);

};

