#pragma once
#include <iostream>
#include <string>

class Shape
{
public:
	enum Color { White, Red, Black };	
protected:
	Color color;
	double square;
	virtual double CalcSquare() = 0;	
	static const char * colorName[3];	
public:
	Shape(Color col = White, double sq = 0) : color(col), square(sq) {};
	virtual Shape * Clone() const = 0;
	virtual Shape & operator=(const Shape & other) = 0 { color = other.color; square = other.square; return *this; }
	~Shape() = default;
	void SetColor(Color col) { color = col; }
	Color GetColor() { return color; }
	virtual void Print(std::ostream & os) const { os << "color: " << colorName[color] << ", square: " << square; };
	virtual bool operator==(const Shape & other) const;
	static bool ExtractShapeData(std::string buffer, Shape::Color &col, int * store, size_t num);
	friend std::ostream & operator<<(std::ostream & os, const Shape & shape) {shape.Print(os); return os; }
	friend int CmpSquare(const Shape &, const Shape &);
	friend int CmpColor(const Shape &, const Shape &);	
};

int CmpSquare(const Shape &, const Shape &);
int CmpColor(const Shape &, const Shape &);