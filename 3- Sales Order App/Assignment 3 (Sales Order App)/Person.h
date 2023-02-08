#pragma once
#include "Customer.h"

class Person : public Customer
{
	string billing_address, full_name;
public:
	Person(int _id);
	void print();
	void update();

	void writeOnStream(ostream& out);
};

