#include "Person.h"
#include <string>

Person::Person(int _id) : Customer(_id)
{
	string address, name;
	cout << "Enter the Billing Address: ";
	cin >> address;
	billing_address = address;

	cout << "Enter the Full Name: ";
	cin.ignore();
	getline(cin, name);
	full_name = name;
}

void Person::print()
{
	Customer::print(); // call the parent function
	cout << "Billing Address: " << billing_address << endl
		<< "Full Name: " << full_name << endl;
}

void Person::update()
{
	Customer::update();

	cout << "Enter the new Billing Address: ";
	string address;
	cin >> address;
	billing_address = address;

	cout << "Enter the new Full Name: ";
	string name;
	cin >> name;
	full_name = name;
}

void Person::writeOnStream(ostream& out)
{
	Customer::writeOnStream(out);
	out << "Billing Address: " << billing_address << '\t' << "Full Name: " << full_name << endl;
}

