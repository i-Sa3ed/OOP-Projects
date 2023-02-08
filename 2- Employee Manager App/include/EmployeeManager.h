#pragma once
//#ifndef _EMPLOYEEMANAGER_H
//#define _EMPLOYEEMANAGER_H


#include "Project.h"
#include "Department.h"
#include "staff.h"

#include <iostream>
#include <vector>
using namespace std;

class EmployeeManager
{
	int departCount, projectsCount;
public:
	EmployeeManager();
	vector <Department> departments;
	vector <Project> projects;

	string checkIfFoundDepartment(int id);
	void addDepartment();
	void printAllDeparts();

	void addProject(Staff& paraStaffObj);
	void printAllProjects();

	void addBudget();
	void increaseExistingBudget();

};

//#endif // !_EMPLOYEEMANAGER_H