#include "Circle.h"
#include <iomanip>
bool Circle::operator==(const Circle & other) const
{
	if (const Circle * another = dynamic_cast<const Circle* >(&other))
		if (radius == other.radius && center == other.center && this->Shape::operator==(other))
			return true;
	return false;
}

void Circle::Print(std::ostream & os) const
{
	os << std::fixed << std::setprecision(2) <<typeid(Circle).name() << ": center: " << center << ", radius = " << radius << ", ";
	this->Shape::Print(os);
}

int CmpRadius(const Circle &one, const Circle &two)
{
	if (one.radius > two.radius)
		return 1;
	else if (one.radius < two.radius)
		return -1;
	else
		return 0;
}