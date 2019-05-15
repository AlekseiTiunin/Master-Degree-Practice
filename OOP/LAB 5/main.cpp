#include <iostream>
#include "String.h"
#include <cctype>
int main()
{
	while(1)
	{
		String * test[3] = { new String{"atest1"},new String{"dtest2"},new String{"btest3"} };
		String m;
		m.SetNewString("etest1");
		String::SortAlpha();
		String::PrintAll(std::cout);
		std::cout << *test[0];
		for (size_t i = 0; i < 3; i++)
			delete test[i];
		String::SortAlpha();
		String::PrintAll(std::cout);
	}
}