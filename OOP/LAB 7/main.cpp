//����������

//�������: 
	//		������� �������,
	//		������� �������,


#include <tchar.h>
#include <stdexcept>
#include "VariusFunctionTemplates.h"
#include "String.h"
#include "ArrayStack.h"
#include "ListStack.h"
#include "RingBuffer.h"
#define stop __asm nop
#define cur_ex 4
int _tmain(int argc, _TCHAR* argv[])
{


	////////////////////////////////////////////////////////////////////////////
		//����. ������� �������.
		//�������� ������ ������� ������������ ������� ����
		//�������� - Swap(). ��������� ����������������� ����������
		//������� � ������� ������������ ���� ��������� ����.
		//��������� 1: ���������� ������� ���������� ��������� � .h-����.
#if cur_ex == 1
		int iX = 1, iY = -1;
		Swap(iX, iY);

		double dX = 0.5, dY = -5.5;
		Swap(dX, dY);

		//��������� 2: ���������, ��� ����� �����������, ��� ����,
		//			����� ��������� ����� ������� � ��������� MyString
		//			�� ������ ���������, �� � ����������
		String str1("One"), str2("Two");
		std::cout << str1 << str2;
		Swap(str1, str2);
		std::cout << str1 << str2;
#endif
	/////////////////////////////////////////////////////////////////////
#if cur_ex == 2
		//����. ������� �������.
		//������� 1.
		//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
		//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
		//			��� �������� ��������������� ������������� � ������ ���������
		//			�������� ������, 
		//			2.��� ������� ������������� ������� ����� ����� ���� �����������
		//			��������-��������� �������
		//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
		//			����, ����� ������������� ���������� ���������� ���� �������� 
		//			������ ���� �� ������������ ���������� � ��������� ��������
		//			4. ������������� ���������� operator[] ����� �������, ����� ������������
		//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������


		//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
		//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
		//push() � pop(), operator[]
		//while (1)
		{
			ArrayStack<int, 5> iStack;
			ArrayStack<String, 10 > strStack;
			iStack.push(1);
			iStack.push(2);
			iStack.push(3);
			iStack.push(4);
			iStack.push(5);
			strStack.push("1 ");
			strStack.push("2 ");
			strStack.push("3 ");
			strStack.push("4 ");
			strStack.push("5 ");
			strStack.push("6 ");
			strStack.push("7 ");
			strStack.push("8 ");
			strStack.push("9 ");
			strStack.push("10 ");
			strStack[0] = "101";
			try { strStack.push("11 "); }
			catch (std::invalid_argument arg)
			{
				std::cout << arg.what();
			}
			std::cout << "pop: " << iStack.pop() << std::endl;
			std::cout << "pop: " << strStack.pop() << std::endl;
			try {
				for (int i = 0; i < iStack.size(); i++)
					std::cout << iStack[i] << " ";
			}
			catch (std::invalid_argument arg)
			{
				std::cout << arg.what();
			}
			try {
				for (int i = 0; i < strStack.size(); i++)
					std::cout << strStack[i] << " ";
			}
			catch (std::invalid_argument arg)
			{
				std::cout << arg.what();
			}
		}
		String::PrintAll(std::cout);
		stop

#endif
#if cur_ex == 3
			//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
			//��� �������� ��������� ������������� ����������� ������.
			//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
			//������������

			{
				ListStack<int> list;
				list.push(-2);
				list.push(-4);
				list.push(-6);
				list.push(-8);
				list.push(-10);
				ListStack<int> listnew;
				listnew.push(2);
				listnew.push(4);
				listnew.push(6);
				listnew.push(8);
				listnew.push(10);
				listnew.push(12);
				listnew = list;
				listnew.ReversePrintRecursive(std::cout);
				listnew.ReversePrintIter(std::cout);
				listnew.ReversePrintDoubleReverse(std::cout);
		}

		stop;
#endif
#if cur_ex == 4
		//������� 3. ���������� ������ ������� - MyQueue ����� �������, ����� 
		//��� �������� ��������� ������������� ������������ ������.
		//��� ������������� ������� ������� ������ ��������� �������, �� ����
		//����� �������� "�����", � "������" ������ ����� ��� ������� ��������� ��������
		//=> ������ ���� ����������� ��������� �����
//		while (1)
		{
			const size_t size = 9;
			int ar[size] = { 1,2,3,4,5,6,7,8,9 };
			RingBuffer<int> buf(ar, size);
			RingBuffer<int> nbuf(size + 8);
			nbuf = buf;
			/*buf.push(1);
			buf.push(2);
			buf.push(3);
			buf.push(4);
			buf.push(5);
			buf.push(6);
			buf.push(7);
			buf.push(8);
			buf.push(9);*/
			std::cout << buf << std::endl;			
			std::cout << nbuf << std::endl;
			nbuf.push(10);
			nbuf.pop();
			nbuf.push(10);
			std::cout << nbuf << std::endl;
			system("pause");
		}
#endif
	return 0;
}

