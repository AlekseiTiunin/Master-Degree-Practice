#include "Rect.h"

bool Rect::operator==(const Rect & other) const
{
	if (const Rect * another = dynamic_cast<const Rect*>(&other))
		if (leftBottom == other.leftBottom && rightTop == other.rightTop && this->Shape::operator==(other))
			return true;
	return false;
}
Rect::Rect(int left, int bottom, int right, int top, Color col) : Shape(col) 
{ 	
	NormalizeSet(left, bottom, right, top);
	square = CalcSquare();
};

void Rect::NormalizeSet(int left, int bottom, int right, int top)
{
	if (left > right)
		std::swap(left, right);
	if (bottom > top)
		std::swap(bottom, top);
	SetCoordinate(left, bottom, right, top);
}