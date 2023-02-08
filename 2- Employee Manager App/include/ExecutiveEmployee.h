#pragma once
#include "SalariedEmployee.h"

class ExecutiveEmployee : public SalariedEmployee
{
	double bonus;
public:
	ExecutiveEmployee(int _id, string _n, string _ph, string _em, string _depart, string _SSN, double _salary, double _bonus);
	void addBonus(double moreBonus);
	void print();
	double pay();
};

