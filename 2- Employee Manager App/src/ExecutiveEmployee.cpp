#include "ExecutiveEmployee.h"

ExecutiveEmployee::ExecutiveEmployee(int _id, string _n, string _ph, string _em, string _depart, string _SSN, double _salary, double _bonus) :
	SalariedEmployee::SalariedEmployee(_id, _n, _ph, _em, _depart, _SSN, _salary)
{
	this->bonus = _bonus;
}

void ExecutiveEmployee::addBonus(double moreBonus)
{
	bonus += moreBonus;
}

void ExecutiveEmployee::print()
{
	SalariedEmployee::print();
	cout << "Bonus : " << bonus << endl;
}

double ExecutiveEmployee::pay()
{
	return salary + bonus;
}
