#pragma once
#include <iostream>
class Point
{
private:
	int x;
	int y;
public:
	int GetX() const { return x; };
	int GetY() const { return y; };
	Point(const int x = 0, const int y = 0) : x(x), y(y) {};
	bool operator==(const Point & other) const;
	friend std::ostream & operator<<(std::ostream & os, const Point & point);
	int operator<(const Point & other) const { return ((x* x + y * y) < (other.x * other.x + other.y* other.y)); }
};

