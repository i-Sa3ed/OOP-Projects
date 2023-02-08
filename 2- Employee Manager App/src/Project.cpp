#include "Project.h"

Project::Project(int _id, string _loc, Employee& _man, double _currCost)
{
	budgetCount = 0;
	this->projectID = _id;
	this->location = _loc;
	this->manager = _man;
	this->currentCost = _currCost;
}

void Project::addBudget(double value)
{
	Budget tempBudget(++budgetCount, value);
	budgetList.push_back(tempBudget);
}

void Project::checkAndIncreaseBudget(int id)
{
	bool found = 0;
	for (auto& item : budgetList)
	{
		if (item.getBudgetID() == id)
		{
			double inputMoreValue;
			cout << "Enter the value to increase the budget $: ";
			cin >> inputMoreValue;

			item.increaseBudget(inputMoreValue);
			found = 1;
			break;
		}
	}

	found ? cout << "Increased~\n" : cout << "No matching budget ID, please retry again..\n";
}

int Project::getProjectID() const
{
	return projectID;
}

double Project::getTotalBudget() const
{
	long double totalBudget = 0;
	for (auto item : budgetList)
		totalBudget += item.getValue();

	return totalBudget;
}

void Project::print()
{
	cout << "Project ID : " << projectID << " , Location : " << location << endl;
	cout << "- Manager : \n";
	manager.print();
	cout << "- Budget List : \n";
	for (int i = 1; i <= budgetCount; i++)
	{
		cout << i << "- ";
		budgetList[i - 1].printBudget();
	}

	cout << "Total Budget : " << getTotalBudget() << endl;
}
