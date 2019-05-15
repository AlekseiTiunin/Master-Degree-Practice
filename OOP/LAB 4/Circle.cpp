#include "Circle.h"
#include <iomanip>


std::ostream & operator<<(std::ostream & os, const Circle & circle)
{
	os  << circle.center << "|  " << std::setw(3) << std::left << circle.radius;
	return os;
}

bool Circle::operator==(const Circle & other) const
{
	if (center == other.center && radius == other.radius)
		return true;
	else
		return false;
}


void Circle::Print(std::ostream & os, const int count) const
{
	os << std::setw(3) << std::left << count << "| " << *this << std::endl;
}

int CmpRadius(const Circle & first, const Circle &second)
{
	if (first.radius > second.radius)
		return +1;
	else if (first.radius < second.radius)
		return -1;
	else
		return 0;
}

