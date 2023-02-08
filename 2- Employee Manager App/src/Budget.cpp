#include "Budget.h"
#include <iostream>
using namespace std;

Budget::Budget(int _id, double _value)
{
	this->budgetID = _id;
	this->value = _value;
}

void Budget::increaseBudget(double amount)
{
	this->value += amount;
}

double Budget::getValue() const
{
	return value;
}

int Budget::getBudgetID() const
{
	return this->budgetID;
}

void Budget::printBudget()
{
	cout << "Budget ID : " << budgetID << " , Value : " << value << '\n';
}
