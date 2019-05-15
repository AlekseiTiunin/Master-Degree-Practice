// ����:
// ���������� ����������.
// ���������� ������� 

//#include "stdafx.h"	//���� �� ����������� �������������� ������������
					//������, ���������������� ��� �������
#include <tchar.h>
#include <Windows.h>
#include "myString.h"
#include "Point.h"
#include "Base.h"
#define	  stop __asm nop
#define curex 5
int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#if curex == 1
	
	//������� 1.���������� ����������.

	//���������� � ������� ����� MyString.cpp � MyString.h
	//������ MyString, �������������� ���� �� ���������� �������
	//9a. ����������� �������� ������������ ��� ������ MyString
	//��������� ������������ ������ �������������� ���������

	{
		MyString s1("AAA"), s2;
		s2=s1;
		std::cout << "s1: " << s1 << ", s2 :" << s2 << std::endl;
		s1="CCC";
		s2= MyString("tmp");
		s1=s1;	
		std::cout << "s1: " << s1 << ", s2 :" << s2 << std::endl;
		stop
	}

#endif

#if curex == 2
	//�������� ����� Point, ������� ����� ��������� ����������
	//"�����". �������� ����������� (������������) ������   

	//1b. "�����������" �������� += ���, ����� ��� ����������
	//�������� ���� pt2+=pt1; ������������
	//����������� ���������� �������� pt1 � pt2, � �����
	//������������� ��������������� ���������� ������� pt2 ���
	// � ������  pt2+=1; ��� ���������� ������� pt2 ������������� ��
	// ��������� ��������
	//a) � ������� ������ ������ (�������� +=)
	//�) � ������� ���������� ������� (�������� -=)
	//��������� ������������ ������ �������������� ���������

	Point pt1(1,1);
	Point pt2(2,2);
	std::cout << "pt1: " << pt1 << " pt2: " << pt2 << std::endl;
	pt2+=pt1;
	std::cout << "pt2+=pt1: " << pt2 << std::endl;
	pt2+=1;
	std::cout << "pt2+=1: " << pt2 << std::endl;
	Point pt3(3,3);
	std::cout << "pt3: " << pt3 << std::endl;
	pt2+=pt1+=pt3;
	std::cout << "pt2+=pt1+=pt3: " << pt2 << std::endl;
	pt2 -= 5;
	std::cout << "pt2-=5: " << pt2 << std::endl;
	stop
#endif
#if curex == 3

	//������� 1c. ����������� �������� +/- 
	//a)� ������� ������� ������ (�������� +)
	//�) � �������  ���������� ������� (�������� -)
	//���, ����� ����� �� ������������������ �����
	//���� ����������� ���������
	Point pt1(1,1);
	Point pt2(2,2);
	Point pt3;

	pt3 = pt1 + 5;
	pt3 = 2 + pt1;
	pt3 = pt1 + pt2;

	pt3 = pt1 - 5;
	pt3 = pt1 - pt2;
	stop

	//������� 1d. ����������� ������� �������� +/- 
	pt3 = -pt1;
	pt3 = +pt1;


#endif

#if curex == 4
	//������� 1d. ����������� �������� << (������ � �����) ���
	//������ MyString ����� �������, ����� ��� ���������� ����������� ������
	//�� ����� ���� ��������:
	//contents:  "QWERTY"

	MyString s("QWERTY");
	std::cout << s << std::endl;

	//������� 1� ����������� �������� + � += ��� ������ MyString
	MyString s1("ABC"), s2("kkk");
	s1 +=s;
	s2 = s+s1;
	std::cout << "s1: " << s1 << ", s2 :" << s2 << std::endl;
	stop
#endif

#if curex == 5
		//������� 2. ����������� "���� ������" � ����������� ����������� ��������������
		//�������. ������ �������� ������� (���� � ������� ��������, ������� ���������� ��������
		//� ���� ���� �� �����), � �������: ���, �������, ���������, ��������...
		//����������:
		//���������� ����������� � ����
		//����������
		//����� ���������� � ���������� ����������
		//����� ���� (��� ������������) ���������� � ���� �����������
		//��������:

		
		Base database;	//�������� ������ ����
		database["������"] = MyData(MyData::MALE, 30, "�������", 25000);	//���� Ivanov-� � ���� ��� ���, ��
						//����������, ���� ��� ����, �� ������ ��� ����������
		database["�������"] = MyData(MyData::MALE, 20, "��������", 225000);
		database["�������"] = MyData(MyData::MALE, 20, "����������� ���������", 125000);
		database["������"] = MyData(MyData::MALE, 20, "����������� ����������� ���������", 85000);
		std::cout << "database: \n" << database;
		database["�������"] = MyData(MyData::MALE, 21, "������� ��������", 325000);
		database["������"] = MyData(MyData::MALE, 31, "������� �������", 20000);
		//� �����:
		Base databasenew = database;
		database.deletePair("������");
		std::cout << "database: \n" << database << "databasenew: \n" << databasenew;
		//
		databasenew = std::move(database);
		databasenew.CompressUnused();
		std::cout << "database: \n" << database << "databasenew: \n" << databasenew;
		


#endif
	
	return 0;
}//endmain

