#include "String.h"

String::String(const char * pstr)
{
	pCounter = Counter::Add(pstr);
}

String::String(const String & other)
{	
	pCounter = other.pCounter;
	pCounter->IncOwnerNum();
}

String::String(String && other)
{
	pCounter = other.pCounter;
	other.pCounter = nullptr;
}

String::~String()
{
	if(pCounter != nullptr)
		pCounter->DecOwnerNum();
}


void String::SetNewString(const char * pstr)
{
	if (!strcmp(pstr, pCounter->pstr))
		return;
	else
	{
		pCounter->DecOwnerNum();
		pCounter = Counter::Add(pstr);
	}
}

std::ostream & operator<<(std::ostream & os, const String & str)
{
	if (str.pCounter != nullptr)
		os << *str.pCounter;

	return os;
}

std::istream & operator>>(std::istream & is, String & str)
{
	is >> *str.pCounter;
	return is;
}

const char * String::GetString() const
{
	if (pCounter != nullptr)
		return pCounter->pstr;
	else
		return "";
}

String & String::operator=(const String& str)
{
	if (this != &str && pCounter != str.pCounter)
	{
		if (pCounter != nullptr)
			pCounter->DecOwnerNum();
		pCounter = str.pCounter;
		pCounter->IncOwnerNum();
	}
	return *this;
}

String & String::operator=(String&& str)
{
	if (this != &str)
	{
		if (pCounter != nullptr)
			pCounter->DecOwnerNum();
		pCounter = str.pCounter;
		str.pCounter = nullptr;
	}
	return *this;
}

void String::CharChange(int(*functor)(int))
{
	Counter::Traverse( [functor](Counter *pcntr){
		int i = 0;
		while (pcntr->pstr[i] != '\0')
			pcntr->pstr[i++] = functor(pcntr->pstr[i]);}
	);
}

String & String::operator=(const char * str)
{
	if(pCounter != nullptr)
		SetNewString(str);
	else
		pCounter = Counter::Add(str);
	return *this;
};