#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(int _id, string _n, string _ph, string _em, string _depart, string _SSN, double _hours, double _rate) :
	Employee::Employee(_id, _n, _ph, _em, _depart, _SSN)
{
	this->hoursWorked = _hours;
	this->rate = _rate;
}

void HourlyEmployee::addHours(int moreHours)
{
	hoursWorked += moreHours;
}

void HourlyEmployee::print()
{
	Employee::print();
	cout << "Hours worked : " << hoursWorked << " , Rate : " << rate << endl;
}

double HourlyEmployee::pay()
{
	return hoursWorked * rate;
}
