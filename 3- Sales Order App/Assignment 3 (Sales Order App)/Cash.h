#pragma once
#include "Payment.h"

class Cash : public Payment
{
public:
	double cashValue;
	Cash(double _amount);
};

