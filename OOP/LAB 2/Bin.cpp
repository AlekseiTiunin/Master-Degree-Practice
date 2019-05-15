#include "Bin.h"
#include <iostream>

Bin::Bin(int byte)
{
	if (byte >> 8 != 0)
	{
		std::cout << "Переданное значение больше байта, установка значений по умолчанию\n";
		m_bin0 = 0;
		m_bin1 = 0;
		m_bin2 = 0;
		m_bin3 = 0;
		m_bin4 = 0;
		m_bin5 = 0;
		m_bin6 = 0;
		m_bin7 = 0;
	}
	else
	{
		unsigned char mask = 0b1;
		m_bin0 = byte & mask;
		m_bin1 = byte >> 1 & mask;
		m_bin2 = byte >> 2 & mask;
		m_bin3 = byte >> 3 & mask;
		m_bin4 = byte >> 4 & mask;
		m_bin5 = byte >> 5 & mask;
		m_bin6 = byte >> 6 & mask;
		m_bin7 = byte >> 7 & mask;
	}
}

Bin::Bin(const Bin &other)
{
	m_bin0 = other.m_bin0;
	m_bin1 = other.m_bin1;
	m_bin2 = other.m_bin2;
	m_bin3 = other.m_bin3;
	m_bin4 = other.m_bin4;
	m_bin5 = other.m_bin5;
	m_bin6 = other.m_bin6;
	m_bin7 = other.m_bin7;
}

Bin::~Bin()
{

}

void Bin::Show() const
{
	//bool tmp[] = { m_bin7 ,}
	std::cout << "Bin: " << static_cast<bool>(m_bin7) 
		<< static_cast<bool>(m_bin6)
		<< static_cast<bool>(m_bin5)
		<< static_cast<bool>(m_bin4)
		<< static_cast<bool>(m_bin3)
		<< static_cast<bool>(m_bin2)
		<< static_cast<bool>(m_bin1)
		<< static_cast<bool>(m_bin0)
		<< std::endl;
}


void Bin::ShowPos(size_t pos) const
{
	if (pos >= 0 && pos < 8)
	{
		int temp[8] = { m_bin0, m_bin1, m_bin2, m_bin3, m_bin4, m_bin5, m_bin6, m_bin7 };
		std::cout << "Bin, Pos " << pos << ": " << temp[pos] << std::endl;
	}
	else
		std::cout << "Неправильная позиция!\n";
}

void Bin::EditPos(size_t pos, int bin)
{
	if (bin >> 1 != 0)
	{
		std::cout << "Переданное значение не 0 или 1, не меняем значение\n";
	}
	else
	{
		switch (pos)
		{
		case 0: m_bin0 = bin;
			break;
		case 1: m_bin1 = bin;
			break;
		case 2: m_bin2 = bin;
			break;
		case 3: m_bin3 = bin;
			break;
		case 4: m_bin4 = bin;
			break;
		case 5: m_bin5 = bin;
			break;
		case 6: m_bin6 = bin;
			break;
		case 7: m_bin7 = bin;
			break;
		default: std::cout << "Не корректная позиция, не меняем значение\n";
		}
	}
}
