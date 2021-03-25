#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
private:
	unsigned long int emp_id;
	string firstname;
	string lastname;
	char gender;
	int age;
	double salary;
	string designation;
	string mobilenumber;

public:
	Employee();

	unsigned long int get_emp_id();
	void set_employee_id(unsigned long int e_id);

	string get_first_name();
	void set_first_name(string e_first_name);

	string get_last_name();
	void set_last_name(string e_last_name);

	int get_age();
	void set_age(int e_age);

	char get_gender();
	void set_gender(char e_gender);

	double get_salary() const;
	void set_salary(double e_salary);

	string get_mobile_number();

	void set_mobile_number(string mob_num);

	virtual void increment_salary() = 0;

	void set_designation(string e_designation);
	string get_designation();

};

class Human_resource : public Employee
{
public:
	Human_resource() {}

	Human_resource(int id, string firstname, string lastname, char gender, string mob_num, int age);

	void increment_salary()  override;

};
class Team_Lead : public Employee
{
public:
	Team_Lead() {}

	Team_Lead(int id, string firstname, string lastname, char gender, string mob_num, int age);

	void increment_salary() override;

};

class Quality_Analyst : public Employee
{
public:
	Quality_Analyst() {}

	Quality_Analyst(int id, string firstname, string lastname, char gender, string mob_num, int age);

	void increment_salary() override;

};

class Developer : public Employee
{
public:
	Developer() {}

	Developer(int id, string firstname, string lastname, char gender, string mob_num, int age);

	void increment_salary() override;

};

