#pragma once
#include "Node.h"
#include <fstream>
#include <string>
#include <regex>

template <typename T>
class List
{
private:

	Node<T> tail_;
	Node<T> head_;
	size_t size_;
	
	Node<T> * GetNode(size_t num = 0);

	void CaptureNode(Node<T> *& other);

	void merge(List<T> & left, List<T> & right, int(*Compare)(const T&, const T&));
	
	void divide(List<T> & left, List<T> & right);
	template <typename U>
	void Traverse(U lamda) const;
public:

	List();
	~List();
	List(const List & other);
	List(List && other);
	List & operator=(const List & other);
	List & operator=(List && other);

	int size() { return size_; };

	void push_front(const T & shape);
	void push_back(const T & shape);
	T& pop_front() { T temp = head_->next.data; delete head_->next; return temp; }
	T& pop_back() { T temp = tail_->prev.data; delete tail_->prev; return temp; }

	bool remove(const T * shape);	
	int remove_all(const T * shape);
	void clear();

	template <typename T>
	friend std::ostream & operator<<(std::ostream & os, List<T> & list);

	void merge_sort(int(*Compare)(const T&, const T&));

	void SaveToFile(const char * name) const;
	void ReadFromFile(const char * name, void(*ptr)(List<T> &, std::istream &is));
};

template <typename T>
Node<T> * List<T>::GetNode(size_t num)
{
	if (num >= 0 && num <= size_)
	{
		Node<T> * ptr = head_.next;
		for (size_t i = 0; i < num; i++)
			ptr = ptr->next;
		return ptr;
	}
	else return &head_;
}

template <typename T>
void List<T>::CaptureNode(Node<T> *& other)
{
	Node<T> * prev = other->prev;
	Node<T> * next = other->next;
	other->prev = tail_.prev;
	other->next = &tail_;
	tail_.prev->next = other;
	tail_.prev = other;
	prev->next = next;
	next->prev = prev;
}

template <typename T>
template <typename U>
void List<T>::Traverse(U lamda) const
{
	Node<T> * p = head_.next;
	int count = 0;
	while (p != &tail_)
	{
		lamda(*(p->data));
		p = p->next;
		count++;
	}
}

template <typename T>
std::ostream & operator<<(std::ostream & os, List<T> & list)
{
	std::ostream os2(os.rdbuf());
	os2 << "List of " << typeid(T).name() << ", size " << list.size_ << ": " << std::endl;
	list.Traverse([&](T & data) {os2 << data << std::endl; });
	return os;
}


template <typename T> 
void List<T>::merge(List<T> & left, List<T> & right, int(*Compare)(const T&, const T&))
{
	while (left.size_ > 0 || right.size_ > 0)
	{
		if (left.size_ > 0 && right.size_ > 0)
			if (Compare(*left.head_.next->data, *right.head_.next->data) == -1)
			{
				CaptureNode(left.head_.next);
				left.size_--;
				size_++;
			}
			else
			{
				CaptureNode(right.head_.next);
				right.size_--;
				size_++;
			}
		else if (left.size_ > 0)
		{
			CaptureNode(left.head_.next);
			left.size_--;
			size_++;
		}
		else if (right.size_ > 0)
		{
			CaptureNode(right.head_.next);
			right.size_--;
			size_++;
		}

	}
}

template <typename T>
void List<T>::divide(List<T> & left, List<T> & right)
{
	size_t middle = size_ / 2;

	Node<T> * last = tail_.prev;

	last->next = &right.tail_; // установили конец right на конец исходного списка
	last->prev = right.tail_.prev;
	right.tail_.prev->next = last;
	right.tail_.prev = last;


	right.head_.next = GetNode(middle); // установили начало right на середину исходного списка
	GetNode(middle)->prev = &right.head_;

	left.tail_.prev = GetNode(middle - 1);
	GetNode(middle - 1)->next = &left.tail_; // установили конец left на середину списка

	head_.next->prev = &left.head_; // установили начало left на начало списка
	left.head_.next = head_.next;

	left.size_ = middle;	// устанавливаем размеры
	if (size_ % 2 == 0)
		right.size_ = middle;
	else
		right.size_ = middle + 1;

	head_.next = &tail_; // зануляем исходный список
	tail_.prev = &head_;
	size_ = 0;
}

template <typename T>
List<T>::List() : size_(0)
{
	head_.next = &tail_;
	tail_.prev = &head_;
}
template <typename T>
List<T>::~List()
{
	while (head_.next != &tail_)
		delete head_.next;
}
template <typename T>
List<T>::List(const List & other)
{
	head_.next = &tail_;
	tail_.prev = &head_;
	other.Traverse([&](T & data) {push_back(data); });
}
template <typename T>
List<T>::List(List && other)
{
	if (other.size_ > 0)
	{
		head_.next = other.head_.next;
		tail_.prev = other.tail_.prev;
		other.head_.next->prev = &head_;
		other.tail_.prev->next = &tail_;
		size_ = other.size_;
		other.head_.next = &tail_;
		other.tail_.prev = &head_;
		other.size_ = 0;
	}
	else
	{
		head_.next = &tail_;
		tail_.prev = &head_;
		size_ = 0;
	}
}
template <typename T>
List<T> & List<T>::operator=(const List<T> & other)
{
	if (this != &other)
	{
		if (other.size_ > 0)
		{
			Node<T> * curOther = other.head_.next;
			Node<T> * curThis = head_.next;
			while (curOther != &other.tail_ && curThis != &tail_)
			{
				if( typeid(*curThis->data) == typeid(*curOther->data))
					*curThis->data = (*curOther->data); 
				else
				{
					delete curThis->data;
					curThis->data = curOther->data->Clone();
				}
				curThis = curThis->next;
				curOther = curOther->next;
			}
			if (curOther != &other.tail_)
				while (curOther != &other.tail_)
				{
					push_back(*curOther->data);
					curOther = curOther->next;
				}

			else
				while (curThis->next != &tail_)
					delete tail_.prev;
			size_ = other.size_;
		}
		else
		{
			head_.next = &tail_;
			tail_.prev = &head_;
		}
	}
	return *this;
}
template <typename T>
List<T> & List<T>::operator=(List && other)
{
	if (this != &other)
	{
		if (other.size_ > 0)
		{
			head_.next = other.head_.next;
			tail_.prev = other.tail_.prev;
			other.head_.next->prev = &head_;
			other.tail_.prev->next = &tail_;
			size_ = other.size_;
			other.head_.next = &other.tail_;
			other.tail_.prev = &other.head_;
			other.size_ = 0;
		}
		else
		{
			head_.next = &tail_;
			tail_.prev = &head_;
			size_ = 0;
		}
	}
	return *this;
}
template <typename T>
void List<T>::push_front(const T & shape)
{
	new Node<T>(head_.next, shape);
	size_++;
}
template <typename T>
void List<T>::push_back(const T & shape)
{
	new Node<T>(&tail_, shape);
	size_++;
}
template <typename T>
bool List<T>::remove(const T * shape)
{
	Node<T> *ptr = head_.next;
	while (ptr != &tail_)
	{
		if (*shape == *ptr->data)
		{
			delete ptr;
			size_--;
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

template <typename T>
int List<T>::remove_all(const T * shape)
{
	size_t count = 0;
	Node<T>  *p = head_.next;

	while (p != &tail_)
	{
		Node<T> *save = p->next;
		if (*shape == *p->data)
		{

			delete p;
			size_--;
			count++;

		}

		p = save;
	}
	return count;
}
template <typename T>
void List<T>::clear()
{
	while (head_.next != &tail_)
		delete head_.next;
	size_ = 0;
}


template <typename T>
void List<T>::merge_sort(int(*Compare)(const T&, const T&))
{
	if (size_ < 2)
		return;
	else
	{
		List<T> left, right;
		divide(left, right);
		left.merge_sort(Compare);
		right.merge_sort(Compare);
		merge(left, right, Compare);
	}
}
template <typename T>
void List<T>::SaveToFile(const char * name) const
{
	std::ofstream out;
	out.open(name);
	out << *this;
	out.close();
}

template <typename T>
void List<T>::ReadFromFile(const char * name, void(*readFunction)(List<T> &, std::istream &is))
{
	clear();
	std::ifstream in;
	in.open(name);
	std::string buffer;
	std::getline(in, buffer);	
	if (std::regex_search(buffer, std::regex(typeid(T).name())))
		readFunction(*this, in);
	else 
		throw 1;	
	in.close();
}