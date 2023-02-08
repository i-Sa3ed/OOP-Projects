#pragma once
#include <iostream>
using namespace std;

class Payment
{
	string paidDate;
	double amount;

public:
	Payment(double _amount);
	double pay();
};

