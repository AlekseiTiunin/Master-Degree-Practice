#include <iostream>
#include <tchar.h>
#include <locale>
#include <cstdio>
#include <cstdarg>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <cstdarg>
extern int & ref;
//Прототипы используемых в данном задании функций:
const int N = 5;
const int M = 4;
void VarArgs(int arg1, ...);
void VarArgsMacros(int arg1, ...);
int IncByValue(int value); 
void IncByPointer(int * value);
void IncByReference(int &value);
void Swap(int * x, int * y);
void Swap(int &x, int &y);
void PrintArray(const int array[N][M]);
int MinArray(const int array[N][M]);
void PrintArrayDynamic(int x, int y,int const * const * array);
int MinArrayDynamic(int y, int x, int const * const * array);
int MyStrCmp(const char *string1, const char *string2);
int DayOfYear(int nDayOfMonth, int nMonth, int nYear, int nDayTab[2][12]);
void DayOfMonth(int & nDayOfMonth, int & nMonth, int nYear, int nDayOfYear, int nDayTab[2][12]);
void PrintArray(int nSize, const int *array); //overload
void AddValue(int Value, int & nSize, int *& nArray);
int SumOfFirstN(int nNumber);
int * MyMin(int array[N][M]);