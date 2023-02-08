#pragma once
#include "Employee.h"

class SalariedEmployee : public Employee
{
protected:
	double salary;
public:
	SalariedEmployee(int _id, string _n, string _ph, string _em, string _depart, string _SSN, double _salary);
	void print();
	double pay();
};

