#pragma once
#include "Employee.h"

class EmployeeCreatorFactory
{
private:

	virtual Employee* FactoryMethod(int, string, string, char, string, int, double) const = 0;

public:

	Employee* generate(int id, string firstname, string lastname, char gender, string mob_num, int age, double salary) const
	{
		Employee* emp = this->FactoryMethod(id, firstname, lastname, gender, mob_num, age , salary);
		return emp;
	}
	virtual ~EmployeeCreatorFactory() {};

};

class Create_Human_Resource : public EmployeeCreatorFactory
{
public:
	Employee* FactoryMethod(int id, string firstname, string lastname, char gender, string mob_num, int age , double salary) const override {
		return new Human_resource(id, firstname, lastname, gender, mob_num, age, salary);
	}
};

class Create_Team_Lead : public EmployeeCreatorFactory
{
	Employee* FactoryMethod(int id, string firstname, string lastname, char gender, string mob_num, int age, double salary) const override {
		return new Team_Lead(id, firstname, lastname, gender, mob_num, age, salary);
	}
};

class Create_Quality_Analyst : public EmployeeCreatorFactory
{
	Employee* FactoryMethod(int id, string firstname, string lastname, char gender, string mob_num, int age,double salary)const override {
		return new Quality_Analyst(id, firstname, lastname, gender, mob_num, age, salary);
	}
};

class Create_Developer : public EmployeeCreatorFactory
{
	Employee* FactoryMethod(int id, string firstname, string lastname, char gender, string mob_num, int age,double salary) const override {
		return new Developer(id, firstname, lastname, gender, mob_num, age, salary);
	}
};

