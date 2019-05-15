// Iter_Alg.cpp : Defines the entry point for the console application.
//
//���������. ����������� ���������. ���������.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <tchar.h>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include "Point.h"
#include "VarTemplateFunc.h"
#include "myRect.h"
using namespace std;	
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{
	
///////////////////////////////////////////////////////////////////
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//������� 1. ���������

	//����������� ���������. ����������� set<Point>. ���������, ���
	//����� ����������� � ������ Point. �������� ������, �������� �������� 
	//�������� ������� ��������� set, �� ����������� �� ��������

	std::set<Point> MySet1{ Point(1,1), Point(1,1), Point(2,2), Point(3,3), Point(0,1), Point(1,1) };
	std::vector<Point> MyVector1(MySet1.rbegin(), MySet1.rend());

	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.
	std::ostream_iterator<Point> out_it(std::cout, "\n");
	std::copy(MySet1.begin(), MySet1.end(), out_it);
	std::cout << "\n";
	std::copy(MyVector1.begin(), MyVector1.end(), out_it);
	//��������� �������. � ������� ������������ ���������:
	//back_inserter()
	//front_inserter()
	//inserter()
	//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
	//����� �� ���������� ������� ����� ������������ � ������ �����������.
	std::back_inserter(MyVector1) = Point(10, 10);
	//std::front_inserter(MyVector1) = Point(-10, -10); ����� ����� push_front
	std::inserter(MyVector1, MyVector1.begin()) = Point(-10, -10);
	std::cout << "\n";
	std::copy(MyVector1.begin(), MyVector1.end(), out_it);
///////////////////////////////////////////////////////////////////

	//������� 2. ���������� ��������� (������������ ���� <algorithm>). ���������.

	// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
	//(������, vector, list...)
	//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
	//������������ �������� ���������
	//��������� : ������� ���������� ������� ���������� ��� ������
	std::cout << "\nfor_each:\n";
	std::for_each(MyVector1.begin(), MyVector1.end(), [](const Point & pt) {std::cout << pt << "\n"; });
	stop

	//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
	//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
	//��� ������) � �������� ��������� � ������� ����������� ���������
	std::cout << "\nfor_each:\n";
	std::for_each(MyVector1.begin(), MyVector1.end(), [x = 0, y = 0](Point & pt) mutable {pt.SetX(x++); pt.SetY(y--); });
	std::for_each(MyVector1.begin(), MyVector1.end(), [](const Point & pt) {std::cout << pt << "\n"; });
	std::back_inserter(MyVector1) = Point(1, 1);
	std::back_inserter(MyVector1) = Point(1, 1);
	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.
	std::cout << "\nfind:\n";
	auto search = std::find(MyVector1.begin(), MyVector1.end(), Point(1, 1));
	while ( search != MyVector1.end())
	{		
		std::cout << *search << "\n"; 
		search = std::find(++search, MyVector1.end(), Point(1, 1));
	}
	
	
	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
	std::cout << "Sort:\n";
	std::sort(MyVector1.begin(), MyVector1.end());
	PrintContainer(MyVector1);

	
	//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
	//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
	//[-n, +m].
	std::cout << "find_if:\n";
	auto pred = [n = 2, m = 4](Point &pt) {
		return (pt.GetX() >= -n && pt.GetX() <= m && pt.GetY() >= -n && pt.GetY() <= m); };
	search = std::find_if(MyVector1.begin(), MyVector1.end(), pred);
	while (search != MyVector1.end())
	{
		std::cout << *search << "\n";
		search = std::find_if(++search, MyVector1.end(), pred);
	}

	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.
	
	std::vector<Rect> MyVector2({ Rect(1,2,1,2), Rect(2,3,2,3), Rect(-1,-2,-1,-3) });
	std::generate_n(std::back_inserter(MyVector2), 20, []() {return Rect(rand() % 20 - 10, rand() % 20 - 10
		, rand() % 20 - 10,	rand() % 20 - 10); });
	PrintContainer(MyVector2);
	auto pred2 = [](const Rect & l, const Rect & r) { int lx1, lx2, ly1, ly2, rx1, rx2, ry1, ry2;
	l.GetAll(lx1, lx2, ly1, ly2); r.GetAll(rx1, rx2, ry1, ry2);
		return (pow((lx1 + lx2) / 2, 2) + pow((ly1 + ly2) / 2, 2)) <
			(pow((rx1 + rx2) / 2, 2) + pow((ry1 + ry2) / 2, 2));
	};
	std::sort(MyVector2.begin(), MyVector2.end(), pred2);
	PrintContainer(MyVector2);
	   
	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()

		std::string MyString1{ "1111ItIsWaLlOfTeXtFoRmAtMe!" };
		std::transform(MyString1.begin(), MyString1.end(), MyString1.begin(), tolower);
		std::cout << MyString1;
		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
	
		std::list<std::string> MyList1{ "ABC", "DBC", "UIR", "oPr" };
		std::set<std::string> MySet1;
		auto trans1 = [](const std::string src) { 
			std::transform(src.begin(), src.end(), src.begin(), tolower);
			return src; };
		std::transform(MyList1.begin(), MyList1.end(), std::inserter(MySet1, MySet1.begin()), trans1);
		PrintContainer(MySet1);
		stop
	}
	{// map
		
		//����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������
	

		//lab 9

		std::vector<std::string> MyVector3{ "ZFT", "ABC", "ABC", "ABC", "DCB", "DCB", "ERT", "ERG" };
		std::map < std::string, int> MyMap1;
		for (auto & value : MyVector3)
			MyMap1[value]++;
		PrintContainer(MyMap1);
	}

	


	return 0;
}

