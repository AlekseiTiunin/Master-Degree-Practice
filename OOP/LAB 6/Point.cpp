#include "Point.h"
#include <iomanip>

std::ostream & operator<<(std::ostream & os, const Point & point)
{
	os << "x = " <<  point.x << ", y = "  << point.y;
	return os;
}

bool Point::operator==(const Point & other) const
{
	if (x == other.x && y == other.y)
		return true;
	else
		return false;
}