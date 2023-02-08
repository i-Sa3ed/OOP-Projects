#pragma once
#include "Employee.h"

class CommissionEmployee : public Employee
{
	double target;
public:
	CommissionEmployee(int _id, string _n, string _ph, string _em, string _depart, string _SSN, double _target);
	void print();
	double pay();
};

