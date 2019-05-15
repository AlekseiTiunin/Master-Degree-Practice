#include "Barrel.h"
Barrel::Barrel()
{
	volume = 0;
	concentration = 0;
}
Barrel::Barrel(double volume, double concentration)
{	
	if (volume > 0)
		Barrel::volume = volume;
	else
	{
		std::cout << "Объем меньше 0, установка значения по умолчанию (0)\n";
		Barrel::volume = 0;
	}
	if (concentration >= 0 && concentration <= 1)
	{
		Barrel::concentration = concentration;
	}
	else
	{
		std::cout << "Недопустимое значение концентрации, установка значения по умолчанию (1)\n";
		Barrel::concentration = 1;
	}
}

Barrel::Barrel(const Barrel & other)
{	
	volume = other.volume;
	concentration = other.concentration;
}

Barrel & Barrel::operator=(const Barrel & other)
{
	volume = other.volume;
	concentration = other.concentration;
	return *this;
}

Barrel::~Barrel()
{
}
std::ostream & operator<<(std::ostream & os, const Barrel & barrel)
{	
	std::cout << barrel.volume << "l, " << static_cast<int> (barrel.concentration * 100) << "% ";
	std::cout << "s = " << barrel.volume * barrel.concentration << " w=" << barrel.volume * (1 - barrel.concentration) <<std::endl;
	return os;
}

void Barrel::pour(Barrel & other, double pourvolume)
{
	if (other.volume >= pourvolume)
	{		
		concentration = (pourvolume*other.concentration + volume * concentration) / (volume + pourvolume);
		volume += pourvolume;
		other.volume -= pourvolume;
	}
	else
		std::cout << "В бочке недостаточно жидкости!\n";
}

double Barrel::getconcentration() const
{
	return concentration;
}