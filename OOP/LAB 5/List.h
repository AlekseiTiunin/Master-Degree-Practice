#pragma once
#include "Node.h"
#include <fstream>

int CmpRadius(const Circle & first, const Circle &second);

class List
{
private:
	
	Node * tail;
	Node * head;
	size_t size;
	Node * GetNode(size_t i = 0);
	void Append(Node *& other);
	void merge(List & left, List & right, int(*Compare)(const Circle &, const Circle &));
	template <typename T>
		void TraverseOstreamReverse(T, std::ostream & os) const;
	template <typename T>
		void TraverseOstream(T, std::ostream & os) const;
public:	
	
	List();
	~List();

	int Size() { return size; };

	void AddToHead(const Circle & circle);
	void AddToTail(const Circle & circle);

	bool Remove(const Circle & circle);
	int RemoveAll(const Circle & circle);
	void EmptyList();	

	Circle & GetItemNum(int num) { return (GetNode(num))->data; }

	friend std::ostream & operator<<(std::ostream & os, const List & list);

	void merge_sort(int(*Compare)(const Circle &, const Circle &));
	
	void SaveToFile(const char * name) const;
	void ReadFromFile(const char * name);	   
};

//void (Circle::*func)(std::ostream &, const int count)