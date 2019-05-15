#include "Counter.h"
#include <cstring>
size_t Counter::counter_num = 0;

Counter * Counter::head = nullptr;

Counter::Counter(const char * str) : owner_num(1)
{
	pstr = new char[strlen(str) + 1]; // заносим строку
	strcpy(pstr, str);
	next = head;			// вставляем в начало списка
	head = this;
	counter_num++;
}

Counter * Counter::Add(const char * ptr)
{	
	if (Counter * search = StrInList(ptr))
	{
		search->owner_num++;
		return search;
	}	
	
	return new Counter(ptr);
}

Counter * Counter::StrInList(const char * ptr)
{
	Counter * current = head;
	while (current != nullptr)
	{		
		if (!strcmp(current->pstr, ptr))
			return current;
		current = current->next;
	}
	return nullptr;
}

Counter::~Counter()
{
	if (this != head) // если удаляемый Counter не начало списка
	{
		Counter * current = head;
		while (current->next != this) // идем на место перед удаляемым элементом в списке
			current = current->next;
		current->next = this->next; // сращиваем список
	}
	else
	{		
		head = head->next;	//если удаляемый элемент начало списка, устанавливаем новое начало списка	
	}
	delete[] pstr;
	counter_num--;
}

void Counter::SortAlpha()
{
	Counter * cur = head;

	Counter ** ptr = new Counter * [counter_num];
	cur = head;

	for (size_t i = 0; i < counter_num; i++) 
	{
		ptr[i] = cur;
		cur = cur->next;
	}
	for (size_t i = 0; i < counter_num; i++)
	{
		size_t min = 0;
		for (size_t j = 1; j < counter_num - i; j++)
		{
			if (strcmp(ptr[min]->pstr, ptr[j]->pstr) == -1)
				min = j;
		}
		std::swap(ptr[counter_num - i - 1], ptr[min]);		
	}
	head = ptr[0];
	ptr[counter_num - 1]->next = nullptr;
	for (size_t i = 0; i < counter_num - 1; i++)
		ptr[i]->next = ptr[i + 1];	
	delete[] ptr;
}


std::ostream & operator<<(std::ostream & os, const Counter & str)
{
	os << str.owner_num << ": " <<  str.pstr <<std::endl;
	return os;
}

std::istream & operator>>(std::istream & is, Counter & str)
{
	char buffer[Counter::maxBuffer];
	is >> buffer;
	str.pstr = new char[strlen(buffer) + 1];
	strcpy(str.pstr, buffer);
	return is;
}

void Counter::DecOwnerNum()
{ 
	owner_num--; 
	if (owner_num == 0) // если владельцев нет, удаляем
	{
		delete this;
	}
}