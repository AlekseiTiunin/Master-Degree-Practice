#include "Shape.h"
#include "Rect.h"
#include "Circle.h"
#include "List.hpp"
#include "ReadFunction.h"
#include <cstdlib>
#include <ctime>

template<typename T>
int cmp(const T &one, const T &two)
{
	if (one > two)
		return 1;
	else if (one < two)
		return -1;
	else
		return 0;
}

int main()
{
	while (1)
	{
		srand(size_t(time(0)));

		{
			List<Shape> * list = new List<Shape>;
			for (size_t i = 0; i < 5; i++)
			{
				if (rand() % 2)
					list->push_back(Rect(rand() % 10, rand() % 10, rand() % 10, rand() % 10, static_cast<Shape::Color>(rand() % 3)));
				else
					list->push_back(Circle(rand() % 10, rand() % 10, rand() % 10, static_cast<Shape::Color>(rand() % 3)));
			}
			List<Shape> listnew;
			listnew.push_back(Rect());
			listnew.push_back(Rect());
			std::cout << *list;
			listnew = *list;
			//listnew.merge_sort(CmpSquare);
			
			delete list;
			std::cout << listnew;
			//listnew.SaveToFile("listnew.txt");
			/*try
			{
			listnew.ReadFromFile("listnew.txt", ReadShape);
			}
			catch(int a)
			{
				std::cout << "Catch exception number " << a << std::endl;
			}
			std::cout << listnew;*/
		}
		std::cin.get();
	}
}