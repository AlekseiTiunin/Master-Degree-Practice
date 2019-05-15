#include "Shape.h"
#include <regex>

const char * Shape::colorName[3] = { "White", "Red", "Black" };

bool Shape::operator==(const Shape & other) const
{
	if (color == other.color)
		return true;
	else
		return false;
}

int CmpSquare(const Shape &one, const Shape &two)
{
	if (one.square > two.square)
		return 1;
	else if (one.square < two.square)
		return -1;
	else
		return 0;
}

int CmpColor(const Shape &one, const Shape &two)
{
	if (one.color > two.color)
		return 1;
	else if (one.color < two.color)
		return -1;
	else
		return 0;
}

bool Shape::ExtractShapeData(std::string buffer, Shape::Color &col, int * store, size_t num)
{
	std::regex e("\\d+");
	std::smatch m;
	size_t count = 0;

	while (std::regex_search(buffer, m, e) && count < num)
	{
		store[count++] = std::stoi(m[0]);
		buffer = m.suffix().str();
	}
	for (size_t i = 0; i < 3; i++)
	{
		std::regex color(Shape::colorName[i]);
		if (std::regex_search(buffer, m, color))
			col = static_cast<Shape::Color>(i);
	}
	if (count == num)
		return true;
	else
		return false;
}


