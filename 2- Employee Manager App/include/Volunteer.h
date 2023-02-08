#pragma once
#include "staffMember.h"

class Volunteer : public staffMember
{
	double amount;
public:
	Volunteer(int _id, string _n, string _ph, string _em, string _depart, double _amount); // reusability
	void print(); // reusability
	double pay();
};

