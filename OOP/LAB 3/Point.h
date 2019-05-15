#pragma once
#include <iostream>
class Point
{
private:
	int x;
	int y;
public:
	~Point() {};
	Point(int x = 0, int y = 0) : x(x), y(y) {};

	Point & operator+=(const Point & other);
	Point & operator+=(int delta);
	Point operator+(const Point & other) const;
	Point operator+(int delta) const;
	friend Point operator+(int delta, const Point &);
	
	friend Point & operator-=(Point & point, const Point & other);
	friend Point & operator-=(Point & point, int delta);
	friend Point operator-(const Point & point, const Point & other);
	friend Point operator-(const Point & point, int delta);
	friend Point operator-(int delta, const Point & point);

	const Point & operator+() const;
	friend Point operator-(const Point & other);

	friend std::ostream & operator<<(std::ostream & os, const Point & point);
};

