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
		delete[] pstr;
	}
	else
	{
		delete[] pstr;
		head = head->next;	//если удаляемый элемент начало списка, устанавливаем новое начало списка	
	}
	counter_num--;
}

void Counter::PrintAlpha(std::ostream & os) // создаем массив указателей на строки и сортируем его
{
	Counter * cur = head;

	char * ptr[4];// = new char *[counter_num];
	cur = head;

	for (size_t i = 0; i < counter_num; i++) // записываем указатели на строки в массив
	{
		ptr[i] = cur->pstr;
		cur = cur->next;
	}
	size_t min;
	for (size_t i = 0; i < counter_num; i++) // ищем минимальный элемент, печатаем его и переносим в конец
	{
		min = 0;
		for (size_t j = 1; j < counter_num - i; j++)
		{
			if (strcmp(ptr[min], ptr[j]) == 1)
				min = j;
		}
		std::cout << ptr[min] << std::endl;
		std::swap(ptr[counter_num - i - 1], ptr[min]);

	}		
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