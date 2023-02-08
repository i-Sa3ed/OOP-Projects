#pragma once
class Budget
{
	int budgetID;
	double value;
public:
	Budget(int _id, double _value);
	void increaseBudget(double amount);
	double getValue() const;
	int getBudgetID() const;
	void printBudget();
};

