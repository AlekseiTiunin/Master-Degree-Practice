#include "ReadFunction.h"

void ReadShape(List<Shape> & list, std::istream &in)
{
	std::string buffer;
	int temp[4];
	Shape::Color col = Shape::White;
	while (std::getline(in, buffer))
	{
		if (std::regex_search(buffer, std::regex(typeid(Rect).name()))) // проверяем тип записанного объекта - Rect или Circle
		{
			if (Shape::ExtractShapeData(buffer, col, temp, 4))
				list.push_back(Rect(temp[0], temp[1], temp[2], temp[3], col));
		}
		else if (std::regex_search(buffer, std::regex(typeid(Circle).name())))
		{
			if (Shape::ExtractShapeData(buffer, col, temp, 3))
				list.push_back(Circle(temp[0], temp[1], temp[2], col));
		}
	}
}