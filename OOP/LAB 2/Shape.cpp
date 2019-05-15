#include "Shape.h"
#include <string>

Shape::Shape(Color color)
{
	if (color >= RED && color <= WHITE)
		m_color = color;
	else
		m_color = WHITE;
}

Shape::~Shape()
{
	//std::cout << "I'm in Shape destructor!\n";
}

Shape::Color Shape::get_color() const
{
	return m_color;
}

void Shape::set_color(Color color)
{
	if (color >= RED && color <= WHITE)
		m_color = color;
	else
		m_color = WHITE;
}

void Shape::WhereAmI() const
{
	std::cout << "I'm in Shape class!\n";
}

std::ostream & operator<<(std::ostream & os, const Shape & shape)
{
	shape.print(os);
	return os;
}