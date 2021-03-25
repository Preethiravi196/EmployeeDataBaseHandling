#include "EmployeeSearchHandler.h"

EmployeeSearchHandler::EmployeeSearchHandler(map<int, Employee*> employee_list_map)
{
	employee_list = employee_list_map;
}

map<int, Employee*> EmployeeSearchHandler::get_resultant_matrix()
{
	return resultant_employee_map;
}

map<int, Employee*> EmployeeSearchHandler::ApplyIntersectionOperation(map<int, Employee*> map1, map<int, Employee*> map2)
{
	resultant_employee_map.clear();
	set_intersection(map1.begin(), map1.end(), map2.begin(), map2.end(), inserter(resultant_employee_map, resultant_employee_map.begin()));

	return resultant_employee_map;
}

map<int, Employee*> EmployeeSearchHandler::ApplyUnionOperation(map<int, Employee*> map1, map<int, Employee*> map2)
{
	resultant_employee_map.clear();
	set_union(map1.begin(), map1.end(), map2.begin(), map2.end(), inserter(resultant_employee_map, resultant_employee_map.begin()));

	return resultant_employee_map;
}

string EmployeeSearchHandler::find_string_using_field(map<int, Employee*>::iterator itr, string field_name)
{
	string main_string;

	if (field_name == "firstname")
	{
		main_string = itr->second->get_first_name();
	}
	else if (field_name == "lastname")
	{
		main_string = itr->second->get_last_name();
	}
	else if (field_name == "mobilenumber")
	{
		main_string = itr->second->get_mobile_number();
	}
	else if (field_name == "designation")
	{
		main_string = itr->second->get_designation();
	}

	transform(main_string.begin(), main_string.end(), main_string.begin(), ::tolower);

	return main_string;
}

double EmployeeSearchHandler::find_double_input_using_field(map<int, Employee*>::iterator itr, string field_name)
{
	double main_double_input = NULL;

	if (field_name == "salary")
	{
		main_double_input = itr->second->get_salary();
	}
	return main_double_input;
}

char EmployeeSearchHandler::find_char_input_using_field(map<int, Employee*>::iterator itr, string field_name)
{
	char main_char_input = NULL;

	if (field_name == "gender")
	{
		main_char_input = itr->second->get_gender();
	}
	return tolower(main_char_input);
}

int EmployeeSearchHandler::find_numeric_input_using_field(map<int, Employee*>::iterator itr, string field_name)
{
	int main_input = 0;

	if (field_name == "employeeid")
	{
		main_input = itr->second->get_emp_id();
	}
	else if (field_name == "age")
	{
		main_input = itr->second->get_age();
	}
	else if (field_name == "salary")
	{
		main_input = itr->second->get_salary();
	}

	return main_input;
}

void EmployeeSearchHandler::SearchOnCharInput(char char_input, string field_name)
{
	char main_character_input;
	resultant_employee_map.clear();

	for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
	{
		main_character_input = find_char_input_using_field(itr, field_name);

		if (main_character_input == char_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
		{
			resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
		}
	}
}

void EmployeeSearchHandler::SearchOnStringInput(string search_string, int type, string field_name)
{
	int position;
	resultant_employee_map.clear();

	if (type == 1)
	{
		string main_string;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_string = find_string_using_field(itr, field_name);
			position = main_string.find(search_string);

			if (position != string::npos && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 2)
	{
		string main_string;
		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_string = find_string_using_field(itr, field_name);

			if (main_string.rfind(search_string, 0) == 0 && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 3)
	{
		string main_string;
		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_string = find_string_using_field(itr, field_name);

			if (main_string.size() >= search_string.size() &&
				main_string.compare(main_string.size() - search_string.size(), search_string.size(), search_string) == 0 && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
}

void EmployeeSearchHandler::SearchOnNumericInput(int search_numeric_input, int type, string field_name)
{
	resultant_employee_map.clear();
	if (type == 1)
	{
		int main_input;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_numeric_input_using_field(itr, field_name);

			if (main_input == search_numeric_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 2)
	{
		int main_input;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_numeric_input_using_field(itr, field_name);

			if (main_input > search_numeric_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 3)
	{
		int main_input;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_numeric_input_using_field(itr, field_name);

			if (main_input < search_numeric_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 4)
	{
		int main_input;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_numeric_input_using_field(itr, field_name);

			if (main_input >= search_numeric_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 5)
	{
		int main_input;
		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_numeric_input_using_field(itr, field_name);

			if (main_input <= search_numeric_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
}

void EmployeeSearchHandler::SearchOnDoubleInput(double search_double_input, int type, string field_name)
{
	resultant_employee_map.clear();
	if (type == 1)
	{
		int main_input;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_double_input_using_field(itr, field_name);

			if (main_input == search_double_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 2)
	{
		int main_input;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_double_input_using_field(itr, field_name);

			if (main_input > search_double_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 3)
	{
		int main_input;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_double_input_using_field(itr, field_name);

			if (main_input < search_double_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 4)
	{
		int main_input;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_double_input_using_field(itr, field_name);

			if (main_input >= search_double_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
	else if (type == 5)
	{
		int main_input;

		for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
		{
			main_input = find_double_input_using_field(itr, field_name);

			if (main_input <= search_double_input && resultant_employee_map.find(itr->first) == resultant_employee_map.end())
			{
				resultant_employee_map.insert(pair<int, Employee*>(itr->first, itr->second));
			}
		}
	}
}

