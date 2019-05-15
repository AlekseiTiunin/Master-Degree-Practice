#pragma once
#pragma once
#include <iostream>
#include "Counter.h"
#include <cctype>
class String
{
private:
	Counter * pCounter;
	static void CharChange(int(*functor)(int));
public:
	String() : pCounter(nullptr) {};
	String(const char * str);
	String(const String & other);
	String(String && other);
	~String();
	void SetNewString(const char * str);
	String & operator=(const char * str);
	String & operator=(const String& str);
	String & operator=(String&& str);

	friend std::ostream & operator<<(std::ostream & os, const String & str);
	friend std::istream & operator>>(std::istream & is, String & str);

	const char * GetString() const;
	static void ToUpper() { CharChange(toupper);}
	static void ToLower() { CharChange(tolower);}
	static void PrintAll(std::ostream & os) 
	{ 
		os << "Counter number: " << Counter::counter_num << std::endl;
		Counter::Traverse([&](Counter * pcntr) { os << *pcntr; });
	}
	static void SortAlpha() { Counter::SortAlpha();}
};


