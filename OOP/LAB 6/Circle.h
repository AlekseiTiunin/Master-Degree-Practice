#pragma once
#include "Point.h"
#include "Shape.h"
#include <iostream>

const double pi = 3.14159265358979323846;
class Circle : public Shape
{
private:
	Point center;
	int radius;
	double CalcSquare() { return (pi * radius * radius); }
public:
	Circle(int x = 0, int y = 0, int rad = 0, Color col = White) : center(x, y), radius(rad), Shape(col) { square = CalcSquare(); };
	Circle & operator=(const Shape & other)	
	{ 
		*this = static_cast<const Circle &> (other);
		return *this;
	}
	virtual Shape * Clone() const{ return new Circle(*this); };
	void GetCenter(int & x, int &y) { center.Get(x, y); };
	void SetCenter(int x, int y) { center.Set(x, y); };
	void GetRadius(int & distance) { distance = radius; }
	void SetRadius(int distance) { radius = distance; }
	void Print(std::ostream & os) const;
	bool operator==(const Circle & other) const;
	friend int CmpRadius(const Circle &, const Circle &);
};

int CmpRadius(const Circle &, const Circle &);
