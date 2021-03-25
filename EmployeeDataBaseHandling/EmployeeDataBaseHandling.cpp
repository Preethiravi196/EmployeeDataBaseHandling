#include <iostream>
#include "FileHandling.h"
#include "Employee.h"
#include "EmployeeOperations.h"

using namespace std;

void prompt_save(File_handling* file)
{
	char ch;
	cout << "\nDo you want to save the changes(Y or N): ";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	{
		file->save();
		cout << "Changes made are saved in the file!!\n";
	}
}


int main()
{
	int option, return_val_1 = 0, return_val_2 = 0, return_val_3 = 0;
	char ch;

	Employee_Operations emp_operations_object;
	File_handling* file = File_handling::GetInstance(emp_operations_object);

	file->open_file();

	cout << "Employee management\n";

	do
	{
		cout << "\nChoose an option:\n1.Add employee\n2.Display all employees record\n3.Delete employee record\n4.Search an employee record\n5.Modify employee detail\n6.Exit\n";
		cout << "Your option: ";
		cin >> option;
		cout << endl;

		switch (option)
		{
		case 1:
		{
			return_val_1 = emp_operations_object.Add_Employee();
			break;
		}
		case 2:
		{
			emp_operations_object.Display_Employee();
			break;
		}
		case 3:
		{
			return_val_2 = emp_operations_object.Delete_Employee();
			break;
		}
		case 4:
		{
			emp_operations_object.Search_Employee();
			break;
		}
		case 5:
		{
			return_val_3 = emp_operations_object.Modify_employee_detail();
			break;
		}
		case 6:
		{
			if (return_val_1 || return_val_2 || return_val_3)
			{
				prompt_save(file);
			}
			return 0;
		}
		default:
		{
			cout << "Enter a valid option!";
			break;
		}
		}
		cout << "\n\nDo you want to continue(Y or N): ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');

	if (return_val_1 || return_val_2 || return_val_3)
	{
		prompt_save(file);
	}

	return 0;
}
