#pragma once
#include "myString.h"
#include <iostream>

class MyData
{
public:
	enum SEX{ UNDEF, MALE, FMALE};
private:
	SEX sex;
	size_t age;
	MyString job;
	float salary;
	const static int MROT = 8500;

	MyData() : sex(UNDEF), age(0), job("NULL"), salary(0) {};
	MyData(const MyData & other) = default;
	MyData & operator=(const MyData & other) = default;
	MyData(MyData && d) = default;	
	friend std::ostream & operator<<(std::ostream &os, const MyData & data);
	friend class Pair;
public:
	~MyData() {};
	MyData(SEX sex, size_t age, const char * job, float salary);
	MyData & operator=(MyData && other) = default;
};

