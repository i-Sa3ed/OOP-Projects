#include "Customer.h"

void Customer::print()
{
	cout << *this; // using the operator that i overloaded below..
}

void Customer::writeOnStream(ostream& out)
{
	out << "ID : " << id << '\t' << "Phone: " << phone << "\t\t";
}

Customer::Customer(int _id)
{
	this->id = _id;
	cin >> *this;
}

Customer::~Customer()
{
}

void Customer::update()
{
	cout << "Enter the new Phone: ";
	string tempPHone;
	cin >> tempPHone;
	phone = tempPHone;
}

void Customer::setID(int _id)
{
	this->id = _id;
}

istream& operator>>(istream& input, Customer& c)
{
	cout << "Enter the Customer's phone: ";
	input >> c.phone;
	return input;
	// // O: insert return statement here
}

ostream& operator<<(ostream& output, Customer& c)
{
	c.writeOnStream(output);
	return output;
	// // O: insert return statement here
}
