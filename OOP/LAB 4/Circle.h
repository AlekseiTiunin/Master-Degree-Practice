#pragma once
#include "Point.h"
#include <iostream>
class Circle
{
private:
	Point center;
	int radius;
public:
	Circle(const Point & point, const int r) : center(point), radius(r) {};
	Circle(const int x = 0, const int y = 0, const int r = 0) : center(x, y), radius(r) {};	
	~Circle() {};
	bool operator==(const Circle & other) const;
	friend std::ostream & operator<<(std::ostream & os, const Circle & circle);	
	void Print(std::ostream & os, int count) const;
	friend int CmpRadius(const Circle & first, const Circle &second);
};