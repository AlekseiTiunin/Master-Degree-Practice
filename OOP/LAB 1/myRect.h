#pragma once
#include <iostream>

class Rect{
	int m_left, m_right, m_top, m_bottom;
	void Swap(int & x, int &y);

public:
	Rect(int left = 0, int right = 0, int bottom = 0, int top = 0);
	Rect(const Rect & other);
	~Rect();
	friend std::ostream & operator<<(std::ostream & os, const Rect & rect);
	friend std::istream & operator>>(std::istream & is,Rect & rect);
	void InflateRect(int left_inc, int right_inc, int bottom_inc, int top_inc);
	void InflateRect(int vert_inc = 1, int horiz_inc = 1);
	void SetAll(int left, int right, int bottom, int top);
	void GetAll(int & x1, int & x2, int & x3, int & x4) const;
	void Normalize();
	void BoundingRect(const Rect & r1, const Rect & r2);
};

int min(int x, int y);
int max(int x, int y);
Rect BoundingRect2(const Rect & r1, const Rect & r2);
Rect BoundingRect(Rect r1, Rect r2);