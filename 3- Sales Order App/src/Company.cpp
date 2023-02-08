#include "Company.h"

Company::Company(int _id) : Customer(_id)
{
	string loc, name;

	cout << "Enter the Location of the Company: ";
	cin >> loc;
	location = loc;

	cout << "Enter the Company Name: ";
	cin >> name;
	company_name = name;
}

void Company::print()
{
	Customer::print();
	cout << "Location: " << location << endl
		<< "Company Name: " << company_name << endl;
}

void Company::update()
{
	Customer::update();

	cout << "Enter the new Location: ";
	string loc;
	cin >> loc;
	location = loc;

	cout << "Enter the new Company Name: ";
	string name;
	cin >> name;
	company_name = name;
}

void Company::writeOnStream(ostream& out)
{
	Customer::writeOnStream(out);
	out << "Location: " << location << '\t' << "Company Name: " << company_name << endl;
}
