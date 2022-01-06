#pragma once
#ifndef EmployeeManager_H
#define EmployeeManager_H

#include"Data.h"
#include<iomanip>
#include<conio.h>
#include<fstream>


/*******************EMPLOYEE MANAGER CLASS**********************/

class EmployeeManager :public Data
{
private:
	int employee_id;
	string designation;
	int salary;
public:
	void outputline();
	void OUTPUT();
	bool check(int);
	void employeeadd();
	void employeedisplay();
	void employeedelete();
	void employeemanager_choice();
};
#endif