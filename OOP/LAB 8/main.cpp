//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

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
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 
#if cur_ex == 1
	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 

	std::vector<int> vInt;
	
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте

	vInt.resize(1);
	vInt.front()=1;


	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	for (size_t i = 0; i < 10; i++)
	{
		vInt.push_back(rand() % 10);
		PrintVector(vInt);
	}
	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
	
	std::vector<double> vDouble(10);
	PrintVector(vDouble);

	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 

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
	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	
	std::vector<double> dMas{ 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7 };
	std::vector<double> vDouble3(dMas.begin(), dMas.begin() + 5);
	PrintVector(vDouble3);
	

	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 

	std::vector<double> vDouble4(dMas.begin() + 2, dMas.begin() + 5);
	PrintVector(vDouble4);

	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).

	std::vector<Point> vPoint1(3);
	PrintVector(vPoint1);
	std::vector<Point> vPoint2(5, { 1,1 });
	PrintVector(vPoint2);
	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{
		std::vector<Point *> vpPoint(5);
	//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*
		for (auto & val : vpPoint)
			val = new Point(rand() % 10, rand() % 10);
		PrintVector(vpPoint);
		for (auto & val : vpPoint)
			delete val;
	}//Какие дополнительные действия нужно предпринять для такого вектора?
#endif
#if cur_ex == 2
	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
		
		{
			size_t n = 10;
			std::vector<int> v(n);
			v.resize(n/2); // меняет размер, но не вместимость
			if (v.capacity() == n)
			{
				std::cout << "true\n"; //true? да
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
				std::cout << "true\n"; //true? да
			}
			else
			{
				std::cout << "false\n";
			}
		}
		

		
		{
			vector<int> v(3,5); // 5 5 5
			PrintContainer(v);
			v.resize(4,10); //значения? 5 5 5 10
			PrintContainer(v);
			v.resize(5); //значения? 5 5 5 10 0
			PrintContainer(v);	
		}


	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов

		std::vector<int> vInt1;
		std::vector<int> vInt2;

		vInt1.reserve(5);
		for (size_t i = 0; i < 5; i++)
			vInt1.push_back(rand() % 10);
		for (size_t i = 0; i < 5; i++)
			vInt2.push_back(rand() % 10);
		PrintContainer(vInt1); // size 5, cap 5
		PrintContainer(vInt2); // size 5, cap 6, амортизация 


	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.

		vInt2.shrink_to_fit();
		PrintContainer(vInt2);
	

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
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
	//Вставка элемента последовательности insert().
	//В вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого еще нет.

	std::vector<char> vChar2{ 'A', 'B', 'C' };
	for (char ch = 'A'; ch != 'F'; ch++)
		if (!IsInContainer(vChar2, ch))
			vChar2.insert(vChar2.begin(), ch);
	PrintVector(vChar2);

	//Вставьте перед каждым элементом вектора vChar2 букву 'W'
	
	for (auto iter = vChar2.begin(); iter != vChar2.end(); )
	{
		auto save = iter - vChar2.begin();
		vChar2.insert(iter, 'W');
		iter = vChar2.begin() + save + 2;
	}
	PrintVector(vChar2);

///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
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
	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 

	char str[] = "qwerrrrty12222r33";
	std::vector<char> vChar3(str, str + std::size(str) - 1);
	PrintVector(vChar3);
	EraseRepeats(vChar3);
	PrintVector(vChar3);
	   
///////////////////////////////////////////////////////////////////
	//Создайте новый вектор таким образом, чтобы его элементы стали
	//копиями элементов любого из созданных ранее векторов, но расположены
	//были бы в обратном порядке

	std::vector<char> vChar4(vChar3.rbegin(), vChar3.rend());
	PrintVector(vChar4);

#endif
///////////////////////////////////////////////////////////////////
#if cur_ex == 5 
	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
	//push_front, insert()

	std::list<Point> ptList1;
	for(size_t i = 0 ; i < 10; i++)
		ptList1.push_back(Point(rand() % 20 - 10, rand() % 20 - 10));
	ptList1.push_back(Point(1, 1));
	ptList1.push_back(Point(2, 2));
	ptList1.push_back(Point(2, 2));
	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.

	PrintContainer(ptList1);

	//Сделайте любой из списков "реверсивным" - reverse()
	ptList1.reverse();
	PrintContainer(ptList1);

	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 

	std::list<Point> ptList2(ptList1.rbegin(), ptList1.rend());
	PrintContainer(ptList2);

	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка

	ptList1.sort();
	ptList2.sort();
	PrintContainer(ptList1);
	PrintContainer(ptList2);
	stop

		//Объедините отсортированные списки - merge(). Посмотрите: что
		//при этом происходит с каждым списком.

	ptList1.merge(ptList2);
	PrintContainer(ptList1);
	PrintContainer(ptList2);
	stop

		//Исключение элемента из списка - remove()
		//Исключите из списка элемент с определенным значением.
		//Подумайте: что должно быть перегружено в классе Point?

	ptList1.remove(Point(1, 1));
	PrintContainer(ptList1);
	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 
	ptList1.remove_if([](const Point & point) {return (point.GetX() < 0 || point.GetY() < 0); });
	PrintContainer(ptList1);
	//Исключение из списка подряд расположенных дублей - unique(). 
	ptList1.unique();
	PrintContainer(ptList1);
	stop
#endif
#if cur_ex == 6
		///////////////////////////////////////////////////////////////////
			//Задание 2.Очередь с двумя концами - контейнер deque

			//Создайте пустой deque с элементами типа Point. С помощью
			//assign заполните deque копиями элементов вектора. С помощью
			//разработанного Вами в предыдущем задании универсального шаблона
			//выведите значения элементов на печать
		std::deque<Point> ptDeque1;
		std::vector<Point> vPoint1(5);
		for (auto & val : vPoint1)
			val = Point(rand() % 20 - 10, rand() % 20 - 10);
		PrintContainer(vPoint1);
		ptDeque1.assign(vPoint1.begin(), vPoint1.end());
		PrintContainer(ptDeque1);
		//Создайте deque с элементами типа MyString. Заполните его значениями
		//с помощью push_back(), push_front(), insert()
		//С помощью erase удалите из deque все элементы, в которых строчки
		//начинаются с 'A' или 'a'
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