// Темы:
// Перегрузка операторов.
// Встроенные объекты 

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
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
	
	//Задание 1.Перегрузка операторов.

	//Подключите к проекту файлы MyString.cpp и MyString.h
	//класса MyString, разработанного Вами на предыдущем занятии
	//9a. Перегрузите оператор присваивания для класса MyString
	//Проверьте корректность работы перегруженного оператора

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
	//Создайте класс Point, который будет содержать координаты
	//"точки". Объявите конструктор (конструкторы) класса   

	//1b. "Перегрузите" оператор += так, чтобы при выполнении
	//операции типа pt2+=pt1; складывались
	//одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	//a) с помощью метода класса (оператор +=)
	//б) с помощью глобальной функции (оператор -=)
	//Проверьте корректность работы перегруженного оператора

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

	//Задание 1c. Перегрузите оператор +/- 
	//a)с помощью методов класса (оператор +)
	//б) с помощью  глобальных функций (оператор -)
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
	Point pt1(1,1);
	Point pt2(2,2);
	Point pt3;

	pt3 = pt1 + 5;
	pt3 = 2 + pt1;
	pt3 = pt1 + pt2;

	pt3 = pt1 - 5;
	pt3 = pt1 - pt2;
	stop

	//Задание 1d. Перегрузите унарный оператор +/- 
	pt3 = -pt1;
	pt3 = +pt1;


#endif

#if curex == 4
	//Задание 1d. Перегрузите оператор << (вывода в поток) для
	//класса MyString таким образом, чтобы при выполнении приведенной строки
	//на экран было выведено:
	//contents:  "QWERTY"

	MyString s("QWERTY");
	std::cout << s << std::endl;

	//Задание 1е Перегрузите оператор + и += для класса MyString
	MyString s1("ABC"), s2("kkk");
	s1 +=s;
	s2 = s+s1;
	std::cout << "s1: " << s1 << ", s2 :" << s2 << std::endl;
	stop
#endif

#if curex == 5
		//Задание 2. Разработать "базу данных" о сотрудниках посредством ассоциативного
		//массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
		//в базе быть не может), а данными: пол, возраст, должность, зарплата...
		//Реализуйте:
		//добавление сотрудников в базу
		//исключение
		//вывод информации о конкретном сотруднике
		//вывод всей (или интересующей) информации о всех сотрудниках
		//Например:

		
		Base database;	//создание пустой базы
		database["Иванов"] = MyData(MyData::MALE, 30, "Рабочий", 25000);	//если Ivanov-а в базе еще нет, то
						//добавление, если уже есть, то замена его реквизитов
		database["Сидоров"] = MyData(MyData::MALE, 20, "Директор", 225000);
		database["Федоров"] = MyData(MyData::MALE, 20, "Заместитель директора", 125000);
		database["Петров"] = MyData(MyData::MALE, 20, "Заместитель заместителя директора", 85000);
		std::cout << "database: \n" << database;
		database["Сидоров"] = MyData(MyData::MALE, 21, "Главный директор", 325000);
		database["Иванов"] = MyData(MyData::MALE, 31, "Младший рабочий", 20000);
		//А также:
		Base databasenew = database;
		database.deletePair("Петров");
		std::cout << "database: \n" << database << "databasenew: \n" << databasenew;
		//
		databasenew = std::move(database);
		databasenew.CompressUnused();
		std::cout << "database: \n" << database << "databasenew: \n" << databasenew;
		


#endif
	
	return 0;
}//endmain

