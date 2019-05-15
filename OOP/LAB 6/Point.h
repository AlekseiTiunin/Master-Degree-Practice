#pragma once
#include <iostream>
class Point
{
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {};
	bool operator==(const Point & other) const;
	void Get(int &x, int &y) { x = this->x; y = this->y; }
	void Set(int x, int y) { this->x = x; this->y = y; }
	int DistanceX(Point other) { return (x - other.x); }
	int DistanceY(Point other) { return (y - other.y); }
	friend std::ostream & operator<<(std::ostream & os, const Point & point);
	bool operator<(const Point & other) const { return ((x* x + y + y) < (other.x * other.x + other.y* other.y)); }
};

