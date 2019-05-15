#pragma once
#include "Circle.h"
class Node
{
	friend class List;
	Node * prev;
	
	Circle data;
	Node() : prev(nullptr), next(nullptr){};
	Node(Node * prev, Node * next, const Circle & data = { 0,0,0 });
	~Node();

	Node * next;
};

