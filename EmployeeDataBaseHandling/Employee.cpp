#include "Employee.h"

Employee::Employee()
{
	emp_id = 0;
	firstname = "";
	lastname = "";
	gender = ' ';
	age = 0;
	mobilenumber = "";
	salary = 0.0;
	designation = "";
}
double Employee::get_salary() const
{
	return salary;
}
unsigned long int Employee::get_emp_id()
{
	return emp_id;
}
void Employee::set_employee_id(unsigned long int e_id)
{
	emp_id = e_id;
}

string Employee::get_first_name()
{
	return firstname;
}
void Employee::set_first_name(string e_first_name)
{
	firstname = e_first_name;
}

string Employee::get_last_name()
{
	return lastname;
}
void Employee::set_last_name(string e_last_name)
{
	lastname = e_last_name;
}

int Employee::get_age()
{
	return age;
}
void Employee::set_age(int e_age)
{
	age = e_age;
}

char Employee::get_gender()
{
	return gender;
}
void Employee::set_gender(char e_gender)
{
	gender = e_gender;
}


void Employee::set_salary(double e_salary)
{
	salary = e_salary;
}

string Employee::get_mobile_number()
{
	return mobilenumber;
}
void Employee::set_mobile_number(string mob_num)
{
	mobilenumber = mob_num;
}

void Employee::set_designation(string e_designation)
{
	designation = e_designation;
}
string Employee::get_designation()
{
	return designation;
}

Human_resource::Human_resource(int id, string firstname, string lastname, char gender, string mob_num, int age)
{
	this->set_designation("Human Resource");
	this->set_salary(50000.0);
	this->set_gender(gender);
	this->set_age(age);
	this->set_last_name(lastname);
	this->set_first_name(firstname);
	this->set_employee_id(id);
	this->set_mobile_number(mob_num);
}

void Human_resource::increment_salary()
{
	double new_salary = Employee::get_salary() + (Employee::get_salary() * 0.3);
	Employee::set_salary(new_salary);
}

Team_Lead::Team_Lead(int id, string firstname, string lastname, char gender, string mob_num, int age)
{
	this->set_designation("Team Lead");
	this->set_salary(100000.0);
	this->set_gender(gender);
	this->set_age(age);
	this->set_first_name(firstname);
	this->set_employee_id(id);
	this->set_last_name(lastname);
	this->set_mobile_number(mob_num);
}

void Team_Lead::increment_salary()
{
	double new_salary = Employee::get_salary() + (Employee::get_salary() * 0.3);
	Employee::set_salary(new_salary);
}

Quality_Analyst::Quality_Analyst(int id, string firstname, string lastname, char gender, string mob_num, int age)
{
	this->set_designation("Quality Analyst");
	this->set_salary(30000.0);
	this->set_gender(gender);
	this->set_age(age);
	this->set_first_name(firstname);
	this->set_employee_id(id);
	this->set_last_name(lastname);
	this->set_mobile_number(mob_num);
}

void Quality_Analyst::increment_salary()
{
	double new_salary = Employee::get_salary() + (Employee::get_salary() * 0.2);
	Employee::set_salary(new_salary);
}

Developer::Developer(int id, string firstname, string lastname, char gender, string mob_num, int age)
{
	this->set_designation("Developer");
	this->set_salary(40000.0);
	this->set_gender(gender);
	this->set_last_name(lastname);
	this->set_age(age);
	this->set_first_name(firstname);
	this->set_employee_id(id);
	this->set_mobile_number(mob_num);
}

void Developer::increment_salary()
{
	double new_salary = Employee::get_salary() + (Employee::get_salary() * 0.2);
	Employee::set_salary(new_salary);
}


