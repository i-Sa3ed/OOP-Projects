#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee(int _id, string _n, string _ph, string _em, string _depart, string _SSN, double _target) :
	Employee::Employee(_id, _n, _ph, _em, _depart, _SSN)
{
	this->target = _target;
}

void CommissionEmployee::print()
{
	Employee::print();
	cout << "Target : " << target << endl;
}

double CommissionEmployee::pay()
{
	return 0.05 * target;
}
