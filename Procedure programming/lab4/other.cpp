#include "other.h"

///////////////////////////////////////////////////
namespace {
	int nVarE = 0;
}

int & ref = nVarE;
//Подсказка-заготовка для задания 5а
//Без использования макросов

void VarArgs(int arg1,...)
{
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	int * ptr = &arg1;
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов
	while (*ptr != 0)
	{
		std::cout << *ptr << " ";
		number++;
		ptr++;
	}




	//Печать числа элементов

	std::cout << "\nЧисло элементов = " << number <<std::endl;

}

void VarArgsMacros(int arg1, ...)
{
	int number = 0;	//счетчик элементов
	int i = arg1;
	va_list p;
	va_start(p, arg1);
	while (i != 0)
	{
		std::cout << i << " ";
		number++;
		i = va_arg(p, int);
	}
	va_end(p);
	std::cout << "\nЧисло элементов = " << number << std::endl;

}

int IncByValue(int value)
{
	return value + 1;
}

void IncByPointer(int * value)
{
	(*value)++;
}

void IncByReference(int &value)
{
	value++;
}

void Swap(int * x, int * y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void Swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void PrintArrayDynamic(int y, int x, int const * const * array)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			std::cout << std::setw(2) << array[i][j] << " ";
		std::cout << std::endl;
	}
}

void PrintArray(const int array[N][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			std::cout << std::setw(2) << array[i][j] << " ";
		std::cout << std::endl;
	}
}
int MinArray(const int array[N][M])
{
	int min = array[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			if (array[i][j] < min)
				min = array[i][j];
	}
	return min;
}

int MinArrayDynamic(int y, int x, int const * const * array)
{
	int min = array[0][0];
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			if (array[i][j] < min)
				min = array[i][j];
	}
	return min;
}

int MyStrCmp(const char *string1, const char *string2)
{
	int i = 0;
	while ((string1[i] != '\0') || (string2[i] != '\0'))
	{
		if (string1[i] > string2[i])
			return 1;
		else if (string1[i] < string2[i])
			return -1;
		i++;
	}
	return 0;
}

int DayOfYear(int nDayOfMonth, int nMonth, int nYear, int nDayTab[2][12])
{
	
	bool nLeap = ((((nYear % 4) == 0) && ((nYear % 100) != 0)) || ((nYear % 400) == 0));

	for (int i = 0; i < nMonth - 1; i++)
		nDayOfMonth += nDayTab[nLeap][i];
	return nDayOfMonth;
}

void DayOfMonth(int & nDayOfMonth, int & nMonth, int nYear, int nDayOfYear, int nDayTab[2][12])
{
	int nLeap, i = 0;
	if ((((nYear % 4) == 0) && ((nYear % 100) != 0)) || ((nYear % 400) == 0))
		nLeap = 1;
	else
		nLeap = 0;
	while (nDayOfYear > nDayTab[nLeap][i])
	{
		nDayOfYear -= nDayTab[nLeap][i];
		i++;
	}
	nDayOfMonth = nDayOfYear;
	nMonth = i + 1;
}
void PrintArray(int nSize, const int *array)
{
	for (int i = 0; i < nSize; i++)
		std::cout << array[i] << " ";
	std::cout.put('\n');
}
void AddValue(int value, int & nSize, int *& nArray)
{
	for (int j = 0; j < nSize; j++)
	{
		if (value == nArray[j])
		{
			std::cout << "Повтор.\n";
			return;
		}
	}
	
	int * tmpptr = new int[nSize + 1];
	for (int j = 0; j < nSize; j++)
		tmpptr[j] = nArray[j];
	delete[] nArray;
	nArray = tmpptr;
	nArray[nSize] = value;
	nSize++;

		
}

int SumOfFirstN(int nNumber)
{
	if (nNumber > 1)
		return SumOfFirstN(nNumber - 1) + nNumber;
	else
		return 1;
}

int * MyMin(int array[N][M])
{
	int *min = &array[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			if (array[i][j] < *min)
				min = &array[i][j];
	}
	return min;
}