#pragma once
#include "Person.h"
#include "Company.h"
#include <vector>


class Customers
{
	int count;
	vector <Customer*> customerList;
public:
	Customers();
	~Customers();
	void addCustomer();
	void editCustomer();
	void deleteCustomer();
	void printAllCustomers();
	void saveCustomersFile();

	int getCustomersNum();
	Customer* getCustomerPtr(int _id);
};

