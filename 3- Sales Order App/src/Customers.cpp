#include "Customers.h"
#include <fstream>

Customers::Customers()
{
	count = 0;
}

Customers::~Customers()
{
	for (auto& item : customerList)
		delete item;
}

void Customers::addCustomer()
{
	cout << "\tChoose the type of the Customer: \n"
		<< "\t1- person\n\t2- company\n";
	int type;
	cin >> type;
	switch (type)
	{
	case 1:
		customerList.push_back(new Person(count++));
		cout << "ADDED~\n";
		break;
	case 2:
		customerList.push_back(new Company(count++));
		cout << "ADDED~\n";
		break;
	default:
		cout << "Invalid Choise..\n";
	}
}

void Customers::editCustomer()
{
	printAllCustomers();
	cout << "\nEnter the ID of the Customer to Edit: ";
	int editID;
	cin >> editID;
	
	if (editID < count && editID >= 0) // valid
	{
		customerList[editID]->update();
		cout << "UPDATED~\n";
	}
	else cout << "Invalid ID..\n";
}

void Customers::deleteCustomer()
{
	printAllCustomers();

	cout << "Enter the ID of the Customer to Delete: ";
	int deleteID;
	cin >> deleteID;

	if (deleteID < count && deleteID >= 0) //valid
	{
		customerList[count - 1]->setID(deleteID); // to keep the IDs ordered and equal to the idx
		swap(customerList[deleteID], customerList[--count]);
		customerList.erase(customerList.end() - 1);
		cout << "DELETED~\n";
	}
	else cout << "Invalid ID..\n";
}

void Customers::printAllCustomers()
{
	cout << "\t**Your Customer List**\n"
		<< "\t---------------------\n";
	for (auto& item : customerList)
	{
		item->print();
		cout << "\t---------------------\n";
	}
}

void Customers::saveCustomersFile()
{
	ofstream fout("Customers.txt");
	if (customerList.empty())
	{
		fout << "Sorry.. you don't have any customer\n";
		return;
	}

	int i, SIZE = customerList.size();

	fout << "\tYour Customer List\n\n";
	for (i = 0; i < SIZE; i++)
	{
		fout << (i + 1) << "- " << *customerList[i];
	}

	fout.close();
}

int Customers::getCustomersNum()
{
	return this->count;
}

Customer* Customers::getCustomerPtr(int _id)
{
	return  customerList[_id];
}
