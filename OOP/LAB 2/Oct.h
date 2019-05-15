#pragma once
class Oct
{
private:
	unsigned int m_oct0 : 3;
	unsigned int m_oct1 : 3;
	unsigned int m_oct2 : 2;
	Oct(int byte = 0);
	Oct(const Oct &other);
	~Oct();
	void Show() const;
	void ShowPos(size_t pos) const;
	void EditPos(size_t pos, int oct);
	friend union MyByte;
};

