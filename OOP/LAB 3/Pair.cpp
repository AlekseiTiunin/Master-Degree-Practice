#include "Pair.h"

bool Pair::operator==(const char * key) const
{
	return (this->key == key);
}

std::ostream & operator<<(std::ostream & os, const Pair & pair)
{
	os << "Èìÿ: " << pair.key << ", "<< pair.data;
	return os;
}