#include "staffMember.h"

staffMember::staffMember()
{
}

staffMember::staffMember(int _id, string _n, string _ph, string _em, string _depart, bool _isEmp = 1)
{
	this->employeeID = _id;
	this->name = _n;
	this->phone = _ph;
	this->email = _em;
	this->memDepartment = _depart;
	this->isEmp = _isEmp;
}

void staffMember::print()
{
	cout << "Employee ID : " << employeeID << " , Name : " << name << " , Department : " << memDepartment << "\nPhone : " << phone << " , Email : " << email << endl;
}

int staffMember::getID() const
{
	return employeeID;
}

bool staffMember::getStatus() const
{
	return isEmp;
}
