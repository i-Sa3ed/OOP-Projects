#include "Credit.h"

Credit::Credit(double _amount) : Payment(_amount)
{
	cout << "Enter the number: ";
	cin >> number;

	date = __DATE__;
	type = "temp_type";
}
