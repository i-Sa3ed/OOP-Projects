#include "Employee.h"

Employee::Employee()
{
}

Employee::Employee(int _id, string _n, string _ph, string _em, string _depart, string _SSN) :
	staffMember::staffMember(_id, _n, _ph, _em, _depart, 1) // re-using the parent consturctor
{
	this->socialSecurityNumber = _SSN;
}

void Employee::print()
{
	staffMember::print(); // re-using
	cout << "Social Security Number : " << socialSecurityNumber << endl;
}

double Employee::pay()
{
	return 0.0;
}
