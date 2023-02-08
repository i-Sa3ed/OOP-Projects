#include "Staff.h"
#include "EmployeeManager.h"

Staff::Staff()
{
	staffCount = 0;
}

Staff::~Staff()
{
	for (auto item : staffList)
		delete item; 
}

double Staff::calcPayroll()
{
	long double payroll = 0;
	for (auto item : staffList)
		payroll += item->pay();
	return payroll;
}

void showTypeOptions()
{
	cout << "\tpress\tfor\n"
		<< "\t  1\tVolunteer\n"
		<< "\t  2\tHourly Employee\n"
		<< "\t  3\tSalaried Employee\n"
		<< "\t  4\tCommission Employee\n";
}

/*
	add common infos first (better)
*/

void Staff::addMember(EmployeeManager& paraEmpManObj)
{
	string inputName, inputPhone, inputEmail;
	cout << "Enter Member's name : ";
	cin >> inputName;
	cout << "Enter Member's phone : ";
	cin >> inputPhone;
	cout << "Enter Member's email : ";
	cin >> inputEmail;

	int inputDepartID;
	string departmentName;

	paraEmpManObj.printAllDeparts();
	cout << endl;

	do
	{
		cout << "Enter the ID of member's department : (must be from your department list :) ";
		cin >> inputDepartID;
	} while (paraEmpManObj.checkIfFoundDepartment(inputDepartID) == "0");
	departmentName = paraEmpManObj.checkIfFoundDepartment(inputDepartID);

	int type;
	cout << "Choose the type of the member : \n";
	showTypeOptions();
	cin >> type;

	switch (type)
	{
	case 1:
	{
		/*
			staffList.push_back(new Volunteer)
			staffList[staffList.size() - 1] -> setVolunteerInfo();
		*/

		double amount;
		cout << "Enter the amount of the Volunteer : ";
		cin >> amount;
		staffList.push_back(new Volunteer(++staffCount, inputName, inputPhone, inputEmail, departmentName, amount));
		cout << "ADDED~\n";
		break;
	}
	case 2:
	{
		string inputSocialNum;
		double inputHours, inputRate;
		cout << "Enter the Social Security Number for the Employee : ";
		cin >> inputSocialNum;
		cout << "Enter the hours that he worked : ";
		cin >> inputHours;
		cout << "Enter the rate of the Employee : ";
		cin >> inputRate;

		staffList.push_back(new HourlyEmployee(++staffCount, inputName, inputPhone, inputEmail, departmentName, inputSocialNum, inputHours, inputRate));
		cout << "ADDED~\n";
		break;
	}
	case 3:
	{
		string inputSocialNum;
		double inputSalary;
		cout << "Enter the Social Security Number for the Employee : ";
		cin >> inputSocialNum;
		cout << "Enter the salary of the Employee $: ";
		cin >> inputSalary;

		char isExecutive;
		double inputBonus;
		cout << "Is it an Executive or not? (y/n)";
		cin >> isExecutive;
		switch (isExecutive)
		{
		case 'y':
			cout << "Enter the Employee's bonus : ";
			cin >> inputBonus;
			staffList.push_back(new ExecutiveEmployee(++staffCount, inputName, inputPhone, inputEmail, departmentName, inputSocialNum, inputSalary, inputBonus));
			cout << "ADDED~\n";
			break;
		case 'n':
			staffList.push_back(new SalariedEmployee(++staffCount, inputName, inputPhone, inputEmail, departmentName, inputSocialNum, inputSalary));
			cout << "ADDED~\n";
			break;
		default:
			cout << "Invalid input.. please retry again~\n";
		}
		break;
	}
	case 4:
	{
		string inputSocialNum;
		double inputTarget;
		cout << "Enter the Social Security Number for the Employee : ";
		cin >> inputSocialNum;
		cout << "Enter the target : ";
		cin >> inputTarget;

		staffList.push_back(new CommissionEmployee(++staffCount, inputName, inputPhone, inputEmail, departmentName, inputSocialNum, inputTarget));
		cout << "ADDED~\n";
		break;
	}
	default: cout << "INVALID INPUT, pleare retry again..\n";
		

	}
}

void Staff::showAll()
{
	cout << "\t\t--Staff Member List--\n";
	cout << "\t\t-------.------.------\n\n";
	for (auto item : staffList)
	{
		item->print();
		cout << "-----------------------\n";
	}
}

void Staff::printManagersOnly()
{
	for (auto item : staffList)
	{
		cout << "- My Managers List: \n";
		if (item->getStatus())
			item->print();
	}
}

void Staff::delMember()
{
	cout << "Your member's list:\n";
	Staff::showAll();
	cout << endl;
	int deletedID;
	cout << "Enter the id for the member to delete : ";
	cin >> deletedID;

	if (!staffList.empty())
	{
		bool found = 0;
		int count = 0;
		for (auto item : staffList)
		{
			if (item->getID() == deletedID)
			{
				staffList.erase(staffList.begin() + count); // take a pointer to what need to be deleted.
				found = 1;
				break;
			}

			count++;
		}

		found ? cout << "DELETED~\n" : cout << "NOT FOUND~\n";
	}
	else cout << "Oops.. you don't have any member in your list@\n";
}

bool Staff::checkIfInStaffList(int id, staffMember* const &emp)
{
	bool found = 0;
	for (auto* item : staffList)
	{
		if (item->getID() == id && item->getStatus())
		{
			found = 1;
			*emp = *item;
			break;
		}
	}

	return found;
}
