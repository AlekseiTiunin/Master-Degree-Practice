#pragma once
#include "Shape.h"
#include "Point.h"
#include <iomanip>
#include <stdexcept>
class Rect :
	public Shape
{
private:
	Point leftBottom, rightTop;
	double CalcSquare() { return (rightTop.DistanceX(leftBottom)) * (rightTop.DistanceY(leftBottom)); }
	void NormalizeSet(int left, int bottom, int right, int top);
public:
	Rect(int left = 0, int bottom = 0, int right = 0, int top = 0, Color col = White);
	Shape * Clone() const { return new Rect(*this); } 
	Rect & operator=(const Shape & other) { *this = static_cast<const Rect &>(other); return *this; };
	void GetCoordinates(int & left, int &bottom, int &right, int &top) { leftBottom.Get(left, bottom); rightTop.Get(right, top); };
	void SetCoordinate(int left, int bottom, int right, int top) { leftBottom.Set(left, bottom); rightTop.Set(right, top); square = CalcSquare(); };
	void Print(std::ostream & os) const {
		os << std::fixed << std::setprecision(2) << typeid(Rect).name() << ": " << "left bottom: " <<leftBottom << ", right top: " << rightTop << ", ";
		this->Shape::Print(os);
	}
	bool operator==(const Rect & other) const;
	~Rect() {};
};

