#pragma once
#include "Shape.h"
#include <iostream>
class Circle :
	public Shape
{
private:
	int m_center_x;
	int m_center_y;
	int m_radius;	
public:
	Circle(int center_x = 0, int center_y = 0, int radius = 0, Color color = WHITE);
	//Circle(const Circle & other);
	Circle(const Shape & other);
	//Circle & operator=(const Circle & other);
	~Circle();	
	void Print(std::ostream os) const;
	virtual void WhereAmI() const;
	virtual void Inflate(int delta = 0);
protected:
	virtual void print(std::ostream &os) const;
};

