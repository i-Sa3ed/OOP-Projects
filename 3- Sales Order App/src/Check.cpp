#include "Check.h"

Check::Check(double _amount) : Payment(_amount)
{
	cout << "Enter the name: ";
	cin >> name;

	cout << "Enter the bank ID: ";
	cin >> bankID;
}
