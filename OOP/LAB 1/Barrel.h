#pragma once
#include <iostream>
class Barrel
{
public:
private:
	double volume;
	double concentration;
public:	
	Barrel();
	Barrel(double volume, double concentration);
	Barrel(const Barrel & other);
	Barrel & operator=(const Barrel & other);
	~Barrel();
	friend std::ostream & operator<<(std::ostream & os, const Barrel & barrel);
	void pour(Barrel & other, double pourvolume);
	double getconcentration() const;
};