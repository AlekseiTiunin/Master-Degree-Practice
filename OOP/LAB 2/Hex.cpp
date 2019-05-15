#include "Hex.h"
#include <iostream>


Hex::Hex(int byte)
{
	if (byte >> 8 != 0)
	{
		std::cout << "ѕереданное значение больше байта, установка значений по умолчанию\n";
		m_hex0 = 0;
		m_hex1 = 0;
	}
	else
	{
		unsigned char mask = 0b1111;
		m_hex0 = byte & mask;
		m_hex1 = byte >> 4 & mask;
	}
}

Hex::Hex(const Hex &other)
{
	m_hex0 = other.m_hex0;
	m_hex1 = other.m_hex1;
}

Hex::~Hex()
{

}

void Hex::Show() const
{
	std::cout << "Hex: " << std::hex << m_hex1 << m_hex0 << std::dec << std::endl;
}


void Hex::ShowPos(size_t pos) const
{
	if (pos < 2 && pos >= 0)
	{
		const unsigned int temp[2] = { m_hex0, m_hex1 };
		std::cout << "Hex, Pos " << std::hex << pos << ": " << temp[pos] << std::dec << std::endl;
	}
	else
		std::cout << "Ќеправильна€ позици€!\n";
}

void Hex::EditPos(size_t pos, int hex)
{
	if (hex >> 4 != 0)
	{
		std::cout << "ѕереданное значение не шестнадцатиричное число, не мен€ем значение\n";
	}
	else
	{
		switch (pos)
		{
		case 0: m_hex0 = hex;
			break;
		case 1: m_hex1 = hex;
			break;
		default: std::cout << "Ќе корректна€ позици€, не мен€ем значение\n";
		}
	}
}
