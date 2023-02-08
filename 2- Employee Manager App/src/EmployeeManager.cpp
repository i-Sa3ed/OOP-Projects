#include "EmployeeManager.h"

EmployeeManager::EmployeeManager()
{
	departCount = projectsCount = 0;
}

string EmployeeManager::checkIfFoundDepartment(int id)
{
	string result = "0";
	for (Department item : departments) {
		if (item.getID() == id)
		{
			result = item.getName();
			break;
		}

	}

	return result;
}

void EmployeeManager::addDepartment()
{
	string inputDepartName;
	cout << "Enter the department's name : ";
	cin >> inputDepartName;

	departments.push_back(Department(++departCount, inputDepartName));
	cout << "ADDED~\n";
}

void EmployeeManager::printAllDeparts()
{
	cout << "\n @Department List :\n";
	int count = 1;
	for (Department item : departments)
	{
		cout << count++ << "- ";
		item.print();
	}
}

void printAllManagers(Staff paraStaff)
{
	paraStaff.printManagersOnly();
}

void EmployeeManager::addProject(Staff& paraStaffObj)
{
	string inputLoc;
	double inputCurrCost;
	int inputManID;
	cout << "Enter the location of the project : ";
	cin >> inputLoc;
	cout << "Enter the current cost : ";
	cin >> inputCurrCost;
	cout << "Enter the manager's ID : ";
	// refinement : show the Employees list here.
	cin >> inputManID;

	// check if the id is in staffList:
	Employee tempManager;

	if (paraStaffObj.checkIfInStaffList(inputManID, &tempManager))
	{
		projects.push_back(Project(++projectsCount, inputLoc, tempManager, inputCurrCost));
		cout << "ADDED~\n";
	}
	else cout << "INVALID employee ID, please retry again..\n";
}

void EmployeeManager::printAllProjects()
{
	cout << "\t--My Projects--\n";
	for (int i = 0; i < projectsCount; i++)
	{
		cout << i + 1 << "-\n";
		projects[i].print();
		cout << endl;
	}
	cout << "\nFOUND~ : (" << projectsCount << ") Projects" << endl;
}

void EmployeeManager::addBudget()
{
	int inputID;
	cout << "Enter the ID of the project to add : ";
	cin >> inputID;

	bool found = 0;
	for (int i = 0; i < projectsCount; i++)
	{
		if (projects[i].getProjectID() == inputID)
		{
			double inputValue;
			cout << "Enter the value of the budget : ";
			cin >> inputValue;
			projects[i].addBudget(inputValue);
			found = 1;
			break;
		}
	}
	found ? cout << "ADDED~" : cout << "Inexisting ID, please retry again..\n";
}

void EmployeeManager::increaseExistingBudget()
{
	int inputProjectID;
	cout << "Enter project ID : ";
	cin >> inputProjectID;

	// check if exist in projects:
	bool found = 0;
	for (int i = 0; i < projectsCount; i++)
	{
		if (projects[i].getProjectID() == inputProjectID)
		{
			int inputBudgetID;
			cout << "Enter budget ID : ";
			cin >> inputBudgetID;

			projects[i].checkAndIncreaseBudget(inputBudgetID);
			found = 1; 
			break;
		}
	}
	if (!found) cout << "No such project with this ID..\n";
}

