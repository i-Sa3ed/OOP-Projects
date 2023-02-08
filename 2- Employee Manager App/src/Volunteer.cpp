#include "Volunteer.h"

Volunteer::Volunteer(int _id, string _n, string _ph, string _em, string _depart, double _amount) :
	staffMember::staffMember(_id, _n, _ph, _em, _depart, 0) // re-using the parent consturctor
{
	this->amount = _amount;
}

void Volunteer::print()
{
	staffMember::print();
	cout << "Amount : " << amount << endl;
}

double Volunteer::pay()
{
	return 0.0;
}
