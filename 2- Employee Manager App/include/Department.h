#pragma once
#include <iostream>
using namespace std;

class Department
{
	int departID;
	string departName;
public:
	Department(int _id, string _name);
	int getID() const;
	string getName() const;
	void print();
};

