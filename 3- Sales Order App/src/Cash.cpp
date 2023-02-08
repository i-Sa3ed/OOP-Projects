#include "Cash.h"

Cash::Cash(double _amount) : Payment(_amount)
{
	cout << "Enter the cash value: ";
	cin >> cashValue;
}
