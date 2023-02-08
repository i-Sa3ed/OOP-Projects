#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee
{
	double hoursWorked, rate;
public:
	HourlyEmployee(int _id, string _n, string _ph, string _em, string _depart, string _SSN, double _hours, double _rate);
	void addHours(int moreHours);
	void print();
	double pay();
};

