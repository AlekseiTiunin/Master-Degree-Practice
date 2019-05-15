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
	if (this != &other)
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
		return '\0';
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

MyString & MyString::operator=(const char * str)
{
	if (str != nullptr)
	{
		delete[] m_pStr;
		m_pStr = new char[strlen(str) + 1];
		strncpy(m_pStr, str, strlen(str) + 1);
	}
	else
		m_pStr = nullptr;

	return *this;
}

MyString MyString::operator+(const MyString& str) const
{
	char * temp = nullptr;
	if (m_pStr != nullptr && str.m_pStr != nullptr)
	{
		temp = new char[strlen(m_pStr) + strlen(str.m_pStr) + 1];
		strcpy(temp, m_pStr);
		strcat(temp, str.m_pStr);
	}
	else if (m_pStr != nullptr && str.m_pStr == nullptr)
	{
		temp = new char[strlen(m_pStr) + 1];
		strcpy(temp, m_pStr);
	}
	else if (m_pStr == nullptr && str.m_pStr != nullptr)
	{
		temp = new char[strlen(str.m_pStr) + 1];
		strcpy(temp, str.m_pStr);
	}
	else
		temp = nullptr;
	MyString retval(temp);
	delete[] temp;
	return retval;
}

MyString & MyString::operator+=(const MyString& str)
{	
	if (m_pStr != nullptr && str.m_pStr != nullptr)
	{
		char * temp = nullptr;
		temp = new char[strlen(m_pStr) + strlen(str.m_pStr) + 1];
		strcpy(temp, m_pStr);
		strcat(temp, str.m_pStr);
		delete[] m_pStr;
		m_pStr = temp;

	}
	else if (m_pStr == nullptr && str.m_pStr != nullptr)
	{
		m_pStr = new char[strlen(str.m_pStr) + 1];
		strcpy(m_pStr, str.m_pStr);
	}	
	return *this;
}

bool MyString::operator==(const char * str) const
{
	if (m_pStr != nullptr && str != nullptr)
		return !strcmp(m_pStr, str);
	else
		return false;
}