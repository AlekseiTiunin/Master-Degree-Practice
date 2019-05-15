#include "Point.h"
#include <iomanip>
Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point & other)
{
	x = other.x;
	y = other.y;
}


Point::~Point()
{

}

std::ostream & operator<<(std::ostream & os, const Point & point)
{
	os << std::setw(3) << std::left << point.x << "| " << std::setw(3) << std::left << point.y;
	return os;
}

bool Point::operator==(const Point & other) const
{	
	if (x == other.x && y == other.y)
		return true;
	else
		return false;
}