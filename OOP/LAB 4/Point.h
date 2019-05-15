#pragma once
#include <iostream>
class Point
{
private:
	int x;
	int y;
public:
	Point(const int x = 0, const int y = 0);
	Point(const Point & other);
	~Point();
	bool operator==(const Point & other) const;
	friend std::ostream & operator<<(std::ostream & os, const Point & point);
};

