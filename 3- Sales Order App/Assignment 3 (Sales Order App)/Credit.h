#pragma once
#include "Payment.h"

class Credit : public Payment
{
public: 
	string number, type, date;
	Credit(double _amount);
};

