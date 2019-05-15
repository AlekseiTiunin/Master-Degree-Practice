// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

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
	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию

	std::set<Point> MySet1{ Point(1,1), Point(1,1), Point(2,2), Point(3,3), Point(0,1), Point(1,1) };
	std::vector<Point> MyVector1(MySet1.rbegin(), MySet1.rend());

	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.
	std::ostream_iterator<Point> out_it(std::cout, "\n");
	std::copy(MySet1.begin(), MySet1.end(), out_it);
	std::cout << "\n";
	std::copy(MyVector1.begin(), MyVector1.end(), out_it);
	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.
	std::back_inserter(MyVector1) = Point(10, 10);
	//std::front_inserter(MyVector1) = Point(-10, -10); нужен метод push_front
	std::inserter(MyVector1, MyVector1.begin()) = Point(-10, -10);
	std::cout << "\n";
	std::copy(MyVector1.begin(), MyVector1.end(), out_it);
///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон
	std::cout << "\nfor_each:\n";
	std::for_each(MyVector1.begin(), MyVector1.end(), [](const Point & pt) {std::cout << pt << "\n"; });
	stop

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката
	std::cout << "\nfor_each:\n";
	std::for_each(MyVector1.begin(), MyVector1.end(), [x = 0, y = 0](Point & pt) mutable {pt.SetX(x++); pt.SetY(y--); });
	std::for_each(MyVector1.begin(), MyVector1.end(), [](const Point & pt) {std::cout << pt << "\n"; });
	std::back_inserter(MyVector1) = Point(1, 1);
	std::back_inserter(MyVector1) = Point(1, 1);
	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
	std::cout << "\nfind:\n";
	auto search = std::find(MyVector1.begin(), MyVector1.end(), Point(1, 1));
	while ( search != MyVector1.end())
	{		
		std::cout << *search << "\n"; 
		search = std::find(++search, MyVector1.end(), Point(1, 1));
	}
	
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	std::cout << "Sort:\n";
	std::sort(MyVector1.begin(), MyVector1.end());
	PrintContainer(MyVector1);

	
	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
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

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	
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
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()

		std::string MyString1{ "1111ItIsWaLlOfTeXtFoRmAtMe!" };
		std::transform(MyString1.begin(), MyString1.end(), MyString1.begin(), tolower);
		std::cout << MyString1;
		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
	
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
		
		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	

		//lab 9

		std::vector<std::string> MyVector3{ "ZFT", "ABC", "ABC", "ABC", "DCB", "DCB", "ERT", "ERG" };
		std::map < std::string, int> MyMap1;
		for (auto & value : MyVector3)
			MyMap1[value]++;
		PrintContainer(MyMap1);
	}

	


	return 0;
}

