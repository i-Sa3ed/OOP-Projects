#pragma once
#include "staffMember.h"
#include <iostream>
using namespace std;

class Employee : public staffMember
{
protected:
	string socialSecurityNumber;
public:
	Employee();
	Employee(int _id, string _n, string _ph, string _em, string _depart, string _SSN);
	void print();
	double pay();
};

