#include "Circle.h"
#include <string>
Circle::Circle(int center_x, int center_y, int radius, Color color) : Shape(color)
{
	m_center_x = center_x;
	m_center_y = center_y;
	m_radius = radius;
}
/*Circle::Circle(const Circle & other) : Shape(other)
{
	m_center_x = other.m_center_x;
	m_center_y = other.m_center_y;
	m_radius = other.m_radius;
}*/

Circle::Circle(const Shape & other) : Shape(other)
{
	m_center_x = 0;
	m_center_y = 0;
	m_radius = 0;
}
/*Circle & Circle::operator=(const Circle & other)
{
	m_center_x = other.m_center_x;
	m_center_y = other.m_center_y;
	m_radius = other.m_radius;
	set_color(other.get_color());
	return *this;
}*/

Circle::~Circle()
{
	//std::cout << "I'm in Circle destructor!\n";
}

void Circle::print(std::ostream &os) const
{
	static std::string colorname[7]{ "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "White" };
	std::cout << "Circle: " << "center_x = " << m_center_x << ", center_y = " << m_center_y
		<< ", radius = " << m_radius <<  ", color = ";
	std::cout << colorname[get_color()] << std::endl;
}

void Circle::WhereAmI() const
{
	std::cout << "I'm in Circle class!\n";
}

void Circle::Inflate(int delta)
{
	m_radius += delta;
}