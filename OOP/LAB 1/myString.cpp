#include <string>
#include <iostream>
#include "myString.h"
using namespace std;

// Определение конструктора.

MyString::MyString()
{
	m_pStr = nullptr;
}

MyString::MyString(const char * str)
{ 
	if (str != nullptr)
	{
		m_pStr = new char[strlen(str) + 1];
		strncpy(m_pStr, str, strlen(str) + 1);
	}
	else
		m_pStr = nullptr;
}

MyString::MyString(const MyString & other)
{
	if (other.m_pStr != nullptr)
	{
		m_pStr = new char[strlen(other.m_pStr) + 1];
		strncpy(m_pStr, other.m_pStr, strlen(other.m_pStr) + 1);
	}
	else
		m_pStr = nullptr;
}

MyString & MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		if (other.m_pStr != nullptr)
		{
			if (m_pStr != nullptr && strlen(m_pStr) < strlen(other.m_pStr))
			{
				delete[] m_pStr;
				m_pStr = new char[strlen(other.m_pStr) + 1];
			}	
			strncpy(m_pStr, other.m_pStr, strlen(other.m_pStr) + 1);
		}
		else
		{
			delete[] m_pStr;
			m_pStr = nullptr;
		}
	}
			
	return *this;
}

MyString::MyString(MyString && other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}

MyString & MyString::operator=(MyString&& other)
{
	if (this != &other )
	{
		delete[] m_pStr;
		m_pStr = other.m_pStr;
		other.m_pStr = nullptr;
	}
	return *this;
}

MyString::~MyString()
{
	delete[] m_pStr;
}

std::ostream & operator<<(std::ostream & os, const MyString & str)
{
	if (str.m_pStr != nullptr)
		std::cout << str.m_pStr;
	return os;
}

std::istream & operator>>(std::istream & is, MyString & str)
{
	char string[str.MaxLen];
	std::cin >> string;
	str = MyString(string);
	return is;
}

const char * MyString::GetString() const
{
	if (m_pStr != nullptr)
		return m_pStr;
	else
		return "\0";
}

void MyString::SetNewString(const char * str)
{
	if (str != nullptr)
	{
		delete[]  m_pStr;
		m_pStr = new char[strlen(str) + 1];
		strncpy(m_pStr, str, strlen(str) + 1);
	}
	else
	{
		delete[] m_pStr;
		m_pStr = nullptr;
	}
}

MyString MyStrCat(size_t number, const char * first, ...)
{
	const char ** pp = &first;

	size_t length = 1;
	for (size_t i = 0; i < number; i++)
		if (pp[i] != nullptr)
			length += strlen(pp[i]);
	
	char * buffer = new char[length] {'\0'};
	for (size_t i = 0; i < number; i++)
		if (pp[i] != nullptr)
			strcat(buffer, pp[i]);
	MyString temp(buffer);
	delete[] buffer;
	return temp;
}

void MyString::MyStrCat(size_t number, const char * first, ...)
{
	const char ** pp = &first;

	size_t length = 1;

	for (size_t i = 0; i < number; i++)
		if (pp[i] != nullptr)
			length += strlen(pp[i]);

	if (m_pStr != nullptr)
	{
		if (strlen(m_pStr) < length)
		{
			delete[] m_pStr;
			m_pStr = new char[length] {'\0'};
		}
	}
	else
		m_pStr = new char[length] {'\0'};

	strcpy(m_pStr, first);

	for (size_t i = 1; i < number; i++)
		if (pp[i] != nullptr)
			strcat(m_pStr, pp[i]);
}