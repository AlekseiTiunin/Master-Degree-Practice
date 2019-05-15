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
	std::cout << "Сработал конструктор!\n";
	m_left = left;
	m_right = right;
	m_bottom = bottom;
	m_top = top;
	Normalize();
}

Rect::Rect(const Rect & other)
{
	ConsDestRatio++;
	std::cout << "Сработал конструктор копирования!";
	m_left = other.m_left;
	m_right = other.m_right;
	m_bottom = other.m_bottom;
	m_top = other.m_top;
}

std::ostream & operator<<(std::ostream & os, const Rect & rect)
{
	std::cout << "Left = " << rect.m_left << " Right = " << rect.m_right <<
		" Bottom = " << rect.m_bottom << " Top = " << rect.m_top << std::endl;
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
	std::cout << "Сработал деструктор!\n";
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

Rect BoundingRect(Rect r1, Rect r2)
{
	int x1[2], x2[2], y1[2], y2[2];
	r1.GetAll(x1[0], x2[0], y1[0], y2[0]); 
	r2.GetAll(x1[1], x2[1], y1[1], y2[1]);
	return Rect(min(x1[0], x1[1]), max(x2[0], x2[1]), min(y1[0], y1[1]), max(y2[0], y2[1]));
}

Rect BoundingRect2(const Rect & r1, const Rect & r2)
{
	int x1[2], x2[2], y1[2], y2[2];
	r1.GetAll(x1[0], x2[0], y1[0], y2[0]);
	r2.GetAll(x1[1], x2[1], y1[1], y2[1]);
	return Rect(min(x1[0], x1[1]), max(x2[0], x2[1]), min(y1[0], y1[1]), max(y2[0], y2[1]));
}

int min(int x, int y)
{
	return (x <= y ? x : y);
}

int max(int x, int y)
{
	return (x >= y ? x : y);
}

void Rect::BoundingRect(const Rect & r1, const Rect & r2)
{
	m_left = min(r1.m_left, r2.m_left);
	m_right = max(r1.m_right, r2.m_right);
	m_bottom = min(r1.m_bottom, r2.m_bottom);
	m_top = max(r1.m_top, r2.m_top);
}