#include "list.h"

Node::Node(Node * prev, Node * next, const Circle & circle) : data(circle)
{
	this->prev = prev;
	this->next = next;
	prev->next = this;
	next->prev = this;
}

Node::~Node()
{
	if(this->prev)
		this->prev->next = this->next;
	if(this->next)
		this->next->prev = this->prev;
}