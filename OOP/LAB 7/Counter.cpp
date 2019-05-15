#include "Counter.h"
#include <cstring>
size_t Counter::counter_num = 0;

Counter * Counter::head = nullptr;

Counter::Counter(const char * str) : owner_num(1)
{
	pstr = new char[strlen(str) + 1]; // ������� ������
	strcpy(pstr, str);
	next = head;			// ��������� � ������ ������
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
	if (this != head) // ���� ��������� Counter �� ������ ������
	{
		Counter * current = head;
		while (current->next != this) // ���� �� ����� ����� ��������� ��������� � ������
			current = current->next;
		current->next = this->next; // ��������� ������
		delete[] pstr;
	}
	else
	{
		delete[] pstr;
		head = head->next;	//���� ��������� ������� ������ ������, ������������� ����� ������ ������	
	}
	counter_num--;
}

void Counter::PrintAlpha(std::ostream & os) // ������� ������ ���������� �� ������ � ��������� ���
{
	Counter * cur = head;

	char * ptr[4];// = new char *[counter_num];
	cur = head;

	for (size_t i = 0; i < counter_num; i++) // ���������� ��������� �� ������ � ������
	{
		ptr[i] = cur->pstr;
		cur = cur->next;
	}
	size_t min;
	for (size_t i = 0; i < counter_num; i++) // ���� ����������� �������, �������� ��� � ��������� � �����
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
	if (owner_num == 0) // ���� ���������� ���, �������
	{
		delete this;
	}
}