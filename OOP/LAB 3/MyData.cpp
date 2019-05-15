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
		std::cout << "������� ����� ������������� ��������, ��������� 18.\n";
		this->age = 0;
	}
	if (salary >= MROT)
		this->salary = salary;
	else
	{
		std::cout << "������� ����� �������� ���� ����, ��������� ����.\n";
		this->salary = MROT;
	}
}

std::ostream & operator<<(std::ostream &os, const MyData & data)
{
	os << "���: " << ((data.sex == MyData::MALE) ? "�������" : (data.sex == MyData::FMALE) ? "�������" : "NULL");
	os << ", �������: " << data.age << " ���, ���������: " << data.job << ", ��������: " << data.salary << " �";
	return os;
}