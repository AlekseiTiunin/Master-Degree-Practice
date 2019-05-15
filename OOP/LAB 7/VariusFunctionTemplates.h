#pragma once
#include <iostream>
template <typename T>

void Swap(T& one, T& two)
{
	T temp = std::move(one);
	one = std::move(two);
	two = std::move(temp);
}