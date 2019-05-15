#include "Point.h"

std::ostream & operator<<(std::ostream & os, const Point & point)
{
	std::cout << "x = " << point.x << " y = " << point.y;
	return os;
}

Point & Point::operator+=(const Point & other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Point & Point::operator+=(int delta)
{
	this->x += delta;
	this->y += delta;
	return *this;
}

Point Point::operator+(const Point & other) const
{
	return Point(x + other.x, y + other.y);
}

Point Point::operator+(int delta) const
{
	return Point(x + delta, y + delta);
}

Point operator+(int delta, const Point & point)
{
	return Point(point.x + delta, point.y + delta);
}

Point & operator-=(Point & point, const Point & other)
{
	point.x += other.x;
	point.y += other.y;
	return point;
}

Point & operator-=(Point & point, int delta)
{
	point.x -= delta;
	point.y -= delta;
	return point;
}

Point operator-(const Point & point, const Point & other)
{
	return Point(point.x - other.x, point.y - other.y);
}
Point operator-(const Point & point, int delta)
{
	return Point(point.x - delta, point.y - delta);
}

Point operator-(int delta, const Point & point)
{
	return Point(point.x - delta, point.y - delta);
}

const Point & Point::operator+() const
{
	return *this;
}

Point operator-(const Point & other)
{
	return Point(-other.x, -other.y);
}