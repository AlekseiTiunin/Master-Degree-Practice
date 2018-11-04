/*
	В результате выполнения данной работы слушатель получает много мелких но необходимых
	для дальнейшей работы навыков, поэтому задание построено как последовательность
	закомментированных блоков, которые требуется последовательно раскомментировать,
	отвечая  при этом на поставленные вопросы.

	Примерная последовательность действий при отладке проекта:
	1. наберите (исправьте, раскомментируйте нужный фрагмент) исходный текст программы;
	2. откомпилируйте (Build/Compile  ***.cpp или Ctrl+F7)
		Замечание: этот этап явно вызывать необязательно, но полезно для начинающего
			программиста, т.к. позволяет увидеть ошибки (errors) и предупреждения
			(warnings), возникающие при компиляции данного конкретного файла;
	3. скомпонуйте проект(Build/Build ***.exe или F7)
		Замечание 1: этот этап тоже необязателен, но настоятельно рекомендуем, т.к.
			позволяет перекомпилировать только измененные файлы и в случае отсутствия
			ошибок всегда полезно посмотреть на выдаваемые компилятором замечания;
		Замечание 2: перед тем, как строить проект, неплохо убедиться  в том, что
			исполняемый код будет содержать информацию для отладчика -
				(Build/Configuration Manager.../Configuration - Debug - тип сборки проекта);
	4. поставьте на интересующих Вас строках исходного кода остановы(breakpoints) - F9 или
		просто кликните левой кнопкой на левой серой полосе окна редактирования;
	5. запустите программу в режиме отладки
		(Debug/Start... или  F5);

  Замечание: для перечисленных выше действий приведены комбинации клавиш и соответствующие
		пункты меню, однако во многих случаях гораздо быстрее то же самое можно сделать с
		помощью кнопок на Tool Bar, в чем слушатель может преуспеть самостоятельно.

*/

#include  <iostream>		//для использования потоков ввода/вывода
#include <iomanip>
#include <Windows.h>
#include <ctype.h>
int nTwin = 1;			//глобальная переменная
namespace TwinSpace { int nTwin = 2; }	//переменная объявлена в
						//пространстве имен - TwinSpace

#define	  stop __asm nop	//с помощью макроподстановки задаем "пустую" команду.
							//Эта макроподстановка нужна только для того, чтобы
							//можно было поставить на этой строке точку останова.

int main()
{

	//**********************************************************
	   //Задание 1. Работа с отладчиком. Базовые типы данных. Выполняя программу по шагам, 
	   //следите за значениями переменных и интерпретируйте результат (помните, что 
	   //количество байт, отводимых под int, системо-зависимо).
	   //Обратите внимание на разную интерпретацию отладчиком signed и unsigned целых типов 
	   //данных, а также на внутреннее представление отрицательных целых чисел.


	char cByte = 'A';
	cByte = 0x42; // B in hex code
	cByte = 66; // B in dec code
	cByte = -1; // знаковый тип, если использовать как число будет -1 (0xff), 
				// если в целях печати, будет неявное приведение типа к unsigned char
				//, этот код эквивалентен букве 'я' для кодировки windows 1251, не определен для ASCII

	unsigned char ucByte = 0x41;
	ucByte = 'B';
	ucByte = -1; // unsigned char это беззнаковый тип, при присвоении -1 идет битовый код ff или 255 для беззнакового.
				 // Этот код эквивалентен букве 'я' для кодировки windows 1251, не определен для ASCII

	SetConsoleCP(1251); // переводим консоль в кодировку 1251
	SetConsoleOutputCP(1251); // переводим консоль в кодировку 1251
	std::cout << "cByte = " << cByte << " ucByte = " << ucByte << std::endl; // вывод в консоль

	int iInt = 0xffffffff; // знаковая переменная, равна -1
	
	unsigned int uiInt = 0xffffffff; // беззнаковая переменная, равна INT_MAX (4294967295)

	float fFloat = 1.f; // переменной float определяем литерал типа float (суффикс f)
	double dDouble = 1.; // переменной double определяем литерал типа double (точка в конце) 

	// Выполните фрагмент, приведенный далее. В комментариях отразите,
	// что реально заносится в переменную. Объясните разницу между этим 
	// значением и инициализатором.

	double d = 0.1234567890123456789123456789; // в памяти записано 0.123456789012345678, 
											   // double 52 бита в мантисе, ~16-17 порядков
	std::cout << std::setprecision(40) << d << std::endl;
	float  f = 0.1234567890123456789123456789; // в памяти записано 0.123456791, float 23 бита в мантисе, ~7 порядков, ошибка округления

	d = 1.; // 1.00000000000000
	d = 0.999999999999999999999999999999999; // 1.00000000000000 ошибка округления

	stop

		// В комментариях напишите результат, возвращаемый оператором sizeof для
		// переменной типа wchar_t (ее размер)
	wchar_t cw = L'Ф';
	size_t n = sizeof(cw); // 2, размер wchar_t
	std::cout << "n = " << n << std::endl;
	stop


		// **************************************************************
			//Задание 2a. Неявное приведение типов данных.
			//Объясните разницу результата при выполнении (1) и (2):
			//Покажите явно (напишите в коде) преобразования, которые неявно выполняет компилятор

		iInt = 1;
	double dDouble1 = iInt / 3;		// (1) в начале производится целочисленное деление iInt на 3, потом неявное приведение int к double
									// результат 0
									// в коде выглядит как double dDouble = double(iInt / 3);
	double dDouble2 = iInt / 3.;	// (2) 3. - это double, int неявно приводится к double, потом производится деление с плавающей запятой
									// результат 0,333333333333
									// в коде выглядит как double dDouble = double(iInt) / 3.;
	std::cout << "dDouble1 = " << dDouble1 << " dDouble2 = " << dDouble2 << std::endl;


	// Ассоциативность операторов.
	// Синтаксис языка C допускает "цепочечное" присваивание
	// (как в строках (1) и (2)). Посмотрев результаты выполнения строк (1) и (2)
	// (значения переменных dDouble, fFloat, nInt, sShort, cByte), определите порядок 
	// выполения присваиваний при цепочечной записи и объясните результат.
	// Расставте скобки, явно определяющие порядок выполнения, как это сделал бы компилятор.
	// Объясните (в комментариях) предупреждения (warnings) компилятора.

	short sShort;
	dDouble = fFloat = iInt = sShort = cByte = 3.3 / 3;	// (1) ассоциативность присвоения справа налево, сначала вычисляется выражение
														// 3.3 / 3, что равно 1.1, далее приводится к типу char (= 1) и присваивается cByte,
														// компилятор предупреждает о возможной потери данных
														// далее резльтат выражения cByte = 3.3 / 3 (то что присвоилось переменной cByte)
														// приводится к типу следующей переменной и присваивается к ней (short) и т.д.
														// (dDouble = (fFloat = (iInt = (sShort = (cByte = 3.3 / 3)))));
	std::cout << "dDouble = " << dDouble << " fFloat = " << fFloat << "iInt = " << iInt << std::endl
		<< " sShort = " << sShort << "cByte = " << cByte << std::endl;
	cByte = sShort = iInt = fFloat = dDouble = 3.3 / 3;			// (2) результат выражение присваивается переменной double без приведения,
																// далее неявно приводится к переменной float и присваивается к fFloat,
																// далее приводится к int (отбрасывается дробная часть = 1) и присваивается iInt и т.д.
																// компилятор предупреждает о возможной потери данных при неявном приведении double к float
																// (так как float < double), float к int и т.д.
																// (cByte = (sShort = (iInt = (fFloat = (dDouble = 3.3 / 3)))))
	std::cout << "dDouble = " << dDouble << " fFloat = " << fFloat << "iInt = " << iInt << std::endl
		<< " sShort = " << sShort << "cByte = " << cByte << std::endl;
	//
	// ниже Вам дан пример "небрежного" использования неявного приведения типов, что может 
	// привести к нежелательным результатам - объясните (в комментариях), к каким?
	// Напишите явно преобразования, которые неявно выполняет компилятор

	iInt = 257; // 0x101
	cByte = iInt; // char - 1 байт, число 257 - 3 байта усекается до 2, получается 0x01 или 1
				  // cByte = char(iInt)

	unsigned char cN1 = 255, cN2 = 2, cSum;
	cSum = cN1 + cN2; // в начале происходит расширение операндов до int, затем результат приводится к типу char

	//Сравните предыдущую строчку с приведенной ниже. Объясните (в комментариях),
	//почему в следующей строке не происходит выход за разрядную сетку
	// Напишите явно преобразования, которые неявно выполняет компилятор
	int iSum = cN1 + cN2; // в начале происходит расширение операндов до int, затем вычисляется сумма

	//Напишите, почему при сложении одинаковых значений (одинаковых в двоичной системе) 
	// в строках (1) и (2) получаются разные результаты
	// Напишите явно преобразования, которые неявно выполняет компилятор и объясните,
	// что при этом происходит
	char c1 = 0xff, c2 = 2; // для знаковых 0xff = -1
	unsigned char uc1 = 0xff, uc2 = 2; // для беззнаковых 0xff = 255
	int iSum1 = c1 + c2;   //(1) -1 + 2 = 1
	int iSum2 = uc1 + uc2; //(2) unsigned char приводится к int, 255 + 2 = 257

	stop


		// ***********************************************************
			//Задание 2b. Явное приведение типов данных.
			//Проинтерпретируйте результат (значения переменной dDouble) в строке (3)
			// Напишите явно преобразования, которые неявно выполняет компилятор
		int nTmp = 100, nn = 3;
	dDouble = 3.3 + nTmp / nn; // (3) 36.299999999999997, в начале производится целочисленное деление nTmp / nn, затем результат деления 
	//приводится к типу double и складывается с 3.3. Есть ошибка округления. 
	//dDouble = 3.3 + double(nTmp / nn).

	//Получите результат без потери точности с помощью оператора явного
	//приведения типа
	double dDouble3 = 3.3 + double(nTmp) / double(nn);		// (4) в явном виде производим приведение типа, double(nn) излишне, но показывает,
	//что мы используем не double в делении.


	stop


		// *******************************************************
			// Задание 3. Область действия, область видимости и
			//				время существования переменных

			//   В этом фрагменте фигурируют четыре переменных с одним и тем же именем 
			// nTwin - одна глобальная, вторая определена в своем пространстве имен, 
			// (определены выше в начале модуля) третья - локальная внутри функции main(), 
			// четвертая - вложенная локальная внутри блока. 
			//   В данном задании требуется в выделенных местах фрагмента определить, к какой 
			// из четырех переменных идет обращение, а также факт существования и видимости 
			// для всех четырех, заполнив приведенные в задании таблицы 
			//	Для выполнения задания рекомендуется пользоваться окнами "Locals" и "Watches"
			// Подсказка: - в окно "Watches" можно поместить как nTwin
			//			так и ::nTwin, впрочем как и TwinSpace::nTwin


		nTwin = 100; // глобальная
	TwinSpace::nTwin = 300; // из пространства имен
	nTwin++; // глобальная 
	// Обратите внимание на небольшой "глюк" отладчика. Хотя локальная переменная nTwin
	// до следующей строки еще не определена (и формально даже не существует), но место
	// под нее в стеке функции main уже выделено (и там мусор). Если теперь в  окно 
	// "Watches" поместить просто nTwin, то отладчик будет показывать значение этой, еще 
	// не объявленной локальной переменной (что-то вроде -858993460 или 0xcccccccc), 
	// хотя должен формально показывать значение глобальной переменной, объявленной ранее.
	// Компилятор при этом все вычисляет верно.
	// Если надо увидеть именно значение глобальной переменной, то надо явно указать в окне
	// "Watches" глобальную область видимости, т.е. написать там ::nTwin.
	// Примечание: вот еще один аргумент за то, чтобы не создавать конфликты имен.
	int nTwin; // скрываем глобальную переменную nTwins
	nTwin = 200; // присвоение локальной переменной nTwin
	::nTwin++; // обращение к глобальной переменной
	{
		int nTwin; // скрываем глобальную и локальную nTwin, теперь мы не можем получить доступ к локальной переменной
		nTwin = -1; // обращение к nTwin блока
		::nTwin++; // обращение к глобальному nTwin
		TwinSpace::nTwin++; // обращение к nTwin из пространства имен
	}

	nTwin--; // обращение к локальной переменной


	// *******************************************************
		// Задание 4. Спецификатор класса памяти - static
		// а) Для каждой итерации цикла напишите значения пременных nLocal# и nStatic#.
		// б) Напишите, когда выполняется инициализация обеих переменных?
		// в) Поясните (в комментарии) разницу между способом инициализации 
		//     переменных nStatic1 и nStatic2 и поясните побочный эффект, 
		//     влияющий на переменную nLocal2.

	for (int i = 0; i < 3; i++)
	{
		static int nStatic1 = 100; 
		int nLocal1 = 100; 
		int nLocal2 = 200; 
		static int nStatic2 = nLocal2++ * 2; // сначала nStatic = 200 * 2, затем nLocal += 1
		nStatic1++; 
		nStatic2++;
		nLocal1++;
		stop
			// в конце каждой итерации
			// nStatic1 - 101 102 103 (инициализация идет только один раз в начале цикла)
			// nStatic2 - 401 402 403 (инициализация идет только один раз в начале цикла)
			// nLocal1 - 101 101 101 (инициализация идет на каждой итерации цикла)
			// nLocal2 - 101 100 100 (инициализация идет на каждой итерации цикла, так как постинкремент был только в инициализации nStatic2,
			// то выполняется только один раз на первой итерации.
	}
	// Напишите:
	//   а) как изменилось поведение пременной nStatic1?
	//   б) как эта переменная ИНИЦИАЛИЗИРОВАНА ?
	for (int i = 0; i < 3; i++)
	{
		static int nStatic1; // инициализирована 0, так как static
		nStatic1 = 100; // присвоение, будет выполняться на каждой итерации
		int nLocal1 = 100;
		nStatic1++;
		nLocal1++;
		stop
			// nStatic1 101 101 101 101
			// nLocal1 101 101 101 101
	}



	// *******************************************************
		// Задание 5. Перечисления - enum
		// Обратите внимание на явную и неявную инициализацию констант
		// Выполняя задание по шагам, следите за значениями, которые
		// принимает переменная myColors


	enum eColors
	{
		BLACK, // 0
		BLUE, // 1
		GREEN, // 2
		RED = 5, // 5
		YELLOW, // 6
		WHITE = RED + 4 // 5 + 4 = 9
	};

	eColors   myColors;	//объявление переменной типа eColors 
	myColors = BLACK; // 0
	myColors = BLUE; // 1
	myColors = GREEN; // 2
	myColors = RED; // 5
	myColors = YELLOW; // 6
	myColors = WHITE; // 9

	int nnn = BLACK; //любой целочисленной переменной можно присвоить
					 //значение из списка инициализирующих значений, 0

	//Именованные константы можно использовать в выражениях:
	nnn = BLUE | YELLOW; // b0001 | b0110 = b0111 (7)

	//Раскомментируйте следующую строку и обратите
	//внимание на  ошибку при компиляции 
	myColors = static_cast <eColors> (1);	//модифицируйте выражение таким образом, чтобы компилятор не выдывал ошибки
	// мы можем присваивать перечислению только то, что указали в объявлении типа, для того, чтобы присвоит 1 нужно использовать явное приведение типа
	// Выполните следующее присваивание НЕ меняя перечисление и тип переменной myColors?
	myColors = static_cast <eColors> (123); // аналогично, будет присвоино значение не входящее в набор перечисления, что может привести к ошибкам
	stop


		// *******************************************************
			// Задание 6.1 Логический тип bool
			// Выполняя задание по шагам, следите за значениями
			// переменной b и интерпретируйте результат. Напишите эти значения в комментариях

		int nNumber = 1;
	bool b = (nNumber != 0); // (1 != 0) = true
	b = (nNumber == 0); // (1 == 0) = false
	b = (nNumber > 0); // (1 > 0) = true
	b = (nNumber > 1); // (1 > 1) = false
	b = 5; // 5 = true

	//Вы всегда можете преобразовать логическое значение к целому
	//явно или компилятор может это сделать самостоятельно (неявно)
	//Обратите внимание: как интерпретирует значения логических переменных компилятор?
	int tmp = b + 1; // (b = true) = 1, tmp = 1 + 1 =2

	//Задание 6.2 В Григорианском календаре (которым мы все пользуемся) високосный год
	// определяется по следующему алгоритму: високосным является каждый четвертый год,
	// но каждый сотый високосным не является, при этом каждый 400-й год все таки 
	// високосный. Т.е. 1823 - не високосный, 1824 - високосный, 1900 - не високосный,
	// 2000 - високосный.
	// Напишите фрагмент кода, такой что:
	// логическая переменная isLeapYear принимает значение true, если год, заданный
	// переменной year - високосный.
	// Примечание: НЕ НАДО пользоваться операторами if-else, тернарным оператором и switch
	//             НАДО написать логическое выражение в одну строку.
	{
		int year = 1823;
		//int year = 1824;
		//int year = 1900;
		//int year = 2000;

		//Вычислили значение 
		bool isLeapYear = (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0); // 1823 false, 1824 true, 1900 false, 2000 true
		// проверили значение в отладчике
		stop
	}

	// *******************************************************
		// Задание 7. Модификатор const и переменные

	{
		//Раскомментируйте следующие две строчки и объясните (в комментариях)
		//ошибки при компиляции 

		//	const int nN; // при объявлении const необходимо ее инициализировать(за исключением extern const)
		//	nN = 1; // мы не можем присваивать что-либо константной переменной
	}



	// ********************************************************
		//Задание 8. Логические условные операторы и операторы отношения.

		//Задание 8.1 Напишите фрагмент кода, который переводит код символа, 
		//хранящийся в переменной ch в противоположный регистр.
		//Требуется предусмотреть проверку ситуации, когда пользователь ввел цифру
		//или нажал другую клавишу, которой символ не соответствует
		//Подсказка: работаем только с символами английского алфавита, для которого в таблице
		// кодов ASCII код каждой буквы нижнего регистра на 0x20 больше кода 
		// соответствующей буквы верхнего регистра.
	{
		// Сформируйте значение переменной ch с помощью потока ввода
		char ch;
		std::cout << "Enter a char" << std::endl;
		while (std::cin >> ch)
		{			
			if (islower(ch))
				ch = toupper(ch);
			else if (isupper(ch))
				ch = tolower(ch);
			std::cout << "char = " << ch << std::endl;
			std::cout << "Enter a char (ctrl-Z to exit): " << std::endl;
		}
		std::cin.clear();
		//... изменили регистр
		// здесь проверили в отладчике значение или вывели "эхо" на экран
		stop
	}


	//Задание 8.2 Напишите фрагмент кода, который реализует с помощью if (if/else)
	//следующую логику: если x меньше или равен 0, y=0
	//если x больше 0 но меньше 1, то y=x,
	//если x больше или равен 1, то y=1
	//Подумайте: какого типа должны или могут быть x и y?
	{
		double x, y;
		std::cout << "Enter a number" << std::endl;
		while (std::cin >> x)
		{
			if (x <= 0)
				y = 0;
			else if (x < 1)
				y = x;
			else
				y = 1;
			std::cout << "y = " << y << std::endl;
			std::cout << "Enter a number (ctrl-Z to exit): " << std::endl;
		}
		std::cin.clear();		
	}

	//Задание 8.3 Напишите фрагмент кода, который реализует с помощью switch
	//следующую логику: в переменной cInput типа char дано значение символа,
	//введенного любым способом.
	//Если введен символ 'y' (т.е. yes) в любом регистре, то присвоить
	//переменной у значение переменной x
	//Если введен символ 'n' (т.е. no) в любом регистре, то присвоить
	//переменной у значение (x * 2)
	//Если любой другой симол, то вывести сообщение об ошибке
	{
		char ch;
		double x = 5, y;
		std::cout << "Enter a choice (y to y = x) (n to y = x * 2) (x = 5)" << std::endl;
		while (std::cin >> ch)
		{
			switch (ch) 
			{
			case 'Y':
			case 'y': y = x;
				std::cout << "y = " << y << std::endl;
				break;
			case 'N':
			case 'n': y = x * 2;
				std::cout << "y = " << y << std::endl;
				break;
			default: std::cout << "Enter y or n" << std::endl;
			}
			std::cout << "Enter a choice (ctrl-Z to exit): " << std::endl;
		}
		std::cin.clear();
	}
	// ********************************************************
	//Задание 9. Циклы.

	//Задание 9.1 Напишите фрагмент кода, который реализует с помощью for
	//следующую логику: найти сумму заданного диапазона целых чисел.
	//Введите границы с помощью потока ввода или с помощью средств отладки.
	//Предусмотрите защиту от ввода нижней границы больше, чем верхней.
	{
 		int lower, higher, sum = 0;
		//сформироыать границы диапазона
		std::cout << "Enter lower bound: ";
		std::cin >> lower;
		std::cout << "Enter higher bound: ";
		std::cin >> higher;
		while (lower > higher)
		{
			std::cout << "Lower > Higher, error " << std::endl;
			std::cout << "Enter lower bound: ";
			std::cin >> lower;
			std::cout << "Enter higher bound: ";
			std::cin >> higher;
		}
		for (int i = lower; i <= higher; i++)
			sum += i;
		std::cout << "Sum = " << sum << std::endl;
		//проверить корректность значений

		// вычислить сумму
		// проверить в отладчике значение
		stop
	}


	//Задание 9.2 Напишите фрагмент кода, который реализует с помощью do-while
	//следующую логику: на каждой итерации цикла ввести с консоли целое значение
	// и покинуть цикл, если значение удовлетворяет условию: 
	// значение больше или равно 10 и четное.
	//Замечание: проверка на четность с использованием операции остатка от деления
	//нацело генерирует очень неэффективный код. Попробуйте реализовать альтернативный
	//вариант.

	{
		int x, flag = 0;
		do
		{ 
			if (flag)
				std::cout << "Значение должно быть больше или равно 10 и четное." << std::endl;
			flag = 1;
			std::cout << "Enter a number: ";
			std::cin >> x;
		} while ((x < 10) || (x & 1 != 0));
	}

	//Задание 9.3 Напишите фрагмент кода, который реализует с помощью while
	//следующую логику: исходно int x = 0; 
	//на каждой итерации x=x+1, sum=sum+1/x
	//найти значение x, при котором sum>1.7
	{
		double x = 0;
		double sum = 0;

		while (sum <= 1.7)
		{
			x = x + 1;
			sum = sum + 1 / x; // в условии написано так, но происходит целочисленное деление и после первой итерации 1 / x всегда 0;
							   // получается бесконечный цикл, решается явным приведением типа к double или изменением типа x; 
		}
	}
	return 0;//код завершения приложения
}	// Конец функции main()

