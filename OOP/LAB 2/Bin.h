#pragma once
class Bin
{
private:
	unsigned char m_bin0 : 1;
	unsigned char m_bin1 : 1;
	unsigned char m_bin2 : 1;
	unsigned char m_bin3 : 1;
	unsigned char m_bin4 : 1;
	unsigned char m_bin5 : 1;
	unsigned char m_bin6 : 1;
	unsigned char m_bin7 : 1;
	Bin(int byte = 0);
	Bin(const Bin &other);
	~Bin();
	void Show() const;
	void ShowPos(size_t pos) const;
	void EditPos(size_t pos, int bin);
	friend union MyByte;
};

