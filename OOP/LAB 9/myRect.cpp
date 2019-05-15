#include "myRect.h"
#include <iostream>
#include <cmath>
/*Rect::Rect()
{
	std::cout << "Default constructor called.\n"; // логичнее использовать аргументы по умолчанию?
}*/
int ConsDestRatio = 0;

Rect::Rect(int left, int right, int bottom, int top)
{
	ConsDestRatio++;
	m_left = left;
	m_right = right;
	m_bottom = bottom;
	m_top = top;
	Normalize();
}

Rect::Rect(const Rect & other)
{
	ConsDestRatio++;
	m_left = other.m_left;
	m_right = other.m_right;
	m_bottom = other.m_bottom;
	m_top = other.m_top;
}

std::ostream & operator<<(std::ostream & os, const Rect & rect)
{
	std::cout << "Left = " << rect.m_left << " Right = " << rect.m_right <<
		" Bottom = " << rect.m_bottom << " Top = " << rect.m_top 
		<< " Distance = " << sqrt(pow((rect.m_left + rect.m_right) / 2, 2) + 
			pow((rect.m_top + rect.m_bottom) / 2, 2)) << std::endl;
	return os;
}
std::istream & operator>>(std::istream & is, Rect & rect)
{
	std::cout << "Left = ";
	std::cin >> rect.m_left;
	std::cout << "Right = ";
	std::cin >> rect.m_right;	
	std::cout << "Bottom = ";
	std::cin >> rect.m_bottom;
	std::cout << "Top = ";
	std::cin >> rect.m_top;
	rect.Normalize();
	return is;
}

void Rect::InflateRect(int left_inc, int right_inc, int bottom_inc, int top_inc)
{
	m_left -= left_inc;
	m_right += right_inc;	
	m_bottom -= bottom_inc;
	m_top += top_inc;
	Normalize();
}

void Rect::InflateRect(int vert_inc, int horiz_inc)
{
	this->InflateRect(vert_inc, vert_inc, horiz_inc, horiz_inc);
	Normalize();
}

void Rect::SetAll(int left, int right, int bottom, int top)
{
	*this = Rect(left, right, bottom, top);
	Normalize();
}

void Rect::GetAll(int & x1, int & x2, int & y1, int & y2) const
{
	x1 = m_left;
	x2 = m_right;
	y1 = m_bottom;
	y2 = m_top;
}

Rect::~Rect()
{
	ConsDestRatio--;
}

void Rect::Swap(int & x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void Rect::Normalize()
{
	if (m_left > m_right)
		Swap(m_left, m_right);
	if (m_bottom > m_top)
		Swap(m_bottom, m_top);
}
