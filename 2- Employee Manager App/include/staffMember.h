#pragma once
#include <iostream>
using namespace std;

class staffMember
{
protected:
	int employeeID;
	string name, phone, email, memDepartment;
	bool isEmp;
public:
	staffMember();
	staffMember(int _id, string _n, string _ph, string _em, string _depart, bool _isEmp);
	virtual void print();
	virtual double pay() = 0;
	int getID() const;
	bool getStatus() const;
};

