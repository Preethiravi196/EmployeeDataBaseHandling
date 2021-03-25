#pragma once
#include "Employee.h"
#include <map>
#include <iterator>
#include <algorithm>

class EmployeeSearchHandler
{
private:
	map<int, Employee*> employee_list;
	map<int, Employee*> resultant_employee_map;

public:
	EmployeeSearchHandler(map<int, Employee*> employee_list_map);

	map<int, Employee*> get_resultant_matrix();

	map<int, Employee*> ApplyIntersectionOperation(map<int, Employee*>, map<int, Employee*>);

	map<int, Employee*> ApplyUnionOperation(map<int, Employee*>, map<int, Employee*>);

	int find_numeric_input_using_field(map<int, Employee*>::iterator, string);

	string find_string_using_field(map<int, Employee*>::iterator, string);

	double find_double_input_using_field(map<int, Employee*>::iterator, string);

	char find_char_input_using_field(map<int, Employee*>::iterator, string);

	void SearchOnStringInput(string, int, string);

	void SearchOnNumericInput(int, int, string);

	void SearchOnDoubleInput(double, int, string);

	void SearchOnCharInput(char, string);

};