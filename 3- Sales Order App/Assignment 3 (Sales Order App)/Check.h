#pragma once
#include "Payment.h"

class Check : public Payment
{
public: 
	string name, bankID;
	Check(double _amount);
};

