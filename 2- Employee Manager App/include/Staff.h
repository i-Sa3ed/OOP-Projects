#pragma once
#include "Volunteer.h"
#include "HourlyEmployee.h"
#include "ExecutiveEmployee.h"
#include "CommissionEmployee.h"
#include "Department.h"
#include "Project.h"

#include <vector>

class EmployeeManager;// to implement bidirectional association

class Staff
{
	vector <staffMember*> staffList;
	int staffCount;
public:
	Staff();
	~Staff();
	double calcPayroll();
	void addMember(EmployeeManager& paraEmpManObj);
	void delMember();
	void showAll();
	void printManagersOnly();
	bool checkIfInStaffList(int id, staffMember* const &emp);
};

