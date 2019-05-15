#pragma once
#include <iostream>
class Shape
{
public:
	enum Color { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, WHITE };
private:
	Color m_color;	
public:
	Shape(Color color = WHITE);
	~Shape();
	Color get_color() const;
	void set_color(Color color);
	virtual void WhereAmI() const;
	virtual void Inflate(int delta = 0) = 0;
	friend std::ostream & operator<<(std::ostream & os, const Shape & shape);
protected:
	virtual void print(std::ostream& os) const = 0;
};

