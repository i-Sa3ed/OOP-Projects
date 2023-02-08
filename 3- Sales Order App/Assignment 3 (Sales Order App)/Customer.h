#pragma once
#include <iostream>
using namespace std;

class Customer
{
	int id;
	string phone;
public:
	Customer(int _id);
	virtual ~Customer();
	void setID(int _id);

	virtual void update();
	virtual void print();
	virtual void writeOnStream(ostream& out);

	friend istream& operator>> (istream& input, Customer& c);
	friend ostream& operator<< (ostream& output, Customer& c);
};

