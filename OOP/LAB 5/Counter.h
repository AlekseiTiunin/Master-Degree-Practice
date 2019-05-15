#pragma once
#include <iostream>
class Counter
{
private:
	static Counter * head;
	static size_t counter_num;	
	template <typename T>
		static void Traverse(T functor);
	static void SortAlpha();
	static Counter * StrInList(const char * ptr);
	static Counter * Add(const char * ptr);
	char *pstr;
	size_t owner_num;
	Counter * next;
	
	Counter(const char * str);
	
	~Counter();
	
	void IncOwnerNum() { owner_num++; }
	void DecOwnerNum();
	
	friend class String;
	friend std::ostream & operator<<(std::ostream & os, const Counter & str);
	static const size_t maxBuffer = 20;
	friend std::istream & operator>>(std::istream & os, Counter & str);
};

template <typename T>
void Counter::Traverse(T functor) 
{
	Counter * cur = head;
	while (cur != nullptr)
	{
		functor(cur);
		cur = cur->next;
	}
}
