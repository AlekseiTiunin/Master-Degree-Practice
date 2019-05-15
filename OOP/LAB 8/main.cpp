//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <stdexcept>
#include "VarFunctionTemplates.h"
#include "myString.h"
#include "Point.h"
#pragma warning(disable: 4786)

template <typename T>
std::ostream & operator<<(std::ostream & os, const std::vector<T>&  vect)
{
	PrintContainer(vect);
	return os;
}
template <typename T>

std::ostream & operator<<(std::ostream & os, const std::vector<T>&  vect)
{
	for( const auto& v:vect)
	{
		os << v;
	}
	return os;
}
using namespace std;	

#define	  stop __asm nop
#define cur_ex 2
int main()
{
	srand(time(0));
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 
#if cur_ex == 1
	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 

	std::vector<int> vInt;
	
	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������

	vInt.resize(1);
	vInt.front()=1;


	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	//
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.
	for (size_t i = 0; i < 10; i++)
	{
		vInt.push_back(rand() % 10);
		PrintVector(vInt);
	}
	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?
	
	std::vector<double> vDouble(10);
	PrintVector(vDouble);

	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 

	std::vector<MyString> vMyString(5, "A");	
	vMyString.at(0) = "B";
	vMyString[1] = "C";
	PrintVector(vMyString);
	try
	{
		//vMyString.at(6);
		//vMyString[6];
	}
	catch (std::out_of_range except)
	{
		std::cout << "Exception: " << except.what() << std::endl;
	}
	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!
	
	std::vector<double> dMas{ 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7 };
	std::vector<double> vDouble3(dMas.begin(), dMas.begin() + 5);
	PrintVector(vDouble3);
	

	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 

	std::vector<double> vDouble4(dMas.begin() + 2, dMas.begin() + 5);
	PrintVector(vDouble4);

	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).

	std::vector<Point> vPoint1(3);
	PrintVector(vPoint1);
	std::vector<Point> vPoint2(5, { 1,1 });
	PrintVector(vPoint2);
	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{
		std::vector<Point *> vpPoint(5);
	//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
		//�) ������������� ����� ��������� �������
		//�) ��� ���������� operator<< ��� Point*
		for (auto & val : vpPoint)
			val = new Point(rand() % 10, rand() % 10);
		PrintVector(vpPoint);
		for (auto & val : vpPoint)
			delete val;
	}//����� �������������� �������� ����� ����������� ��� ������ �������?
#endif
#if cur_ex == 2
	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
		
		{
			size_t n = 10;
			std::vector<int> v(n);
			v.resize(n/2); // ������ ������, �� �� �����������
			if (v.capacity() == n)
			{
				std::cout << "true\n"; //true? ��
			}
			else
			{
				std::cout << "false\n";
			}
		}
		

		
		{
			int n = 10;
			size_t m = 15;
			std::vector<int> v(n);
			v.reserve(m);
			if(v.capacity() == m)
			{
				std::cout << "true\n"; //true? ��
			}
			else
			{
				std::cout << "false\n";
			}
		}
		

		
		{
			vector<int> v(3,5); // 5 5 5
			PrintContainer(v);
			v.resize(4,10); //��������? 5 5 5 10
			PrintContainer(v);
			v.resize(5); //��������? 5 5 5 10 0
			PrintContainer(v);	
		}


	//�������� ��� "������" ������� � ����������
	//������ (�� ������ � ���� �� ����) ����. 
	//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	//��� ���������� � ������� push_back.
	//������ ������ ������ ��������� ���������� ����������� push_back.
	//
	//�������� ������, ������� �������� � �������� ���������

		std::vector<int> vInt1;
		std::vector<int> vInt2;

		vInt1.reserve(5);
		for (size_t i = 0; i < 5; i++)
			vInt1.push_back(rand() % 10);
		for (size_t i = 0; i < 5; i++)
			vInt2.push_back(rand() % 10);
		PrintContainer(vInt1); // size 5, cap 5
		PrintContainer(vInt2); // size 5, cap 6, ����������� 


	//!!! shrink_to_fit - ���������� ������� �������.
	//��� ������ ������� �� ����������� ������� ��������� ��������� �������
	//�� size.

		vInt2.shrink_to_fit();
		PrintContainer(vInt2);
	

	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2
	//vv[2] - �������� 4,4,4,4
	//...
	//������������ ���������� ������ ����������� ������� �� �������
		int ar[] = { 11,2,4,3,5 };
		std::vector<std::vector<int>> vect2d({{std::vector<int>(11,11)}, std::vector<int>(2,2), 
			std::vector<int>(4,4), std::vector<int>(ar, ar + std::size(ar)) });
		//for (auto val : vect2d)
		//	PrintContainer(val);
		std::cout << "PRINTNEW!!!\n";
		std::cout << vect2d;
		stop
#endif
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if cur_ex == 3
	//������� �������� ������������������ insert().
	//� ������ vChar2 �������� � ������ ������� ������ ������ ���
	//�������, ��� � ������� ������ ��� ���.

	std::vector<char> vChar2{ 'A', 'B', 'C' };
	for (char ch = 'A'; ch != 'F'; ch++)
		if (!IsInContainer(vChar2, ch))
			vChar2.insert(vChar2.begin(), ch);
	PrintVector(vChar2);

	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'
	
	for (auto iter = vChar2.begin(); iter != vChar2.end(); )
	{
		auto save = iter - vChar2.begin();
		vChar2.insert(iter, 'W');
		iter = vChar2.begin() + save + 2;
	}
	PrintVector(vChar2);

///////////////////////////////////////////////////////////////////
	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
	char str[] = "qwerrrrty12222r33";
	std::vector<char> vChar3(str, str + std::size(str) - 1);
	PrintVector(vChar3);
	for (size_t i = 0; i < vChar3.size() - 1;)
		if (vChar3[i] == vChar3[i + 1])
			vChar3.erase(vChar3.begin() + i + 1);
		else
			i++;
	PrintVector(vChar3);

#endif
stop

///////////////////////////////////////////////////////////////////

#if cur_ex == 4
	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 

	char str[] = "qwerrrrty12222r33";
	std::vector<char> vChar3(str, str + std::size(str) - 1);
	PrintVector(vChar3);
	EraseRepeats(vChar3);
	PrintVector(vChar3);
	   
///////////////////////////////////////////////////////////////////
	//�������� ����� ������ ����� �������, ����� ��� �������� �����
	//������� ��������� ������ �� ��������� ����� ��������, �� �����������
	//���� �� � �������� �������

	std::vector<char> vChar4(vChar3.rbegin(), vChar3.rend());
	PrintVector(vChar4);

#endif
///////////////////////////////////////////////////////////////////
#if cur_ex == 5 
	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()

	std::list<Point> ptList1;
	for(size_t i = 0 ; i < 10; i++)
		ptList1.push_back(Point(rand() % 20 - 10, rand() % 20 - 10));
	ptList1.push_back(Point(1, 1));
	ptList1.push_back(Point(2, 2));
	ptList1.push_back(Point(2, 2));
	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.

	PrintContainer(ptList1);

	//�������� ����� �� ������� "�����������" - reverse()
	ptList1.reverse();
	PrintContainer(ptList1);

	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� 

	std::list<Point> ptList2(ptList1.rbegin(), ptList1.rend());
	PrintContainer(ptList2);

	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������

	ptList1.sort();
	ptList2.sort();
	PrintContainer(ptList1);
	PrintContainer(ptList2);
	stop

		//���������� ��������������� ������ - merge(). ����������: ���
		//��� ���� ���������� � ������ �������.

	ptList1.merge(ptList2);
	PrintContainer(ptList1);
	PrintContainer(ptList2);
	stop

		//���������� �������� �� ������ - remove()
		//��������� �� ������ ������� � ������������ ���������.
		//���������: ��� ������ ���� ����������� � ������ Point?

	ptList1.remove(Point(1, 1));
	PrintContainer(ptList1);
	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 
	ptList1.remove_if([](const Point & point) {return (point.GetX() < 0 || point.GetY() < 0); });
	PrintContainer(ptList1);
	//���������� �� ������ ������ ������������� ������ - unique(). 
	ptList1.unique();
	PrintContainer(ptList1);
	stop
#endif
#if cur_ex == 6
		///////////////////////////////////////////////////////////////////
			//������� 2.������� � ����� ������� - ��������� deque

			//�������� ������ deque � ���������� ���� Point. � �������
			//assign ��������� deque ������� ��������� �������. � �������
			//�������������� ���� � ���������� ������� �������������� �������
			//�������� �������� ��������� �� ������
		std::deque<Point> ptDeque1;
		std::vector<Point> vPoint1(5);
		for (auto & val : vPoint1)
			val = Point(rand() % 20 - 10, rand() % 20 - 10);
		PrintContainer(vPoint1);
		ptDeque1.assign(vPoint1.begin(), vPoint1.end());
		PrintContainer(ptDeque1);
		//�������� deque � ���������� ���� MyString. ��������� ��� ����������
		//� ������� push_back(), push_front(), insert()
		//� ������� erase ������� �� deque ��� ��������, � ������� �������
		//���������� � 'A' ��� 'a'
		std::deque<MyString> strDeque1;
		strDeque1.push_back("Abc");
		strDeque1.push_back("Bcd");
		strDeque1.push_front("Abd");
		strDeque1.push_front("Fhdf");
		strDeque1.insert(strDeque1.begin() + 2, "Midle");
		PrintContainer(strDeque1);
		strDeque1.erase(std::remove_if(strDeque1.begin(), strDeque1.end(),
			[&](MyString & val) {return val.GetString()[0] == 'A'; }), strDeque1.end());
		PrintContainer(strDeque1);
#endif

	system("pause");
	return 0;
}