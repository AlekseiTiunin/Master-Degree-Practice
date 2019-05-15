#include "List.h"
#include <string>
#include <cctype>
#include <sstream>
#include <regex>

List::List() : size(0)
{
	head.next = &tail;
	tail.prev = &head;
}

List::~List()
{
	while (head.next != &tail)
		delete head.next;
}
void List::AddToHead(const Circle & circle)
{
	new Node(&head, head.next, circle);
	size++;
}

void List::AddToTail(const Circle & circle)
{
	new Node(tail.prev, &tail, circle);
	size++;
}
bool List::Remove(const Circle & circle)
{
	Node *ptr = head.next;
	while (ptr != &tail)
	{
		if (circle == ptr->data)
		{
			delete ptr;
			size--;
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}
int List::RemoveAll(const Circle & circle)
{
	size_t count = 0;
	Node  *p = head.next;

	while (p != &tail)
	{
		Node *save = p->next;
		if (circle == p->data)
		{			
			
			delete p;
			size--;
			count++;
			
		}
		
			p = save;
	}
	return count;
}

void List::EmptyList()
{
	while (head.next != &tail)
		delete head.next;
	size = 0;
}

template <typename T>
void List::TraverseOstreamReverse(T functor, std::ostream & os) const
{
	Node * p = tail.prev;
	int count = 0;
	while (p != &head)
	{
		(p->data.*functor)(os, count);
		p = p->prev;
		count++;
	}
}

template <typename T>
void List::TraverseOstream(T functor, std::ostream & os) const
{
	Node * p = head.next;
	int count = 0;
	while (p != &tail)
	{
		(p->data.*functor)(os, count);
		p = p->next;
		count++;
	}
}


std::ostream & operator<<(std::ostream & os, const List & list)
{
	os << "N  |" << "x   |" << "y   |" << "radius\n";
	os << "--------------------\n";
	list.TraverseOstream(&Circle::Print, os);
	return os;
}


void List::SaveToFile(const char * name) const
{
	std::ofstream out;
	out.open(name);
	out << *this;
	out.close();
}

void List::ReadFromFile(const char * name)
{
	std::ifstream in;
	in.open(name);
	EmptyList();
	int temp[4];
	std::string(buffer); 

	while(getline(in, buffer))
	{
		std::regex e("\\d+");
		std::smatch m;
		int count = 0;
		while (std::regex_search(buffer, m, e))
		{
			temp[count++] = std::stoi(m[0]);
			buffer = m.suffix().str();
		}
		if (count == 4)
			AddToTail(Circle(temp[1], temp[2], temp[3]));
	}	
}


void List::merge_sort(int(*Compare)(const Circle &, const Circle &))
{
	if (size < 2)
		return;
	else
	{
		List left, right;
		divide(left, right);
		left.merge_sort(Compare);
		right.merge_sort(Compare);
		merge(left, right, Compare);
	}
}

void List::merge(List & left, List & right, int(*Compare)(const Circle &, const Circle &))
{
	while (left.size > 0 || right.size > 0)
	{
		if (left.size > 0 && right.size > 0)
			if (Compare(left.head.next->data, right.head.next->data) == -1)
			{
				Append(left.head.next);
				left.size--;
				size++;			
			}
			else
			{
				Append(right.head.next);
				right.size--;
				size++;
			}
		else if (left.size > 0)
		{
			Append(left.head.next);
			left.size--;
			size++;
		}
		else if (right.size > 0)
		{
			Append(right.head.next);
			right.size--;
			size++;
		}
		
	}
}

void List::divide(List & left, List & right)
{
	size_t middle = size / 2;

	Node * last = tail.prev;

	last->next = &right.tail; // установили конец right на конец исходного списка
	last->prev = right.tail.prev;
	right.tail.prev->next = last;
	right.tail.prev = last;


	right.head.next = GetNode(middle); // установили начало right на середину исходного списка
	GetNode(middle)->prev = &right.head;

	left.tail.prev = GetNode(middle - 1);
	GetNode(middle - 1)->next = &left.tail; // установили конец left на середину списка

	head.next->prev = &left.head; // установили начало left на начало списка
	left.head.next = head.next;

	left.size = middle;	// устанавливаем размеры
	if (size % 2 == 0)
		right.size = middle;
	else
		right.size = middle + 1;

	head.next = &tail; // зануляем исходный список
	tail.prev = &head;
	size = 0;
}


Node* List::GetNode(size_t num)
{	
	if (num >= 0 && num <= size)
	{
		Node * ptr = head.next;
		for (size_t i = 0; i < num; i++)
			ptr = ptr->next;
		return ptr;
	}
	else return &head;
}

void List::Append(Node *& other)
{
	Node * prev = other->prev;
	Node * next = other->next;
	other->prev = tail.prev;
	other->next = &tail;
	tail.prev->next = other;
	tail.prev = other;	
	prev->next = next;
	next->prev = prev;	
}

List::List(const List & other) : size(0)
{
	head.next = &tail;
	tail.prev = &head;
	Node * cur = other.head.next;
	while (cur != &other.tail)
	{
		AddToTail(cur->data);
		cur = cur->next;
	}
}
List::List(List && other)
{
	if (other.size > 0)
	{
		head.next = other.head.next;
		tail.prev = other.tail.prev;
		other.head.next->prev = &head;
		other.tail.prev->next = &tail;
		size = other.size;
		other.head.next = &tail;
		other.tail.prev = &head;
		other.size = 0;
	}
	else
	{
		head.next = &tail;
		tail.prev = &head;
		size = 0;
	}
}
List & List::operator=(const List & other)
{
	if (this != &other)
	{
		head.next = &tail;
		tail.prev = &head;

		if (other.size > 0)
		{
			Node * curOther = other.head.next;
			Node * curThis = head.next;
			while (curOther != &other.tail && curThis != &tail)
			{
				curThis->data = curOther->data;
				curThis = curThis->next;
				curOther = curOther->next;
			}
			if  (curOther != &other.tail)
				while (curOther != &other.tail)
				{
					AddToTail(curOther->data);
					curOther = curOther->next;
				}
			
			else
				while (curThis != &tail)
				{
					Node * save = curThis->next;
					delete curThis;
					curThis = save;
				}
			size = other.size;
		}		
	}

	return *this;
}
List & List::operator=(List && other)
{
	EmptyList();
	if (this != &other)
	{
		if (other.size > 0)
		{
			head.next = other.head.next;
			tail.prev = other.tail.prev;
			other.head.next->prev = &head;
			other.tail.prev->next = &tail;
			size = other.size;
			other.head.next = &other.tail;
			other.tail.prev = &other.head;
			other.size = 0;
		}
		else
		{
			head.next = &tail;
			tail.prev = &head;
			size = 0;
		}
	}
	return *this;
}