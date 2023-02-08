#pragma once
#include "Budget.h"
#include "Employee.h"
#include <iostream>
#include <vector>
using namespace std;

class Project
{
	int projectID;
	string location;
	Employee manager;
	double currentCost;
	vector <Budget> budgetList;
	int budgetCount; // start with 1

public:
	Project(int _id, string _loc, Employee& _man, double _currCost);
	void addBudget(double value);
	void checkAndIncreaseBudget(int id);
	int getProjectID() const;
	double getTotalBudget() const;
	void print();
};

