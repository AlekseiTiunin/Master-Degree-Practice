#pragma once
#include <vector>
#include <unordered_set>
#include <type_traits>
#include <deque>
#include <algorithm>

template <typename U> // через constexp if сделать единый шаблон , 
void PrintVector(const std::vector<U> & container)
{
	size_t size = container.size();
	std::cout << "size =  " << container.size() << ", capacity = " << container.capacity() << ", max_size = " << container.max_size() << std::endl;
	for (size_t i = 0; i < size; i++)
		if constexpr(!std::is_pointer<typename vector<U>::value_type>:: value)
			std::cout << container[i] << " ";
		else
			std::cout << *container[i] << " ";
	std::cout << std::endl;
}
template <typename T> 
bool IsInContainer(const T & container, const typename T::value_type & data)
{
	for (const auto & val : container)
		if (val == data)
			return true;
	return false;
}

template <typename T>
void EraseRepeats(T & container) //Erase-remove idiom
{
	std::unordered_set<typename T::value_type> s;
	auto end = std::remove_if(container.begin(), container.end(), 
		[&s](typename T::value_type & val) {
		return !s.insert(val).second;});
	container.erase(end, container.end());
}

template <typename U>
void PrintContainer(U & container)
{
	std::cout << "Container type = " << typeid(container).name() << ", size =  " << container.size() << std::endl;
	for (auto & val : container)
		if constexpr (!std::is_pointer<typename U::value_type>::value)
			std::cout << val << "\n";
		else
			std::cout << *val << "\n";
	std::cout << std::endl;
}
