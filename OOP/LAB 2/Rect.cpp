#include "Rect.h"
#include <iostream>
#include <string>
Rect::Rect(int left, int right, int bottom, int top, Color color) : Shape(color)
{
	m_left = left;
	m_right = right;
	m_bottom = bottom;
	m_top = top;
	//set_color(color);
}

/*Rect::Rect(const Rect & other) : Shape(other)
{
	m_left = other.m_left;
	m_right = other.m_right;
	m_bottom = other.m_bottom;
	m_top = other.m_top;
	//set_color(other.get_color());
}*/

Rect::Rect(const Shape & other) : Shape(other)
{
	m_left = 0;
	m_right = 0;
	m_bottom = 0;
	m_top = 0;
}
/*Rect & Rect::operator=(const Rect & other)
{
	this->m_left = other.m_left;
	this->m_right = other.m_right;
	this->m_bottom = other.m_bottom;
	this->m_top = other.m_top;
	this->set_color(other.get_color());
	return *this;
}*/
Rect::~Rect()
{
	//std::cout << "I'm in Rect destructor!\n";
}
void Rect::print(std::ostream & os) const
{
	static std::string colorname[7]{ "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "White" };
	std::cout << "Rectangle: " << "left = " << m_left << ", right = " << m_right
		<< ", bottom = " << m_bottom << ", top = " << m_top << ", color = ";
	std::cout << colorname[get_color()] << std::endl;
}

void Rect::WhereAmI() const
{
	std::cout << "I'm in Rect class!\n";
}

void Rect::Inflate(int delta)
{
	m_left -= delta;
	m_right += delta;
	m_bottom -= delta;
	m_top += delta;
}