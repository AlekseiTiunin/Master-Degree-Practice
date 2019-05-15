#pragma once
#include "Bin.h"
#include "Oct.h"
#include "Hex.h"
#include <iostream>
union MyByte
{
private:
	Bin m_bin;
	Oct m_oct;
	Hex m_hex;
	unsigned char m_dec;

public:
	MyByte(int byte = 0);
	~MyByte();
	void ShowInteract() const;
	void ShowPosInteract() const;
	void EditPosInteract();
	void ShowBin() const { m_bin.Show(); }
	void ShowOct() const { m_oct.Show(); }
	void ShowHex() const { m_hex.Show(); }
	void ShowDec() const { std::cout << "Dec: " << static_cast<int> (m_dec) << std::endl; }
	void ShowChar() const;
	void ShowBinPos(int pos) const { m_bin.ShowPos(pos); }
	void ShowOctPos(int pos) const { m_oct.ShowPos(pos); }
	void ShowHexPos(int pos) const { m_hex.ShowPos(pos); }
	void ShowDecPos(int pos) const;
	void EditBinPos(int pos, int bin) { m_bin.EditPos(pos, bin); }
	void EditOctPos(int pos, int oct) { m_oct.EditPos(pos, oct); }
	void EditHexPos(int pos, int hex) { m_hex.EditPos(pos, hex); }
	void EditDecPos(int pos, int dec);
};

