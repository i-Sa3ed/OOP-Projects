#pragma once
#include "Customer.h"

class Company : public Customer
{
	string location, company_name;
public:
	Company(int _id);
	void print();
	void update();

	void writeOnStream(ostream& out);
};

