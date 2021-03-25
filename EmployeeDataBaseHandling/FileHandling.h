#pragma once
#include "EmployeeOperations.h"
#include <fstream>
#include <sstream>
#define FILENAME "Employee.txt"
using namespace std;

class File_handling
{
private:
	File_handling(Employee_Operations& object) : object_(object)
	{
	}
	static File_handling* instance;
	fstream fs;
	Employee_Operations& object_;

public:

	File_handling(File_handling& other) = delete;
	void operator=(File_handling&) = delete;

	static File_handling* GetInstance(Employee_Operations& object);

	void open_file();

	void save();

	~File_handling();

};

