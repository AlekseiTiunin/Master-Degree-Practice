#include "Point.h"
#include <iomanip>
#include <cmath>
std::ostream & operator<<(std::ostream & os, const Point & point)
{
	os << std::setw(3) << std::left << point.x << "| " << std::setw(3) << std::left << point.y << "| " 
		<< std::setw(3) << std::sqrt(point.x * point.x + point.y * point.y);
	return os;
}

bool Point::operator==(const Point & other) const
{	
	if (x == other.x && y == other.y)
		return true;
	else
		return false;
}