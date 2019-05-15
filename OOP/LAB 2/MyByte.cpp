#include "MyByte.h"
#include <iostream>
MyByte::MyByte(int byte)
{
	if (byte >> 8 != 0)
	{
		std::cout << "Переданное значение больше байта, установка значений по умолчанию\n";
		m_bin = Bin(0);
		m_oct = Oct(0);
		m_hex = Hex(0);
		m_dec = 0;
	}
	m_bin = Bin(byte); 
	m_oct = Oct(byte); 
	m_hex = Hex(byte); 
	m_dec = byte; 
}


MyByte::~MyByte()
{

}

void MyByte::ShowDecPos(int pos) const
{
	if (pos >= 0 && pos < 3)
	{		
		int temp = m_dec;
		for (int i = 0; i < pos; i++)
			temp /= 10;
		std::cout << "Dec, Pos " << pos << ": " << temp % 10 << std::endl;
	}
	else
		std::cout << "Неправильная позиция!\n";
}

void MyByte::EditDecPos(int pos, int dec)
{
	if (dec < 0 && dec > 9)
	{
		std::cout << "Переданное значение не десятичное число, не меняем значение\n";
	}
	else
	{
		int temp = m_dec;
		switch (pos)
		{
		case 0: temp = (m_dec / 100) * 100 + m_dec / 10 % 10 * 10 + dec;
			break;
		case 1: 
			temp = (m_dec / 100) * 100 + dec * 10 + m_dec % 10;
			break;
		case 2:
			temp = dec * 100 + (m_dec / 10  % 10) * 10 + m_dec % 10;
			break;
		default: std::cout << "Не корректная позиция, не меняем значение\n";
		}
		if (temp > 255)
		{
			std::cout << "Получившиееся число больше байта, сброс значения!\n";
			m_dec = 0;
		}
		else
			m_dec = temp;
	}
}

void MyByte::ShowChar() const
{
	if ((m_dec > 32 && m_dec < 127) || (m_dec > 127))
		std::cout << "Char: " << static_cast<char>(m_dec) << std::endl;
}

void MyByte::ShowInteract() const
{
	std::cout << "Выберите необходимое представление:\n";
	std::cout << "1) Двоичное 2) Восьмеричное 3) Шестнадцатеричное 4) Десятичное 5) Символ\n";
	void (MyByte::*fptr[5]) () const{ &MyByte::ShowBin, &MyByte::ShowOct, 
		&MyByte::ShowHex, &MyByte::ShowDec, &MyByte::ShowChar };
	int choice = 0;
	while (!(std::cin >> choice) || choice - 1 < 0 || choice - 1 > 4)
	{
		std::cout << "Недопустимый выбор, повтрорите:\n";
		std::cin.ignore(20, '\n');
		std::cin.clear();
	}
	(this->*fptr[choice - 1])();
}
void MyByte::ShowPosInteract() const
{
	std::cout << "Выберите необходимое представление:\n";
	std::cout << "1) Двоичное 2) Восьмеричное 3) Шестнадцатеричное 4) Десятичное 5) Символ\n";
	void (MyByte::*fptr[4]) (int ) const { &MyByte::ShowBinPos, &MyByte::ShowOctPos,
		&MyByte::ShowHexPos, &MyByte::ShowDecPos};
	int choice = 0;
	while (!(std::cin >> choice) || choice - 1 < 0 || choice - 1 > 4)
	{
		std::cout << "Недопустимый выбор, повтрорите:\n";
		std::cin.ignore(20, '\n');
		std::cin.clear();
	}
	int posmax[4]{ 7, 2, 1, 2 };
	int pos = 0;
	std::cout << "Выберите позицию > 0 и < " << posmax[choice - 1];
	while (!(std::cin >> choice) || pos < 0 || pos > posmax[choice - 1])
	{
		std::cout << "Недопустимая позиция, повтрорите:\n";
		std::cin.ignore(20, '\n');
		std::cin.clear();
	}
	(this->*fptr[choice - 1])(pos);
}
void MyByte::EditPosInteract()
{
	std::cout << "Выберите необходимое представление:\n";
	std::cout << "1) Двоичное 2) Восьмеричное 3) Шестнадцатеричное 4) Десятичное 5) Символ\n";
	void (MyByte::*fptr[4]) (int, int) {
		&MyByte::EditBinPos, &MyByte::EditOctPos,
			&MyByte::EditHexPos, &MyByte::EditDecPos
	};
	int choice = 0;
	while (!(std::cin >> choice) || choice - 1 < 0 || choice - 1 > 4)
	{
		std::cout << "Недопустимый выбор, повтрорите:\n";
		std::cin.ignore(20, '\n');
		std::cin.clear();
	}
	int posmax[4]{ 7, 2, 1, 2 };
	int pos = 0;
	std::cout << "Выберите позицию >= 0 и < " << posmax[choice - 1]<< ": ";
	while (!(std::cin >> pos) || pos < 0 || pos > posmax[choice - 1])
	{
		std::cout << "Недопустимая позиция, повтрорите:\n";
		std::cin.ignore(20, '\n');
		std::cin.clear();
	}
	int nummax[4]{ 1, 7, 0xE, 9 };
	int num = 0;
	std::cout << "Выберите цифру для ввода > 0 и < " << std::hex << nummax[choice - 1] << std::dec << ": ";
	while (!(std::cin >> std::hex >> num >> std::dec) || num < 0 || num > nummax[choice - 1])
	{
		std::cout << "Недопустимая цифра, повтрорите:\n";
		std::cin.ignore(20, '\n');
		std::cin.clear();
	}
	(this->*fptr[choice - 1])(pos, num);
}