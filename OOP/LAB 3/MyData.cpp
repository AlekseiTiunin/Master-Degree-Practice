#include "MyData.h"

MyData::MyData(SEX sex, size_t age, const char * job, float salary) : job(job)
{
	if (sex == MALE || sex == FMALE)
		this->sex = sex;
	else
		this->sex = UNDEF;

	if (age > 18 && age < 65)
		this->age = age;
	else
	{
		std::cout << "Попытка ввода недопустимого возраста, установка 18.\n";
		this->age = 0;
	}
	if (salary >= MROT)
		this->salary = salary;
	else
	{
		std::cout << "Попытка ввода зарплаты ниже МРОТ, установка МРОТ.\n";
		this->salary = MROT;
	}
}

std::ostream & operator<<(std::ostream &os, const MyData & data)
{
	os << "Пол: " << ((data.sex == MyData::MALE) ? "Мужской" : (data.sex == MyData::FMALE) ? "Женский" : "NULL");
	os << ", Возраст: " << data.age << " лет, Должность: " << data.job << ", Зарплата: " << data.salary << " р";
	return os;
}