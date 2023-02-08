#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(int _id, string _n, string _ph, string _em, string _depart, string _SSN, double _salary) :
	Employee::Employee(_id, _n, _ph, _em, _depart, _SSN)
{
	this->salary = _salary;
}

void SalariedEmployee::print()
{
	Employee::print();
	cout << "Salary : " << salary << endl;
}

double SalariedEmployee::pay()
{
	return salary;
}
