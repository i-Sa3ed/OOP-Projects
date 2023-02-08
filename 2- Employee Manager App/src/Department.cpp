#include "Department.h"

Department::Department(int _id, string _name)
{
	departID = _id;
	departName = _name;
}

int Department::getID() const
{
	return departID;
}

string Department::getName() const
{
	return departName;
}

void Department::print()
{
	cout << "department ID : " << departID << " , department name : " << departName << endl;
}
