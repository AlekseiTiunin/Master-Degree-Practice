#include "Oct.h"
#include <iostream>

Oct::Oct(int byte)
{
	if (byte >> 8 != 0)
	{
		std::cout << "Переданное значение больше байта, установка значений по умолчанию\n";
		m_oct0 = 0;
		m_oct1 = 0;
		m_oct2 = 0;
	}
	else
	{
		unsigned char mask = 0b111;
		m_oct0 = byte & mask;
		m_oct1 = byte >> 3 & mask;
		m_oct2 = byte >> 6 & mask;
	}
}

Oct::Oct(const Oct &other)
{
	m_oct0 = other.m_oct0;
	m_oct1 = other.m_oct1;
	m_oct2 = other.m_oct2;
}

Oct::~Oct()
{

}

void Oct::Show() const
{
	std::cout << "Oct: " << m_oct2 << m_oct1 << m_oct0 << std::endl;
}


void Oct::ShowPos(size_t pos) const
{
	if (pos < 3 && pos >= 0)
	{
		const unsigned int temp[3] = { m_oct0, m_oct1, m_oct2 };
		std::cout << "Oct, Pos " << pos << ": " << temp[pos] << std::endl;
	}
	else 
		std::cout << "Неправильная позиция!\n";
}

void Oct::EditPos(size_t pos, int oct)
{
	if (oct >> 3 != 0)
	{
		std::cout << "Переданное значение не восьмеричное число, не меняем значение\n";
	}
	else if (pos == 2 && m_oct1 == 7 && m_oct0 == 7 && oct > 3)
	{
		std::cout << "Получившиееся число больше байта, сброс значения!\n";
		*this = Oct();
	}
	else
	{
		switch (pos)
		{
		case 0: m_oct0 = oct;
			break;
		case 1: m_oct1 = oct;
			break;
		case 2: m_oct2 = oct;		
			break;
		default: std::cout << "Не корректная позиция, не меняем значение\n";
		}
	}
	
}
