#pragma once
#include "FileHandling.h"

File_handling* File_handling::instance = nullptr;

File_handling* File_handling::GetInstance(Employee_Operations& object)
{
	if (instance == nullptr)
		instance = new File_handling(object);
	return instance;
}

void File_handling::open_file()
{
	ifstream fs;
	fs.open(FILENAME, ios::in);
	if (!fs.is_open())
	{
		fs.open(FILENAME, ios::in);
	}
	else
	{
		if (fs.peek() == EOF)
		{
			return;
		}
		else
		{
			double salary;
			string input, firstname, lastname, mob_num, designation, data;
			int age;
			unsigned long int emp_id;
			char gender;
			try
			{
				while (getline(fs, data))
				{
					Employee* employee = NULL;
					stringstream lineStream(data);

					getline(lineStream, input, '|');
					stringstream convertor1(input);
					convertor1 >> emp_id;

					getline(lineStream, firstname, '|');

					getline(lineStream, lastname, '|');

					getline(lineStream, input, '|');
					gender = input[0];

					getline(lineStream, input, '|');
					stringstream convertor2(input);
					convertor2 >> age;

					getline(lineStream, mob_num, '|');

					getline(lineStream, input, '|');
					stringstream convertor3(input);
					convertor3 >> salary;

					getline(lineStream, designation, '\n');

					if (designation == "Human Resource")
					{
						EmployeeCreatorFactory* employee = new Create_Human_Resource();
						Employee* emp = employee->generate(emp_id, firstname, lastname, gender, mob_num, age,salary);
						object_.employee_list.insert(pair<int, Employee*>(emp_id, emp));

					}
					else if (designation == "Team Lead")
					{
						EmployeeCreatorFactory* employee = new Create_Team_Lead();
						Employee* emp = employee->generate(emp_id, firstname, lastname, gender, mob_num, age, salary);
						object_.employee_list.insert(pair<int, Employee*>(emp_id, emp));

					}
					else if (designation == "Quality Analyst")
					{
						EmployeeCreatorFactory* employee = new Create_Quality_Analyst();
						Employee* emp = employee->generate(emp_id, firstname, lastname, gender, mob_num, age, salary);
						object_.employee_list.insert(pair<int, Employee*>(emp_id, emp));

					}
					else if (designation == "Developer")
					{
						EmployeeCreatorFactory* employee = new Create_Developer();
						Employee* emp = employee->generate(emp_id, firstname, lastname, gender, mob_num, age, salary);
						object_.employee_list.insert(pair<int, Employee*>(emp_id, emp));
					}
					object_.set_last_emp_id(emp_id + 1);
				}
			}
			catch (const std::exception& exec)
			{
				cout << "Exception occurred!!" << exec.what() << endl;
			}

		}
	}
}

void File_handling::save()
{
	ofstream fs(FILENAME, ios::out);
	if (!fs.is_open())
	{
		fs.open(FILENAME, ios::out);
	}
	try
	{
		for (auto itr = object_.employee_list.begin(); itr != object_.employee_list.end(); ++itr)
		{
			fs << itr->first << "|"
				<< itr->second->get_first_name() << "|"
				<< itr->second->get_last_name() << "|"
				<< itr->second->get_gender() << "|"
				<< itr->second->get_age() << "|"
				<< itr->second->get_mobile_number() << "|"
				<< itr->second->get_salary() << "|"
				<< itr->second->get_designation() << "\n";
		}
	}
	catch (const std::exception& exec)
	{
		cout << "Exception occurred!!" << exec.what() << endl;
	}
}

File_handling::~File_handling()
{
	fs.close();
}