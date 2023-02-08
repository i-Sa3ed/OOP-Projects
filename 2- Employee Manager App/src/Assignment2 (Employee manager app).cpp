// Assignment2 (Employee manager app).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "EmployeeManager.h"
#include "Staff.h"

EmployeeManager EmpObj;
Staff StaffObj;

#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void header()
{
	cout << "\n\t\t   $Employee Manager App$\n";
	cout << "\t\t-----------------------------\n";
}

void generalOptions()
{
	cout << "\tPress ... To deal with\n"
		<< "  \t 1 -----> Departments\n"
		<< "  \t 2 -----> Staff\n"
		<< "  \t 3 -----> Projects\n";
}

void departOptions()
{
	cout << "\tPress ........ To\n"
		<< "\t   1 -----> Add New Department\n"
		<< "\t   2 -----> Print All Departments\n";
}

void staffOptions()
{
	cout << "\tPress ........ To\n"
		<< "\t   1 -----> Add New Member\n"
		<< "\t   2 -----> Print All Members\n"
		<< "\t   3 -----> Calculate the Payroll\n"
		<< "\t   4 -----> Delete a Member\n";
}

void projectOptions()
{
	cout << "\tPress ........ To\n"
		<< "\t   1 -----> Add New Project\n"
		<< "\t   2 -----> Print All Projects\n"
		<< "\t   3 -----> Add Budget to a Project\n"
		<< "\t   4 -----> Increase Budget for a Project\n";

}

int main()
{
	// coloring the screen;
	system("Color 06");
	while (1)
	{
		system("cls");
		header();
		generalOptions();
		
		int choice;
		cin >> choice;
		int innerChoice;
		switch (choice)
		{
		case 1:
			departOptions();
			cin >> innerChoice;
			if (innerChoice == 1) EmpObj.addDepartment();
			else if (innerChoice == 2) EmpObj.printAllDeparts();
			else cout << "INVALID INPUT, please retry again..\n";
			break;
		case 2:
			staffOptions();
			cin >> innerChoice;
			switch (innerChoice)
			{
			case 1: StaffObj.addMember(EmpObj); break;
			case 2: StaffObj.showAll(); break;
			case 3: cout << "Your total Payroll is : " << StaffObj.calcPayroll() << endl; break;
			case 4: StaffObj.delMember(); break;
			default: cout << "INVALID INPUT, please retry again..\n";
			}
			break;
		case 3: 
			projectOptions();
			cin >> innerChoice;
			switch (innerChoice)
			{
			case 1: EmpObj.addProject(StaffObj); break;
			case 2: EmpObj.printAllProjects(); break;
			case 3: EmpObj.addBudget(); break;
			case 4: EmpObj.increaseExistingBudget(); break;
			default: cout << "INVALID INPUT, please retry again..\n";
			}
			break;
		default: cout << "INVALID INPUT, please retry again..\n";
		}

		cout << "\nPress Enter to return home page..\n";
		while (!_kbhit()) Sleep(1);
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
