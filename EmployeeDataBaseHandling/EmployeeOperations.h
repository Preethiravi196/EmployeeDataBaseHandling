#pragma once
#include "EmployeeCreatorFactory.h"
#include "EmployeeSearchHandler.h"
#include <map>
#include <iostream>
#include <set>
#include <algorithm>
#include <regex>

using namespace std;

class Employee_Operations
{
private:
	unsigned long int last_emp_id;

public:
	map<int, Employee*> employee_list;

	Employee_Operations()
	{
		last_emp_id = 10080;
	}

	unsigned long int get_last_emp_id();

	void set_last_emp_id(unsigned long int);

	bool isValid_mobile_number(string);

	void Display_Employee();

	int Add_Employee();

	int Delete_Employee();

	int Modify_employee_detail();

	void Search_Employee();

	string get_string_input(string);

	double get_double_input(string);

	char get_char_input(string);

	int get_int_input(string);

	int get_string_operation_type();

	int get_numerical_operation_type();

};

