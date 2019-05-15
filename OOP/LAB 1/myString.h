#pragma once
class MyString
{
    char * m_pStr;	//строка-член класса
	
public:
	MyString();
	MyString(const char * str);
	MyString(const MyString & other);
	MyString(MyString && other);
	~MyString();
	void SetNewString(const char * str);
	friend std::ostream & operator<<(std::ostream & os, const MyString & str);
	friend std::istream & operator>>(std::istream & is, MyString & str);	
	const char * GetString() const;
	static const int MaxLen = 100;
	MyString & operator=(const char * str);
	MyString & operator=(MyString&& str);
	MyString & operator=(const MyString& str);
	void MyStrCat(size_t number, const char * first, ...);
};

MyString MyStrCat(size_t number, const char * first, ...);