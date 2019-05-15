#pragma once

#include <algorithm>
#include <iterator>
#include <type_traits>
#include <iostream>
#include <queue>

template <typename T>
void PrintSTLAdapter(T container, const char * separatory = " ",std::ostream & os = std::cout)
{		
	while (container.size() > 0)
	{
		if constexpr (std::is_same<std::queue<typename T::value_type, typename T::container_type>, T>::value)
			if constexpr (!std::is_pointer<typename T::value_type>::value || std::is_same <typename T::value_type, const char *>::value)
				std::cout << container.front() << separatory;
			else
				std::cout << *container.front() << separatory;
		else 
			if constexpr (!std::is_pointer<typename T::value_type>::value || std::is_same <typename T::value_type, const char *>::value)
				std::cout << container.top() << separatory;
			else
				std::cout << *container.top() << separatory;
		container.pop();
	}
	os << "\n";
}
template <typename U>
void PrintContainer(U & container, char separator = '\n')
{
	for (auto & val : container)
		if constexpr (!std::is_pointer<typename U::value_type>::value || std::is_same <typename U::value_type, const char *>::value)
			std::cout << val << separator;
		else
			std::cout << *val << separator;
	std::cout << std::endl;
}

template <typename T, typename U>
std::ostream & operator<<(std::ostream & os, const std::set<T, U> data)
{
	PrintContainer(data, ' ');
	return os;
}

template <typename T, typename U>
std::ostream & operator<<(std::ostream & os, const std::multiset<T, U> data)
{
	PrintContainer(data, ' ');
	return os;
}

template <typename T, typename U>
std::ostream & operator<<(std::ostream & os, const std::pair<T, U> data)
{
	return os << data.first << " " << data.second;
}








