#pragma once
class Hex
{
private:
	unsigned int m_hex0 : 4;
	unsigned int m_hex1 : 4;
	Hex(int byte = 0);
	Hex(const Hex &other);
	~Hex();
	void Show() const;
	void ShowPos(size_t pos) const;
	void EditPos(size_t pos, int hesx);
	friend union MyByte;
};

