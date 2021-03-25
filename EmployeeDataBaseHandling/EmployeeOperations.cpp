#pragma once
#include "EmployeeOperations.h"

unsigned long int Employee_Operations::get_last_emp_id()
{
	return last_emp_id;
}

void Employee_Operations::set_last_emp_id(unsigned long int last_employee_id)
{
	last_emp_id = last_employee_id;
}

int Employee_Operations::Add_Employee()
{
	string firstname, lastname, mob_num;
	int age, option, return_val = 0;
	double salary;
	char gender;

	cout << "Enter the first name: ";
	cin >> firstname;

	cout << "Enter the last name: ";
	cin >> lastname;

	cout << "Enter Gender:\n1.Male(M)\n2.Female(F)\n3.Other(O)\nYour option: ";
	cin >> gender;

	while (gender != 'M' && gender != 'F' && gender != 'O')
	{
		cout << "Invalid! Enter M or F or O: ";
		cin >> gender;
	}

	cout << "Enter the age: ";
	cin >> age;

	cout << "Enter mobile number: ";
	cin >> mob_num;

	while (!(isValid_mobile_number(mob_num)))
	{
		cout << "Invalid! Enter a valid mobile number: ";
		cin >> mob_num;
	}
	cout << "Enter the designation options:\n1.Team Leader(TL)\n2.Human Resource(HR)\n3.Developer\n4.Quality Analyst(QA)\nYour Option: ";
	cin >> option;

	switch (option)
	{
	case 1:
	{
		EmployeeCreatorFactory* employee = new Create_Team_Lead();
		Employee* emp = employee->generate(last_emp_id, firstname, lastname, gender, mob_num, age,100000.0);
		employee_list.insert(pair<int, Employee*>(last_emp_id++, emp));
		return_val = 1;
		break;
	}
	case 2:
	{
		EmployeeCreatorFactory* employee = new Create_Human_Resource();
		Employee* emp = employee->generate(last_emp_id, firstname, lastname, gender, mob_num, age,50000.0);
		employee_list.insert(pair<int, Employee*>(last_emp_id++, emp));
		return_val = 1;
		break;
	}
	case 3:
	{
		EmployeeCreatorFactory* employee = new Create_Developer();
		Employee* emp = employee->generate(last_emp_id, firstname, lastname, gender, mob_num, age,40000.0);
		employee_list.insert(pair<int, Employee*>(last_emp_id++, emp));
		return_val = 1;
		break;
	}
	case 4:
	{
		EmployeeCreatorFactory* employee = new Create_Quality_Analyst();
		Employee* emp = employee->generate(last_emp_id, firstname, lastname, gender, mob_num, age,30000.0);
		employee_list.insert(pair<int, Employee*>(last_emp_id++, emp));
		return_val = 1;
		break;
	}
	default:
	{
		cout << "Invalid option!!\n";
		if (!return_val)
			return_val = 0;
		break;
	}
	}
	return return_val;
}

bool Employee_Operations::isValid_mobile_number(string mob_num)
{
	const regex pattern("(0/91)?[7-9][0-9]{9}");
	if (regex_match(mob_num, pattern))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Employee_Operations::Display_Employee()
{
	if (employee_list.begin() == employee_list.end())
	{
		cout << "No record found in the file!!\n";
		return;
	}

	cout << "Emp Id|First name|Last name|Gender|Age|Mobile number|Salary|Designation\n\n";

	for (auto itr = employee_list.begin(); itr != employee_list.end(); ++itr)
	{
		cout << itr->first << " | " << itr->second->get_first_name() << " | " << itr->second->get_last_name() << " | " << itr->second->get_gender() << " | " << itr->second->get_age() << " | " << itr->second->get_mobile_number() << " | " << itr->second->get_salary() << " | " << itr->second->get_designation() << endl;
	}
}

int Employee_Operations::Delete_Employee()
{
	int emp_id, return_val = 1;
	cout << "Enter the id of the employee whose data need to be deleted: ";
	cin >> emp_id;

	map<int, Employee*>::iterator itr;
	itr = employee_list.find(emp_id);

	if (itr != employee_list.end())
	{
		employee_list.erase(emp_id);
		cout << "Record successfully deleted!!";
		return_val = 1;
	}
	else
	{
		cout << "No record found with employee id: " << emp_id;
		if (!return_val)
			return_val = 0;
	}
	return return_val;
}

int Employee_Operations::Modify_employee_detail()
{
	int emp_id, option, integer_input, return_val = 0, des_op;
	char ch, gender;
	string string_input, designation;

	cout << "Enter the employee id to modify the data: ";
	cin >> emp_id;

	map<int, Employee*>::iterator itr;
	itr = employee_list.find(emp_id);

	if (itr != employee_list.end())
	{
		cout << "\nEmp Id|First name|Last name|Gender|Age|Mobile number|Salary|Designation\n\n";

		cout << itr->first << " | " << itr->second->get_first_name() << " | " << itr->second->get_last_name() << " | " << itr->second->get_gender() << " | " << itr->second->get_age() << " | " << itr->second->get_mobile_number() << " | " << itr->second->get_salary() << " | " << itr->second->get_designation() << endl << endl;

		do
		{
			cout << "Choose the field to modify:\n1.First name\n2.Last name\n3.gender\n4.age\n5.Mobile number\n6.Designation\n7.Increment Salary\nYour Option: ";
			cin >> option;

			switch (option)
			{
			case 1:
			{
				cout << "Enter the new first name to modify: ";
				cin >> string_input;
				itr->second->set_first_name(string_input);
				return_val = 1;
				break;
			}
			case 2:
			{
				cout << "Enter the new last name to modify: ";
				cin >> string_input;
				itr->second->set_last_name(string_input);
				return_val = 1;
				break;
			}
			case 3:
			{
				cout << "Enter the new gender to modify: ";
				cin >> gender;
				itr->second->set_gender(gender);
				return_val = 1;
				break;
			}
			case 4:
			{
				cout << "Enter the new age to modify: ";
				cin >> integer_input;
				itr->second->set_age(integer_input);
				return_val = 1;
				break;
			}
			case 5:
			{
				cout << "Enter the new mobile number to modify: ";
				cin >> string_input;
				itr->second->set_mobile_number(string_input);
				return_val = 1;
				break;
			}
			case 6:
			{
				cout << "Enter the new designation to modify:\n1.Team Leader(TL)\n2.Human Resource(HR)\n3.Developer\n4.Quality Analyst(QA)\nYour option: ";
				cin >> des_op;

				switch (des_op)
				{
				case 1:
				{
					itr->second->set_designation("Team Lead");
					itr->second->set_salary(100000.0);
					return_val = 1;
					break;
				}
				case 2:
				{
					itr->second->set_designation("Human Resource");
					itr->second->set_salary(50000.0);
					return_val = 1;
					break;
				}
				case 3:
				{
					itr->second->set_designation("Developer");
					itr->second->set_salary(40000.0);
					return_val = 1;
					break;
				}
				case 4:
				{
					itr->second->set_designation("Quality Analyst");
					itr->second->set_salary(30000.0);
					return_val = 1;
					break;
				}
				default:
				{
					cout << "Invalid option!!\n";
					if (!return_val)
						return_val = 0;
					break;
				}
				}
				break;
			}
			case 7:
			{
				itr->second->increment_salary();
				return_val = 1;
				break;
			}

			default:
			{
				cout << "Invalid option!!\n";
				if (!return_val)
					return_val = 0;
				break;
			}
			}
			cout << "Do you want to continue modifying data(Y or N): ";
			cin >> ch;
		} while (ch == 'Y' || ch == 'y');
	}
	else
	{
		cout << "No record found with employee id: " << emp_id;
		if (!return_val)
			return_val = 0;
	}
	return return_val;
}

void Employee_Operations::Search_Employee()
{
	EmployeeSearchHandler SearchHandlerObject(employee_list);

	map<int, Employee*> resultant_search_map_1, resultant_search_map_2;

	int option, type, operation;

	string search_string;

	char ch = 'N';

	do
	{
		if (ch == 'Y' || ch == 'y')
		{
			cout << "\nChoose the operation for search query:\n1.Or\n2.And\nYour option: ";
			cin >> operation;
		}
		cout << "Choose a field for searching the record:\n1.Employee Id\n2.Firstname\n3.Lastname\n4.gender\n5.age\n6.Mobile number\n7.Designation\n8.Salary\nYour Option: ";
		cin >> option;

		cout << endl;

		if (option == 4)
		{
			char gender = get_char_input("Gender");
			SearchHandlerObject.SearchOnCharInput(gender, "gender");
		}
		else if (option == 2 || option == 3 || option == 6 || option == 7)
		{
			int operation_type = 1;

			if (option == 2)
			{
				operation_type = get_string_operation_type();
				string firstname = get_string_input("First Name");
				SearchHandlerObject.SearchOnStringInput(firstname, operation_type, "firstname");
			}
			else if (option == 3)
			{
				operation_type = get_string_operation_type();
				string lastname = get_string_input("Last Name");
				SearchHandlerObject.SearchOnStringInput(lastname, operation_type, "lastname");
			}
			else if (option == 6)
			{
				operation_type = get_string_operation_type();
				string mobile_number = get_string_input("Mobile Number");
				SearchHandlerObject.SearchOnStringInput(mobile_number, operation_type, "mobilenumber");
			}
			else if (option == 7)
			{
				operation_type = get_string_operation_type();
				string designation = get_string_input("Designation");
				SearchHandlerObject.SearchOnStringInput(designation, operation_type, "designation");
			}
		}
		else if (option == 1 || option == 5 || option == 8)
		{
			int operation_type = 1;

			if (option == 1)
			{
				operation_type = get_numerical_operation_type();
				int emp_id = get_int_input("Employee Id");
				SearchHandlerObject.SearchOnNumericInput(emp_id, operation_type, "employeeid");
			}
			else if (option == 5)
			{
				operation_type = get_numerical_operation_type();
				int age = get_int_input("Age");
				SearchHandlerObject.SearchOnNumericInput(age, operation_type, "age");
			}
			else if (option == 8)
			{
				operation_type = get_numerical_operation_type();
				double salary = get_double_input("Salary");
				SearchHandlerObject.SearchOnNumericInput(salary, operation_type, "salary");
			}
		}
		else
		{
			cout << "Invalid option!!\n";
		}

		resultant_search_map_1 = SearchHandlerObject.get_resultant_matrix();

		if (ch == 'Y' || ch == 'y')
		{
			if (operation == 1)
			{
				resultant_search_map_2 = SearchHandlerObject.ApplyUnionOperation(resultant_search_map_1, resultant_search_map_2);
			}
			else
			{
				resultant_search_map_2 = SearchHandlerObject.ApplyIntersectionOperation(resultant_search_map_1, resultant_search_map_2);
			}
		}
		else
		{
			resultant_search_map_2 = resultant_search_map_1;
			resultant_search_map_1.clear();
		}

		cout << "\nDo you want to continue the search with any other field? Y or N : ";
		cin >> ch;


	} while (ch == 'Y' || ch == 'y');

	if (resultant_search_map_2.begin() != resultant_search_map_2.end())
	{
		cout << "\nEmp Id|First name|Last name|Gender|Age|Mobile number|Salary|Designation\n\n";

		for (auto itr = resultant_search_map_2.begin(); itr != resultant_search_map_2.end(); itr++)
		{
			cout << itr->first << " | " << itr->second->get_first_name() << " | " << itr->second->get_last_name() << " | " << itr->second->get_gender() << " | " << itr->second->get_age() << " | " << itr->second->get_mobile_number() << " | " << itr->second->get_salary() << " | " << itr->second->get_designation() << endl;

		}
	}
	else
	{
		cout << "\nNo data found based on the query!!\n";
	}
}

string Employee_Operations::get_string_input(string key_name)
{
	string input_str = "";
	cout << "Enter input for " << key_name << ": ";
	cin.ignore();
	getline(cin, input_str);

	transform(input_str.begin(), input_str.end(), input_str.begin(), ::tolower);

	return string(input_str);
}

double Employee_Operations::get_double_input(string key_name)
{
	double input_double = 0.0;
	cout << "Enter input for " << key_name << ": ";
	cin >> input_double;

	return input_double;
}

char Employee_Operations::get_char_input(string key_name)
{
	char input_char = NULL;
	cout << "Enter input for " << key_name << ": ";
	cin >> input_char;

	return tolower(input_char);
}

int Employee_Operations::get_int_input(string key_name)
{
	int input_int = 0;
	cout << "Enter input for " << key_name << ": ";
	cin >> input_int;

	return input_int;
}

int Employee_Operations::get_string_operation_type()
{
	int operation_type = 1, return_value;
	cout << "Choose the operation type:\n1.Contains\n2.Starts with\n3.Ends with\nYour option: ";
	cin >> operation_type;

	return_value = (operation_type <= 3 && operation_type >= 1) ? operation_type : 1;

	return return_value;
}

int Employee_Operations::get_numerical_operation_type()
{
	int operation_type = 1, return_value;
	cout << "Choose the operation type:\n1.Equal to\n2.Greater than\n3.Less than \n4.Greater than or equal to\n5.Less than or equal to\nYour option: ";
	cin >> operation_type;

	return_value = (operation_type <= 5 && operation_type >= 1) ? operation_type : 1;

	return return_value;
}


