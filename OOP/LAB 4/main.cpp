#include <iostream>
#include <fstream>
#include "List.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(static_cast<size_t>(time(0)));
	List list;
	
	for (size_t i = 0; i < 25; i++)
		list.AddToHead(Circle(rand() % 30, rand() % 30, rand() % 30));
	list.merge_sort(CmpRadius);
	std::cout << "Size: " << list.Size() << std::endl << list;	
	List listnew;
	for (size_t i = 0; i < 15; i++)
		listnew.AddToHead(Circle(rand() % 30, rand() % 30, rand() % 30));
	listnew = std::move( list);
	std::cout << "Size: " << listnew.Size() << std::endl << listnew;
	std::cout << "Size: " << list.Size() << std::endl << list;
	return 0;
}