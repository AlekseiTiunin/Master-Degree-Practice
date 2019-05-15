#pragma once
#include "Shape.h"
#include <iostream>
class Rect :
	public Shape
{
private:
	int m_left;
	int m_right;
	int m_bottom;
	int m_top;	
public:
	Rect(int left = 0, int right = 0, int bottom = 0, int top = 0, Color color = WHITE);
//	Rect(const Rect & other);
	Rect(const Shape & other);
//	Rect & operator=(const Rect & other);
	~Rect();	
	virtual void WhereAmI() const;
	virtual void Inflate(int delta = 0);
protected:
	virtual void print(std::ostream &os) const;
};

